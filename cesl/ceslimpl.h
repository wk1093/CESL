// #define ceslf(type, name, args, body)

// if IMPL is defined, then we are compiling the implementation
// else we are compiling the interface

#ifdef CESL_IMPL
#define ceslf(head, body) head body
#else
#define ceslf(head, body) head;
#endif
