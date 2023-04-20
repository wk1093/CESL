from pcpp.preprocessor import Preprocessor, FileInclusionTime, clock
from pcpp.parser import *
import tempfile
import re
import os
import sys
from pcpp.parser import trigraph, Macro, Action, OutputDirective, PreprocessorHooks

# example: https://github.com/ned14/pcpp/blob/master/pcpp/pcmd.py


class MacroExpander(Preprocessor):  # preprocess the file, but ignore #include
    def __init__(self, *args, **kwargs):
        super(MacroExpander, self).__init__()

    def parsegen(self, input, source=None, abssource=None):
        rewritten_source = source
        if abssource:
            rewritten_source = abssource
            for rewrite in self.rewrite_paths:
                temp = re.sub(rewrite[0], rewrite[1], rewritten_source)
                if temp != abssource:
                    rewritten_source = temp
                    if os.sep != '/':
                        rewritten_source = rewritten_source.replace(
                            os.sep, '/')
                    break

        # Replace trigraph sequences
        t = trigraph(input)
        lines = self.group_lines(t, rewritten_source)

        if not source:
            source = ""
        if not rewritten_source:
            rewritten_source = ""

        my_include_times_idx = len(self.include_times)
        self.include_times.append(FileInclusionTime(
            self.macros['__FILE__'] if '__FILE__' in self.macros else None, source, abssource, self.include_depth))
        self.include_depth += 1
        my_include_time_begin = clock()
        if self.expand_filemacro:
            self.define("__FILE__ \"%s\"" % rewritten_source)

        self.source = abssource
        chunk = []
        enable = True
        iftrigger = False
        ifpassthru = False

        class ifstackentry(object):
            def __init__(self, enable, iftrigger, ifpassthru, startlinetoks):
                self.enable = enable
                self.iftrigger = iftrigger
                self.ifpassthru = ifpassthru
                self.rewritten = False
                self.startlinetoks = startlinetoks
        ifstack = []
        # True until any non-whitespace output or anything with effects happens.
        at_front_of_file = True
        # True if auto pragma once still a possibility for this #include
        auto_pragma_once_possible = self.auto_pragma_once_enabled
        # =(MACRO, 0) means #ifndef MACRO or #if !defined(MACRO) seen, =(MACRO,1) means #define MACRO seen
        include_guard = None
        self.on_potential_include_guard(None)

        for x in lines:
            all_whitespace = True
            skip_auto_pragma_once_possible_check = False
            # Handle comments
            for i, tok in enumerate(x):
                if tok.type in self.t_COMMENT:
                    if not self.on_comment(tok):
                        if tok.type == self.t_COMMENT1:
                            tok.value = ' '
                        elif tok.type == self.t_COMMENT2:
                            tok.value = '\n'
                        tok.type = 'CPP_WS'
            # Skip over whitespace
            for i, tok in enumerate(x):
                if tok.type not in self.t_WS and tok.type not in self.t_COMMENT:
                    all_whitespace = False
                    break
            output_and_expand_line = True
            output_unexpanded_line = False
            if tok.value == '#':
                precedingtoks = [tok]
                output_and_expand_line = False
                try:
                    # Preprocessor directive
                    i += 1
                    while i < len(x) and x[i].type in self.t_WS:
                        precedingtoks.append(x[i])
                        i += 1
                    dirtokens = self.tokenstrip(x[i:])
                    if dirtokens:
                        name = dirtokens[0].value
                        args = self.tokenstrip(dirtokens[1:])

                        if self.debugout is not None:
                            print("%d:%d:%d %s:%d #%s %s" % (enable, iftrigger, ifpassthru, dirtokens[0].source, dirtokens[0].lineno, dirtokens[0].value, "".join(
                                [tok.value for tok in args])), file=self.debugout)
                            # print(ifstack)

                        handling = self.on_directive_handle(
                            dirtokens[0], args, ifpassthru, precedingtoks)
                        assert handling == True or handling == None
                    else:
                        name = ""
                        args = []
                        raise OutputDirective(Action.IgnoreAndRemove)

                    if name == 'define':
                        at_front_of_file = False
                        if enable:
                            for tok in self.expand_macros(chunk):
                                yield tok
                            chunk = []
                            if include_guard and include_guard[1] == 0:
                                if include_guard[0] == args[0].value and len(args) == 1:
                                    include_guard = (args[0].value, 1)
                                    # If ifpassthru is only turned on due to this include guard, turn it off
                                    if ifpassthru and not ifstack[-1].ifpassthru:
                                        ifpassthru = False
                            self.define(args)
                            if self.debugout is not None:
                                print("%d:%d:%d %s:%d      %s" % (enable, iftrigger, ifpassthru, dirtokens[0].source, dirtokens[0].lineno, repr(
                                    self.macros[args[0].value])), file=self.debugout)
                            if handling is None:
                                for tok in x:
                                    yield tok
                    elif name == 'include':
                        for tok in x:
                            yield tok

                        if enable and False:  # disable includes
                            for tok in self.expand_macros(chunk):
                                yield tok
                            chunk = []
                            oldfile = self.macros['__FILE__'] if '__FILE__' in self.macros else None
                            if args and args[0].value != '<' and args[0].type != self.t_STRING:
                                args = self.tokenstrip(
                                    self.expand_macros(args))
                            # print('***', ''.join([x.value for x in args]), file = sys.stderr)
                            for tok in self.include(args, x):
                                yield tok
                            if oldfile is not None:
                                self.macros['__FILE__'] = oldfile
                            self.source = abssource
                    elif name == 'undef':
                        at_front_of_file = False
                        if enable:
                            for tok in self.expand_macros(chunk):
                                yield tok
                            chunk = []
                            self.undef(args)
                            if handling is None:
                                for tok in x:
                                    yield tok
                    elif name == 'ifdef':
                        at_front_of_file = False
                        ifstack.append(ifstackentry(
                            enable, iftrigger, ifpassthru, x))
                        if enable:
                            ifpassthru = False
                            if not args[0].value in self.macros:
                                res = self.on_unknown_macro_in_defined_expr(
                                    args[0])
                                if res is None:
                                    ifpassthru = True
                                    ifstack[-1].rewritten = True
                                    raise OutputDirective(
                                        Action.IgnoreAndPassThrough)
                                elif res is True:
                                    iftrigger = True
                                else:
                                    enable = False
                                    iftrigger = False
                            else:
                                iftrigger = True
                    elif name == 'ifndef':
                        if not ifstack and at_front_of_file:
                            self.on_potential_include_guard(args[0].value)
                            include_guard = (args[0].value, 0)
                        at_front_of_file = False
                        ifstack.append(ifstackentry(
                            enable, iftrigger, ifpassthru, x))
                        if enable:
                            ifpassthru = False
                            if args[0].value in self.macros:
                                enable = False
                                iftrigger = False
                            else:
                                res = self.on_unknown_macro_in_defined_expr(
                                    args[0])
                                if res is None:
                                    ifpassthru = True
                                    ifstack[-1].rewritten = True
                                    raise OutputDirective(
                                        Action.IgnoreAndPassThrough)
                                elif res is True:
                                    enable = False
                                    iftrigger = False
                                else:
                                    iftrigger = True
                    elif name == 'if':
                        if not ifstack and at_front_of_file:
                            if args[0].value == '!' and args[1].value == 'defined':
                                n = 2
                                if args[n].value == '(':
                                    n += 1
                                self.on_potential_include_guard(args[n].value)
                                include_guard = (args[n].value, 0)
                        at_front_of_file = False
                        ifstack.append(ifstackentry(
                            enable, iftrigger, ifpassthru, x))
                        if enable:
                            iftrigger = False
                            ifpassthru = False
                            result, rewritten = self.evalexpr(args)
                            if rewritten is not None:
                                x = x[:i+2] + rewritten + [x[-1]]
                                x[i+1] = copy.copy(x[i+1])
                                x[i+1].type = self.t_SPACE
                                x[i+1].value = ' '
                                ifpassthru = True
                                ifstack[-1].rewritten = True
                                raise OutputDirective(
                                    Action.IgnoreAndPassThrough)
                            if not result:
                                enable = False
                            else:
                                iftrigger = True
                    elif name == 'elif':
                        at_front_of_file = False
                        if ifstack:
                            # We only pay attention if outer "if" allows this
                            if ifstack[-1].enable:
                                if enable and not ifpassthru:         # If already true, we flip enable False
                                    enable = False
                                elif not iftrigger:   # If False, but not triggered yet, we'll check expression
                                    result, rewritten = self.evalexpr(args)
                                    if rewritten is not None:
                                        enable = True
                                        if not ifpassthru:
                                            # This is a passthru #elif after a False #if, so convert to an #if
                                            x[i].value = 'if'
                                        x = x[:i+2] + rewritten + [x[-1]]
                                        x[i+1] = copy.copy(x[i+1])
                                        x[i+1].type = self.t_SPACE
                                        x[i+1].value = ' '
                                        ifpassthru = True
                                        ifstack[-1].rewritten = True
                                        raise OutputDirective(
                                            Action.IgnoreAndPassThrough)
                                    if ifpassthru:
                                        # If this elif can only ever be true, simulate that
                                        if result:
                                            newtok = copy.copy(x[i+3])
                                            newtok.type = self.t_INTEGER
                                            newtok.value = self.t_INTEGER_TYPE(
                                                result)
                                            x = x[:i+2] + [newtok] + [x[-1]]
                                            raise OutputDirective(
                                                Action.IgnoreAndPassThrough)
                                        # Otherwise elide
                                        enable = False
                                    elif result:
                                        enable = True
                                        iftrigger = True
                        else:
                            self.on_error(
                                dirtokens[0].source, dirtokens[0].lineno, "Misplaced #elif")

                    elif name == 'else':
                        at_front_of_file = False
                        if ifstack:
                            if ifstack[-1].enable:
                                if ifpassthru:
                                    enable = True
                                    raise OutputDirective(
                                        Action.IgnoreAndPassThrough)
                                if enable:
                                    enable = False
                                elif not iftrigger:
                                    enable = True
                                    iftrigger = True
                        else:
                            self.on_error(
                                dirtokens[0].source, dirtokens[0].lineno, "Misplaced #else")

                    elif name == 'endif':
                        at_front_of_file = False
                        if ifstack:
                            oldifstackentry = ifstack.pop()
                            enable = oldifstackentry.enable
                            iftrigger = oldifstackentry.iftrigger
                            ifpassthru = oldifstackentry.ifpassthru
                            if self.debugout is not None:
                                print("%d:%d:%d %s:%d      (%s:%d %s)" % (enable, iftrigger, ifpassthru, dirtokens[0].source, dirtokens[0].lineno,
                                                                          oldifstackentry.startlinetoks[0].source, oldifstackentry.startlinetoks[0].lineno, "".join([n.value for n in oldifstackentry.startlinetoks])), file=self.debugout)
                            skip_auto_pragma_once_possible_check = True
                            if oldifstackentry.rewritten:
                                raise OutputDirective(
                                    Action.IgnoreAndPassThrough)
                        else:
                            self.on_error(
                                dirtokens[0].source, dirtokens[0].lineno, "Misplaced #endif")
                    elif name == 'pragma' and args[0].value == 'once':
                        if enable:
                            self.include_once[self.source] = None
                    elif enable:
                        # Unknown preprocessor directive
                        output_unexpanded_line = (self.on_directive_unknown(
                            dirtokens[0], args, ifpassthru, precedingtoks) is None)

                except OutputDirective as e:
                    if e.action == Action.IgnoreAndPassThrough:
                        output_unexpanded_line = True
                    elif e.action == Action.IgnoreAndRemove:
                        pass
                    else:
                        assert False

            # If there is ever any non-whitespace output outside an include guard, auto pragma once is not possible
            if not skip_auto_pragma_once_possible_check and auto_pragma_once_possible and not ifstack and not all_whitespace:
                auto_pragma_once_possible = False
                if self.debugout is not None:
                    print("%d:%d:%d %s:%d Determined that #include \"%s\" is not entirely wrapped in an include guard macro, disabling auto-applying #pragma once" %
                          (enable, iftrigger, ifpassthru, x[0].source, x[0].lineno, self.source), file=self.debugout)

            if output_and_expand_line or output_unexpanded_line:
                if not all_whitespace:
                    at_front_of_file = False

                # Normal text
                if enable:
                    if output_and_expand_line:
                        chunk.extend(x)
                    elif output_unexpanded_line:
                        for tok in self.expand_macros(chunk):
                            yield tok
                        chunk = []
                        for tok in x:
                            yield tok
                else:
                    # Need to extend with the same number of blank lines
                    i = 0
                    while i < len(x):
                        if x[i].type not in self.t_WS:
                            del x[i]
                        else:
                            i += 1
                    chunk.extend(x)

        for tok in self.expand_macros(chunk):
            yield tok
        chunk = []
        for i in ifstack:
            self.on_error(i.startlinetoks[0].source, i.startlinetoks[0].lineno,
                          "Unterminated " + "".join([n.value for n in i.startlinetoks]))
        if auto_pragma_once_possible and include_guard and include_guard[1] == 1:
            if self.debugout is not None:
                print("%d:%d:%d %s:%d Determined that #include \"%s\" is entirely wrapped in an include guard macro called %s, auto-applying #pragma once" %
                      (enable, iftrigger, ifpassthru, self.source, 0, self.source, include_guard[0]), file=self.debugout)
            self.include_once[self.source] = include_guard[0]
        elif self.auto_pragma_once_enabled and self.source not in self.include_once:
            if self.debugout is not None:
                print("%d:%d:%d %s:%d Did not auto apply #pragma once to this file due to auto_pragma_once_possible=%d, include_guard=%s" % (
                    enable, iftrigger, ifpassthru, self.source, 0, auto_pragma_once_possible, repr(include_guard)), file=self.debugout)
        my_include_time_end = clock()
        self.include_times[my_include_times_idx].elapsed = my_include_time_end - \
            my_include_time_begin
        self.include_depth -= 1


class Stream:
    def __init__(self):
        self.string = ""

    def write(self, string):
        self.string += string

    def read(self):
        return self.string


def preproc(source, fname):
    me = MacroExpander()
    me.parse(source, fname)
    a = Stream()
    me.write(a)
    return a.read()
