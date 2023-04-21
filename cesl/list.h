#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
// CESL (C Extended Standard Library) List Encapsulation

struct I8List {
    int8_t *data;
    int len;
};
struct U8List {
    uint8_t *data;
    int len;
};
; // I8List = int8_t, U8List = uint8_t
struct I16List {
    int16_t *data;
    int len;
};
struct U16List {
    uint16_t *data;
    int len;
};
;
struct I32List {
    int32_t *data;
    int len;
};
struct U32List {
    uint32_t *data;
    int len;
};
;
struct I64List {
    int64_t *data;
    int len;
};
struct U64List {
    uint64_t *data;
    int len;
};
;

struct CharList {
    char *data;
    int len;
};
struct UCharList {
    unsigned char *data;
    int len;
};
;
struct ShortList {
    short *data;
    int len;
};
struct UShortList {
    unsigned short *data;
    int len;
};
;
struct IntList {
    int *data;
    int len;
};
struct UIntList {
    unsigned int *data;
    int len;
};
; // IntList = int, UIntList = unsigned int
struct LongList {
    long *data;
    int len;
};
struct ULongList {
    unsigned long *data;
    int len;
};
;
struct LongLongList {
    long long *data;
    int len;
};
struct ULongLongList {
    unsigned long long *data;
    int len;
};
;

struct FloatList {
    float *data;
    int len;
};
struct DoubleList {
    double *data;
    int len;
};
struct LongDoubleList {
    long double *data;
    int len;
};

struct BoolList {
    bool *data;
    int len;
};

struct StringList {
    char **data;
    int len;
};
