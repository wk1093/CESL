from preproc import preproc
import os
import re


def count(file):
    with open(file, "r") as f:
        return len(f.readlines())

# lines:


def lines(dir: str):
    core = 0
    for l in os.listdir(dir):
        if not os.path.isfile(os.path.join(dir, l)):
            continue
        lines = count(os.path.join(dir, l))
        print(f"{l}: {lines} lines")
        core += lines
    print(f"\nTotal: {core} lines")
    return core


# for file in ../core, preprocess, then make the same filename in ../cesl
for l in os.listdir("core"):
    with open(os.path.join("core", l), "r") as f:
        src = re.sub(r"#line.*\n", "", (preproc(f.read(), l)))

    with open(os.path.join("cesl", l), "w+") as f:
        f.write(src)
    os.system(
        "clang-format --style=\"{BasedOnStyle: llvm, IndentWidth: 4}\" -i " + os.path.join("cesl", l))

lines("cesl")
