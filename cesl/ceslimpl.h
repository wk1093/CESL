#pragma once
// #define ceslf(type, name, args, body)

// if IMPL is defined, then we are compiling the implementation
// else we are compiling the interface

#ifdef CESL_IMPL
#define STB_IMAGE_IMPLEMENTATION
#define ceslf(head, body) head body
#else
#define ceslf(head, body) head;
#endif
