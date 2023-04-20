#include "list.h"
#include <stdlib.h>
#include <string.h>
struct I8List copyI8List(struct I8List in) {
    struct I8List newList;
    newList.data = (int8_t *)malloc(sizeof(int8_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(int8_t));
};
struct U8List copyU8List(struct U8List in) {
    struct U8List newList;
    newList.data = (uint8_t *)malloc(sizeof(uint8_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(uint8_t));
};
;
struct I16List copyI16List(struct I16List in) {
    struct I16List newList;
    newList.data = (int16_t *)malloc(sizeof(int16_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(int16_t));
};
struct U16List copyU16List(struct U16List in) {
    struct U16List newList;
    newList.data = (uint16_t *)malloc(sizeof(uint16_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(uint16_t));
};
;
struct I32List copyI32List(struct I32List in) {
    struct I32List newList;
    newList.data = (int32_t *)malloc(sizeof(int32_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(int32_t));
};
struct U32List copyU32List(struct U32List in) {
    struct U32List newList;
    newList.data = (uint32_t *)malloc(sizeof(uint32_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(uint32_t));
};
;
struct I64List copyI64List(struct I64List in) {
    struct I64List newList;
    newList.data = (int64_t *)malloc(sizeof(int64_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(int64_t));
};
struct U64List copyU64List(struct U64List in) {
    struct U64List newList;
    newList.data = (uint64_t *)malloc(sizeof(uint64_t) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(uint64_t));
};
;

struct CharList copyCharList(struct CharList in) {
    struct CharList newList;
    newList.data = (char *)malloc(sizeof(char) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(char));
};
struct UCharList copyUCharList(struct UCharList in) {
    struct UCharList newList;
    newList.data = (unsigned char *)malloc(sizeof(unsigned char) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(unsigned char));
};
;
struct ShortList copyShortList(struct ShortList in) {
    struct ShortList newList;
    newList.data = (short *)malloc(sizeof(short) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(short));
};
struct UShortList copyUShortList(struct UShortList in) {
    struct UShortList newList;
    newList.data = (unsigned short *)malloc(sizeof(unsigned short) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(unsigned short));
};
;
struct IntList copyIntList(struct IntList in) {
    struct IntList newList;
    newList.data = (int *)malloc(sizeof(int) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(int));
};
struct UIntList copyUIntList(struct UIntList in) {
    struct UIntList newList;
    newList.data = (unsigned int *)malloc(sizeof(unsigned int) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(unsigned int));
};
;
struct LongList copyLongList(struct LongList in) {
    struct LongList newList;
    newList.data = (long *)malloc(sizeof(long) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(long));
};
struct ULongList copyULongList(struct ULongList in) {
    struct ULongList newList;
    newList.data = (unsigned long *)malloc(sizeof(unsigned long) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(unsigned long));
};
;
struct LongLongList copyLongLongList(struct LongLongList in) {
    struct LongLongList newList;
    newList.data = (long long *)malloc(sizeof(long long) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(long long));
};
struct ULongLongList copyULongLongList(struct ULongLongList in) {
    struct ULongLongList newList;
    newList.data =
        (unsigned long long *)malloc(sizeof(unsigned long long) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(unsigned long long));
};
;

struct FloatList copyFloatList(struct FloatList in) {
    struct FloatList newList;
    newList.data = (float *)malloc(sizeof(float) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(float));
};
struct DoubleList copyDoubleList(struct DoubleList in) {
    struct DoubleList newList;
    newList.data = (double *)malloc(sizeof(double) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(double));
};
struct LongDoubleList copyLongDoubleList(struct LongDoubleList in) {
    struct LongDoubleList newList;
    newList.data = (long double *)malloc(sizeof(long double) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(long double));
};

struct BoolList copyBoolList(struct BoolList in) {
    struct BoolList newList;
    newList.data = (bool *)malloc(sizeof(bool) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(bool));
};

struct StringList copyStringList(struct StringList in) {
    struct StringList newList;
    newList.data = (char **)malloc(sizeof(char *) * in.len);
    newList.len = in.len;
    memcpy(newList.data, in.data, in.len * sizeof(char *));
};
