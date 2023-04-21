#ifdef CESL_IMPL
#define ceslf(type, name, args, body) type name args body
#else
#define ceslf(type, name, args, body) type name args;
#endif
