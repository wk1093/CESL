#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct I8Array {
    int8_t *data;
    int size;
    int capacity;
    void (*push)(struct I8Array *, int8_t);
    int8_t (*pop)(struct I8Array *);
    int8_t (*get)(struct I8Array *, int);
    void (*set)(struct I8Array *, int, int8_t);
    void (*clear)(struct I8Array *);
    void (*del)(struct I8Array *);
    int8_t (*remove)(struct I8Array *, int);
};
void pushI8Array(struct I8Array *t, int8_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (int8_t *)realloc(t->data, t->capacity * sizeof(int8_t));
    }
    t->data[t->size] = i;
    t->size++;
}
int8_t popI8Array(struct I8Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
int8_t getI8Array(struct I8Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setI8Array(struct I8Array *t, int i, int8_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearI8Array(struct I8Array *t) { t->size = 0; }
void delI8Array(struct I8Array *t) {
    free(t->data);
    free(t);
}
int8_t removeI8Array(struct I8Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    int8_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct I8Array *newI8Array() {
    struct I8Array *t = (struct I8Array *)malloc(sizeof(struct I8Array));
    t->data = (int8_t *)malloc(10 * sizeof(int8_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushI8Array;
    t->pop = &popI8Array;
    t->get = &getI8Array;
    t->set = &setI8Array;
    t->clear = &clearI8Array;
    t->del = &delI8Array;
    t->remove = &removeI8Array;
    return t;
};
struct U8Array {
    uint8_t *data;
    int size;
    int capacity;
    void (*push)(struct U8Array *, uint8_t);
    uint8_t (*pop)(struct U8Array *);
    uint8_t (*get)(struct U8Array *, int);
    void (*set)(struct U8Array *, int, uint8_t);
    void (*clear)(struct U8Array *);
    void (*del)(struct U8Array *);
    uint8_t (*remove)(struct U8Array *, int);
};
void pushU8Array(struct U8Array *t, uint8_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (uint8_t *)realloc(t->data, t->capacity * sizeof(uint8_t));
    }
    t->data[t->size] = i;
    t->size++;
}
uint8_t popU8Array(struct U8Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
uint8_t getU8Array(struct U8Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setU8Array(struct U8Array *t, int i, uint8_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearU8Array(struct U8Array *t) { t->size = 0; }
void delU8Array(struct U8Array *t) {
    free(t->data);
    free(t);
}
uint8_t removeU8Array(struct U8Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 85, "arr.h",
               "Index out of bounds!");
        ;
    }
    uint8_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct U8Array *newU8Array() {
    struct U8Array *t = (struct U8Array *)malloc(sizeof(struct U8Array));
    t->data = (uint8_t *)malloc(10 * sizeof(uint8_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushU8Array;
    t->pop = &popU8Array;
    t->get = &getU8Array;
    t->set = &setU8Array;
    t->clear = &clearU8Array;
    t->del = &delU8Array;
    t->remove = &removeU8Array;
    return t;
};
;
struct I16Array {
    int16_t *data;
    int size;
    int capacity;
    void (*push)(struct I16Array *, int16_t);
    int16_t (*pop)(struct I16Array *);
    int16_t (*get)(struct I16Array *, int);
    void (*set)(struct I16Array *, int, int16_t);
    void (*clear)(struct I16Array *);
    void (*del)(struct I16Array *);
    int16_t (*remove)(struct I16Array *, int);
};
void pushI16Array(struct I16Array *t, int16_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (int16_t *)realloc(t->data, t->capacity * sizeof(int16_t));
    }
    t->data[t->size] = i;
    t->size++;
}
int16_t popI16Array(struct I16Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
int16_t getI16Array(struct I16Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setI16Array(struct I16Array *t, int i, int16_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearI16Array(struct I16Array *t) { t->size = 0; }
void delI16Array(struct I16Array *t) {
    free(t->data);
    free(t);
}
int16_t removeI16Array(struct I16Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    int16_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct I16Array *newI16Array() {
    struct I16Array *t = (struct I16Array *)malloc(sizeof(struct I16Array));
    t->data = (int16_t *)malloc(10 * sizeof(int16_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushI16Array;
    t->pop = &popI16Array;
    t->get = &getI16Array;
    t->set = &setI16Array;
    t->clear = &clearI16Array;
    t->del = &delI16Array;
    t->remove = &removeI16Array;
    return t;
};
struct U16Array {
    uint16_t *data;
    int size;
    int capacity;
    void (*push)(struct U16Array *, uint16_t);
    uint16_t (*pop)(struct U16Array *);
    uint16_t (*get)(struct U16Array *, int);
    void (*set)(struct U16Array *, int, uint16_t);
    void (*clear)(struct U16Array *);
    void (*del)(struct U16Array *);
    uint16_t (*remove)(struct U16Array *, int);
};
void pushU16Array(struct U16Array *t, uint16_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (uint16_t *)realloc(t->data, t->capacity * sizeof(uint16_t));
    }
    t->data[t->size] = i;
    t->size++;
}
uint16_t popU16Array(struct U16Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
uint16_t getU16Array(struct U16Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setU16Array(struct U16Array *t, int i, uint16_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearU16Array(struct U16Array *t) { t->size = 0; }
void delU16Array(struct U16Array *t) {
    free(t->data);
    free(t);
}
uint16_t removeU16Array(struct U16Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 86, "arr.h",
               "Index out of bounds!");
        ;
    }
    uint16_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct U16Array *newU16Array() {
    struct U16Array *t = (struct U16Array *)malloc(sizeof(struct U16Array));
    t->data = (uint16_t *)malloc(10 * sizeof(uint16_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushU16Array;
    t->pop = &popU16Array;
    t->get = &getU16Array;
    t->set = &setU16Array;
    t->clear = &clearU16Array;
    t->del = &delU16Array;
    t->remove = &removeU16Array;
    return t;
};
;
struct I32Array {
    int32_t *data;
    int size;
    int capacity;
    void (*push)(struct I32Array *, int32_t);
    int32_t (*pop)(struct I32Array *);
    int32_t (*get)(struct I32Array *, int);
    void (*set)(struct I32Array *, int, int32_t);
    void (*clear)(struct I32Array *);
    void (*del)(struct I32Array *);
    int32_t (*remove)(struct I32Array *, int);
};
void pushI32Array(struct I32Array *t, int32_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (int32_t *)realloc(t->data, t->capacity * sizeof(int32_t));
    }
    t->data[t->size] = i;
    t->size++;
}
int32_t popI32Array(struct I32Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
int32_t getI32Array(struct I32Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setI32Array(struct I32Array *t, int i, int32_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearI32Array(struct I32Array *t) { t->size = 0; }
void delI32Array(struct I32Array *t) {
    free(t->data);
    free(t);
}
int32_t removeI32Array(struct I32Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    int32_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct I32Array *newI32Array() {
    struct I32Array *t = (struct I32Array *)malloc(sizeof(struct I32Array));
    t->data = (int32_t *)malloc(10 * sizeof(int32_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushI32Array;
    t->pop = &popI32Array;
    t->get = &getI32Array;
    t->set = &setI32Array;
    t->clear = &clearI32Array;
    t->del = &delI32Array;
    t->remove = &removeI32Array;
    return t;
};
struct U32Array {
    uint32_t *data;
    int size;
    int capacity;
    void (*push)(struct U32Array *, uint32_t);
    uint32_t (*pop)(struct U32Array *);
    uint32_t (*get)(struct U32Array *, int);
    void (*set)(struct U32Array *, int, uint32_t);
    void (*clear)(struct U32Array *);
    void (*del)(struct U32Array *);
    uint32_t (*remove)(struct U32Array *, int);
};
void pushU32Array(struct U32Array *t, uint32_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (uint32_t *)realloc(t->data, t->capacity * sizeof(uint32_t));
    }
    t->data[t->size] = i;
    t->size++;
}
uint32_t popU32Array(struct U32Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
uint32_t getU32Array(struct U32Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setU32Array(struct U32Array *t, int i, uint32_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearU32Array(struct U32Array *t) { t->size = 0; }
void delU32Array(struct U32Array *t) {
    free(t->data);
    free(t);
}
uint32_t removeU32Array(struct U32Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 87, "arr.h",
               "Index out of bounds!");
        ;
    }
    uint32_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct U32Array *newU32Array() {
    struct U32Array *t = (struct U32Array *)malloc(sizeof(struct U32Array));
    t->data = (uint32_t *)malloc(10 * sizeof(uint32_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushU32Array;
    t->pop = &popU32Array;
    t->get = &getU32Array;
    t->set = &setU32Array;
    t->clear = &clearU32Array;
    t->del = &delU32Array;
    t->remove = &removeU32Array;
    return t;
};
;
struct I64Array {
    int64_t *data;
    int size;
    int capacity;
    void (*push)(struct I64Array *, int64_t);
    int64_t (*pop)(struct I64Array *);
    int64_t (*get)(struct I64Array *, int);
    void (*set)(struct I64Array *, int, int64_t);
    void (*clear)(struct I64Array *);
    void (*del)(struct I64Array *);
    int64_t (*remove)(struct I64Array *, int);
};
void pushI64Array(struct I64Array *t, int64_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (int64_t *)realloc(t->data, t->capacity * sizeof(int64_t));
    }
    t->data[t->size] = i;
    t->size++;
}
int64_t popI64Array(struct I64Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
int64_t getI64Array(struct I64Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setI64Array(struct I64Array *t, int i, int64_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearI64Array(struct I64Array *t) { t->size = 0; }
void delI64Array(struct I64Array *t) {
    free(t->data);
    free(t);
}
int64_t removeI64Array(struct I64Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    int64_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct I64Array *newI64Array() {
    struct I64Array *t = (struct I64Array *)malloc(sizeof(struct I64Array));
    t->data = (int64_t *)malloc(10 * sizeof(int64_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushI64Array;
    t->pop = &popI64Array;
    t->get = &getI64Array;
    t->set = &setI64Array;
    t->clear = &clearI64Array;
    t->del = &delI64Array;
    t->remove = &removeI64Array;
    return t;
};
struct U64Array {
    uint64_t *data;
    int size;
    int capacity;
    void (*push)(struct U64Array *, uint64_t);
    uint64_t (*pop)(struct U64Array *);
    uint64_t (*get)(struct U64Array *, int);
    void (*set)(struct U64Array *, int, uint64_t);
    void (*clear)(struct U64Array *);
    void (*del)(struct U64Array *);
    uint64_t (*remove)(struct U64Array *, int);
};
void pushU64Array(struct U64Array *t, uint64_t i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (uint64_t *)realloc(t->data, t->capacity * sizeof(uint64_t));
    }
    t->data[t->size] = i;
    t->size++;
}
uint64_t popU64Array(struct U64Array *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
uint64_t getU64Array(struct U64Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setU64Array(struct U64Array *t, int i, uint64_t v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearU64Array(struct U64Array *t) { t->size = 0; }
void delU64Array(struct U64Array *t) {
    free(t->data);
    free(t);
}
uint64_t removeU64Array(struct U64Array *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 88, "arr.h",
               "Index out of bounds!");
        ;
    }
    uint64_t v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct U64Array *newU64Array() {
    struct U64Array *t = (struct U64Array *)malloc(sizeof(struct U64Array));
    t->data = (uint64_t *)malloc(10 * sizeof(uint64_t));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushU64Array;
    t->pop = &popU64Array;
    t->get = &getU64Array;
    t->set = &setU64Array;
    t->clear = &clearU64Array;
    t->del = &delU64Array;
    t->remove = &removeU64Array;
    return t;
};
;

struct CharArray {
    char *data;
    int size;
    int capacity;
    void (*push)(struct CharArray *, char);
    char (*pop)(struct CharArray *);
    char (*get)(struct CharArray *, int);
    void (*set)(struct CharArray *, int, char);
    void (*clear)(struct CharArray *);
    void (*del)(struct CharArray *);
    char (*remove)(struct CharArray *, int);
};
void pushCharArray(struct CharArray *t, char i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (char *)realloc(t->data, t->capacity * sizeof(char));
    }
    t->data[t->size] = i;
    t->size++;
}
char popCharArray(struct CharArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
char getCharArray(struct CharArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setCharArray(struct CharArray *t, int i, char v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearCharArray(struct CharArray *t) { t->size = 0; }
void delCharArray(struct CharArray *t) {
    free(t->data);
    free(t);
}
char removeCharArray(struct CharArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    char v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct CharArray *newCharArray() {
    struct CharArray *t = (struct CharArray *)malloc(sizeof(struct CharArray));
    t->data = (char *)malloc(10 * sizeof(char));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushCharArray;
    t->pop = &popCharArray;
    t->get = &getCharArray;
    t->set = &setCharArray;
    t->clear = &clearCharArray;
    t->del = &delCharArray;
    t->remove = &removeCharArray;
    return t;
};
struct UCharArray {
    unsigned char *data;
    int size;
    int capacity;
    void (*push)(struct UCharArray *, unsigned char);
    unsigned char (*pop)(struct UCharArray *);
    unsigned char (*get)(struct UCharArray *, int);
    void (*set)(struct UCharArray *, int, unsigned char);
    void (*clear)(struct UCharArray *);
    void (*del)(struct UCharArray *);
    unsigned char (*remove)(struct UCharArray *, int);
};
void pushUCharArray(struct UCharArray *t, unsigned char i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (unsigned char *)realloc(t->data,
                                           t->capacity * sizeof(unsigned char));
    }
    t->data[t->size] = i;
    t->size++;
}
unsigned char popUCharArray(struct UCharArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
unsigned char getUCharArray(struct UCharArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setUCharArray(struct UCharArray *t, int i, unsigned char v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearUCharArray(struct UCharArray *t) { t->size = 0; }
void delUCharArray(struct UCharArray *t) {
    free(t->data);
    free(t);
}
unsigned char removeUCharArray(struct UCharArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 95, "arr.h",
               "Index out of bounds!");
        ;
    }
    unsigned char v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct UCharArray *newUCharArray() {
    struct UCharArray *t =
        (struct UCharArray *)malloc(sizeof(struct UCharArray));
    t->data = (unsigned char *)malloc(10 * sizeof(unsigned char));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushUCharArray;
    t->pop = &popUCharArray;
    t->get = &getUCharArray;
    t->set = &setUCharArray;
    t->clear = &clearUCharArray;
    t->del = &delUCharArray;
    t->remove = &removeUCharArray;
    return t;
};
;
struct ShortArray {
    short *data;
    int size;
    int capacity;
    void (*push)(struct ShortArray *, short);
    short (*pop)(struct ShortArray *);
    short (*get)(struct ShortArray *, int);
    void (*set)(struct ShortArray *, int, short);
    void (*clear)(struct ShortArray *);
    void (*del)(struct ShortArray *);
    short (*remove)(struct ShortArray *, int);
};
void pushShortArray(struct ShortArray *t, short i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (short *)realloc(t->data, t->capacity * sizeof(short));
    }
    t->data[t->size] = i;
    t->size++;
}
short popShortArray(struct ShortArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
short getShortArray(struct ShortArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setShortArray(struct ShortArray *t, int i, short v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearShortArray(struct ShortArray *t) { t->size = 0; }
void delShortArray(struct ShortArray *t) {
    free(t->data);
    free(t);
}
short removeShortArray(struct ShortArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    short v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct ShortArray *newShortArray() {
    struct ShortArray *t =
        (struct ShortArray *)malloc(sizeof(struct ShortArray));
    t->data = (short *)malloc(10 * sizeof(short));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushShortArray;
    t->pop = &popShortArray;
    t->get = &getShortArray;
    t->set = &setShortArray;
    t->clear = &clearShortArray;
    t->del = &delShortArray;
    t->remove = &removeShortArray;
    return t;
};
struct UShortArray {
    unsigned short *data;
    int size;
    int capacity;
    void (*push)(struct UShortArray *, unsigned short);
    unsigned short (*pop)(struct UShortArray *);
    unsigned short (*get)(struct UShortArray *, int);
    void (*set)(struct UShortArray *, int, unsigned short);
    void (*clear)(struct UShortArray *);
    void (*del)(struct UShortArray *);
    unsigned short (*remove)(struct UShortArray *, int);
};
void pushUShortArray(struct UShortArray *t, unsigned short i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (unsigned short *)realloc(
            t->data, t->capacity * sizeof(unsigned short));
    }
    t->data[t->size] = i;
    t->size++;
}
unsigned short popUShortArray(struct UShortArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
unsigned short getUShortArray(struct UShortArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setUShortArray(struct UShortArray *t, int i, unsigned short v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearUShortArray(struct UShortArray *t) { t->size = 0; }
void delUShortArray(struct UShortArray *t) {
    free(t->data);
    free(t);
}
unsigned short removeUShortArray(struct UShortArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 96, "arr.h",
               "Index out of bounds!");
        ;
    }
    unsigned short v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct UShortArray *newUShortArray() {
    struct UShortArray *t =
        (struct UShortArray *)malloc(sizeof(struct UShortArray));
    t->data = (unsigned short *)malloc(10 * sizeof(unsigned short));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushUShortArray;
    t->pop = &popUShortArray;
    t->get = &getUShortArray;
    t->set = &setUShortArray;
    t->clear = &clearUShortArray;
    t->del = &delUShortArray;
    t->remove = &removeUShortArray;
    return t;
};
;
struct IntArray {
    int *data;
    int size;
    int capacity;
    void (*push)(struct IntArray *, int);
    int (*pop)(struct IntArray *);
    int (*get)(struct IntArray *, int);
    void (*set)(struct IntArray *, int, int);
    void (*clear)(struct IntArray *);
    void (*del)(struct IntArray *);
    int (*remove)(struct IntArray *, int);
};
void pushIntArray(struct IntArray *t, int i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (int *)realloc(t->data, t->capacity * sizeof(int));
    }
    t->data[t->size] = i;
    t->size++;
}
int popIntArray(struct IntArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
int getIntArray(struct IntArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setIntArray(struct IntArray *t, int i, int v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearIntArray(struct IntArray *t) { t->size = 0; }
void delIntArray(struct IntArray *t) {
    free(t->data);
    free(t);
}
int removeIntArray(struct IntArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    int v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct IntArray *newIntArray() {
    struct IntArray *t = (struct IntArray *)malloc(sizeof(struct IntArray));
    t->data = (int *)malloc(10 * sizeof(int));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushIntArray;
    t->pop = &popIntArray;
    t->get = &getIntArray;
    t->set = &setIntArray;
    t->clear = &clearIntArray;
    t->del = &delIntArray;
    t->remove = &removeIntArray;
    return t;
};
struct UIntArray {
    unsigned int *data;
    int size;
    int capacity;
    void (*push)(struct UIntArray *, unsigned int);
    unsigned int (*pop)(struct UIntArray *);
    unsigned int (*get)(struct UIntArray *, int);
    void (*set)(struct UIntArray *, int, unsigned int);
    void (*clear)(struct UIntArray *);
    void (*del)(struct UIntArray *);
    unsigned int (*remove)(struct UIntArray *, int);
};
void pushUIntArray(struct UIntArray *t, unsigned int i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (unsigned int *)realloc(t->data,
                                          t->capacity * sizeof(unsigned int));
    }
    t->data[t->size] = i;
    t->size++;
}
unsigned int popUIntArray(struct UIntArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
unsigned int getUIntArray(struct UIntArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setUIntArray(struct UIntArray *t, int i, unsigned int v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearUIntArray(struct UIntArray *t) { t->size = 0; }
void delUIntArray(struct UIntArray *t) {
    free(t->data);
    free(t);
}
unsigned int removeUIntArray(struct UIntArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 97, "arr.h",
               "Index out of bounds!");
        ;
    }
    unsigned int v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct UIntArray *newUIntArray() {
    struct UIntArray *t = (struct UIntArray *)malloc(sizeof(struct UIntArray));
    t->data = (unsigned int *)malloc(10 * sizeof(unsigned int));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushUIntArray;
    t->pop = &popUIntArray;
    t->get = &getUIntArray;
    t->set = &setUIntArray;
    t->clear = &clearUIntArray;
    t->del = &delUIntArray;
    t->remove = &removeUIntArray;
    return t;
};
;
struct LongArray {
    long *data;
    int size;
    int capacity;
    void (*push)(struct LongArray *, long);
    long (*pop)(struct LongArray *);
    long (*get)(struct LongArray *, int);
    void (*set)(struct LongArray *, int, long);
    void (*clear)(struct LongArray *);
    void (*del)(struct LongArray *);
    long (*remove)(struct LongArray *, int);
};
void pushLongArray(struct LongArray *t, long i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (long *)realloc(t->data, t->capacity * sizeof(long));
    }
    t->data[t->size] = i;
    t->size++;
}
long popLongArray(struct LongArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
long getLongArray(struct LongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setLongArray(struct LongArray *t, int i, long v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearLongArray(struct LongArray *t) { t->size = 0; }
void delLongArray(struct LongArray *t) {
    free(t->data);
    free(t);
}
long removeLongArray(struct LongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    long v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct LongArray *newLongArray() {
    struct LongArray *t = (struct LongArray *)malloc(sizeof(struct LongArray));
    t->data = (long *)malloc(10 * sizeof(long));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushLongArray;
    t->pop = &popLongArray;
    t->get = &getLongArray;
    t->set = &setLongArray;
    t->clear = &clearLongArray;
    t->del = &delLongArray;
    t->remove = &removeLongArray;
    return t;
};
struct ULongArray {
    unsigned long *data;
    int size;
    int capacity;
    void (*push)(struct ULongArray *, unsigned long);
    unsigned long (*pop)(struct ULongArray *);
    unsigned long (*get)(struct ULongArray *, int);
    void (*set)(struct ULongArray *, int, unsigned long);
    void (*clear)(struct ULongArray *);
    void (*del)(struct ULongArray *);
    unsigned long (*remove)(struct ULongArray *, int);
};
void pushULongArray(struct ULongArray *t, unsigned long i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (unsigned long *)realloc(t->data,
                                           t->capacity * sizeof(unsigned long));
    }
    t->data[t->size] = i;
    t->size++;
}
unsigned long popULongArray(struct ULongArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
unsigned long getULongArray(struct ULongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setULongArray(struct ULongArray *t, int i, unsigned long v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearULongArray(struct ULongArray *t) { t->size = 0; }
void delULongArray(struct ULongArray *t) {
    free(t->data);
    free(t);
}
unsigned long removeULongArray(struct ULongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 98, "arr.h",
               "Index out of bounds!");
        ;
    }
    unsigned long v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct ULongArray *newULongArray() {
    struct ULongArray *t =
        (struct ULongArray *)malloc(sizeof(struct ULongArray));
    t->data = (unsigned long *)malloc(10 * sizeof(unsigned long));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushULongArray;
    t->pop = &popULongArray;
    t->get = &getULongArray;
    t->set = &setULongArray;
    t->clear = &clearULongArray;
    t->del = &delULongArray;
    t->remove = &removeULongArray;
    return t;
};
;
struct LongLongArray {
    long long *data;
    int size;
    int capacity;
    void (*push)(struct LongLongArray *, long long);
    long long (*pop)(struct LongLongArray *);
    long long (*get)(struct LongLongArray *, int);
    void (*set)(struct LongLongArray *, int, long long);
    void (*clear)(struct LongLongArray *);
    void (*del)(struct LongLongArray *);
    long long (*remove)(struct LongLongArray *, int);
};
void pushLongLongArray(struct LongLongArray *t, long long i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data =
            (long long *)realloc(t->data, t->capacity * sizeof(long long));
    }
    t->data[t->size] = i;
    t->size++;
}
long long popLongLongArray(struct LongLongArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
long long getLongLongArray(struct LongLongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setLongLongArray(struct LongLongArray *t, int i, long long v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearLongLongArray(struct LongLongArray *t) { t->size = 0; }
void delLongLongArray(struct LongLongArray *t) {
    free(t->data);
    free(t);
}
long long removeLongLongArray(struct LongLongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    long long v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct LongLongArray *newLongLongArray() {
    struct LongLongArray *t =
        (struct LongLongArray *)malloc(sizeof(struct LongLongArray));
    t->data = (long long *)malloc(10 * sizeof(long long));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushLongLongArray;
    t->pop = &popLongLongArray;
    t->get = &getLongLongArray;
    t->set = &setLongLongArray;
    t->clear = &clearLongLongArray;
    t->del = &delLongLongArray;
    t->remove = &removeLongLongArray;
    return t;
};
struct ULongLongArray {
    unsigned long long *data;
    int size;
    int capacity;
    void (*push)(struct ULongLongArray *, unsigned long long);
    unsigned long long (*pop)(struct ULongLongArray *);
    unsigned long long (*get)(struct ULongLongArray *, int);
    void (*set)(struct ULongLongArray *, int, unsigned long long);
    void (*clear)(struct ULongLongArray *);
    void (*del)(struct ULongLongArray *);
    unsigned long long (*remove)(struct ULongLongArray *, int);
};
void pushULongLongArray(struct ULongLongArray *t, unsigned long long i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (unsigned long long *)realloc(
            t->data, t->capacity * sizeof(unsigned long long));
    }
    t->data[t->size] = i;
    t->size++;
}
unsigned long long popULongLongArray(struct ULongLongArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
unsigned long long getULongLongArray(struct ULongLongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setULongLongArray(struct ULongLongArray *t, int i, unsigned long long v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearULongLongArray(struct ULongLongArray *t) { t->size = 0; }
void delULongLongArray(struct ULongLongArray *t) {
    free(t->data);
    free(t);
}
unsigned long long removeULongLongArray(struct ULongLongArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 99, "arr.h",
               "Index out of bounds!");
        ;
    }
    unsigned long long v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct ULongLongArray *newULongLongArray() {
    struct ULongLongArray *t =
        (struct ULongLongArray *)malloc(sizeof(struct ULongLongArray));
    t->data = (unsigned long long *)malloc(10 * sizeof(unsigned long long));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushULongLongArray;
    t->pop = &popULongLongArray;
    t->get = &getULongLongArray;
    t->set = &setULongLongArray;
    t->clear = &clearULongLongArray;
    t->del = &delULongLongArray;
    t->remove = &removeULongLongArray;
    return t;
};
;

struct FloatArray {
    float *data;
    int size;
    int capacity;
    void (*push)(struct FloatArray *, float);
    float (*pop)(struct FloatArray *);
    float (*get)(struct FloatArray *, int);
    void (*set)(struct FloatArray *, int, float);
    void (*clear)(struct FloatArray *);
    void (*del)(struct FloatArray *);
    float (*remove)(struct FloatArray *, int);
};
void pushFloatArray(struct FloatArray *t, float i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (float *)realloc(t->data, t->capacity * sizeof(float));
    }
    t->data[t->size] = i;
    t->size++;
}
float popFloatArray(struct FloatArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 101, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
float getFloatArray(struct FloatArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 101, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setFloatArray(struct FloatArray *t, int i, float v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 101, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearFloatArray(struct FloatArray *t) { t->size = 0; }
void delFloatArray(struct FloatArray *t) {
    free(t->data);
    free(t);
}
float removeFloatArray(struct FloatArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 101, "arr.h",
               "Index out of bounds!");
        ;
    }
    float v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct FloatArray *newFloatArray() {
    struct FloatArray *t =
        (struct FloatArray *)malloc(sizeof(struct FloatArray));
    t->data = (float *)malloc(10 * sizeof(float));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushFloatArray;
    t->pop = &popFloatArray;
    t->get = &getFloatArray;
    t->set = &setFloatArray;
    t->clear = &clearFloatArray;
    t->del = &delFloatArray;
    t->remove = &removeFloatArray;
    return t;
};
struct DoubleArray {
    double *data;
    int size;
    int capacity;
    void (*push)(struct DoubleArray *, double);
    double (*pop)(struct DoubleArray *);
    double (*get)(struct DoubleArray *, int);
    void (*set)(struct DoubleArray *, int, double);
    void (*clear)(struct DoubleArray *);
    void (*del)(struct DoubleArray *);
    double (*remove)(struct DoubleArray *, int);
};
void pushDoubleArray(struct DoubleArray *t, double i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (double *)realloc(t->data, t->capacity * sizeof(double));
    }
    t->data[t->size] = i;
    t->size++;
}
double popDoubleArray(struct DoubleArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 102, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
double getDoubleArray(struct DoubleArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 102, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setDoubleArray(struct DoubleArray *t, int i, double v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 102, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearDoubleArray(struct DoubleArray *t) { t->size = 0; }
void delDoubleArray(struct DoubleArray *t) {
    free(t->data);
    free(t);
}
double removeDoubleArray(struct DoubleArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 102, "arr.h",
               "Index out of bounds!");
        ;
    }
    double v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct DoubleArray *newDoubleArray() {
    struct DoubleArray *t =
        (struct DoubleArray *)malloc(sizeof(struct DoubleArray));
    t->data = (double *)malloc(10 * sizeof(double));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushDoubleArray;
    t->pop = &popDoubleArray;
    t->get = &getDoubleArray;
    t->set = &setDoubleArray;
    t->clear = &clearDoubleArray;
    t->del = &delDoubleArray;
    t->remove = &removeDoubleArray;
    return t;
};
struct LongDoubleArray {
    long double *data;
    int size;
    int capacity;
    void (*push)(struct LongDoubleArray *, long double);
    long double (*pop)(struct LongDoubleArray *);
    long double (*get)(struct LongDoubleArray *, int);
    void (*set)(struct LongDoubleArray *, int, long double);
    void (*clear)(struct LongDoubleArray *);
    void (*del)(struct LongDoubleArray *);
    long double (*remove)(struct LongDoubleArray *, int);
};
void pushLongDoubleArray(struct LongDoubleArray *t, long double i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data =
            (long double *)realloc(t->data, t->capacity * sizeof(long double));
    }
    t->data[t->size] = i;
    t->size++;
}
long double popLongDoubleArray(struct LongDoubleArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 103, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
long double getLongDoubleArray(struct LongDoubleArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 103, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setLongDoubleArray(struct LongDoubleArray *t, int i, long double v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 103, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearLongDoubleArray(struct LongDoubleArray *t) { t->size = 0; }
void delLongDoubleArray(struct LongDoubleArray *t) {
    free(t->data);
    free(t);
}
long double removeLongDoubleArray(struct LongDoubleArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 103, "arr.h",
               "Index out of bounds!");
        ;
    }
    long double v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct LongDoubleArray *newLongDoubleArray() {
    struct LongDoubleArray *t =
        (struct LongDoubleArray *)malloc(sizeof(struct LongDoubleArray));
    t->data = (long double *)malloc(10 * sizeof(long double));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushLongDoubleArray;
    t->pop = &popLongDoubleArray;
    t->get = &getLongDoubleArray;
    t->set = &setLongDoubleArray;
    t->clear = &clearLongDoubleArray;
    t->del = &delLongDoubleArray;
    t->remove = &removeLongDoubleArray;
    return t;
};

struct BoolArray {
    bool *data;
    int size;
    int capacity;
    void (*push)(struct BoolArray *, bool);
    bool (*pop)(struct BoolArray *);
    bool (*get)(struct BoolArray *, int);
    void (*set)(struct BoolArray *, int, bool);
    void (*clear)(struct BoolArray *);
    void (*del)(struct BoolArray *);
    bool (*remove)(struct BoolArray *, int);
};
void pushBoolArray(struct BoolArray *t, bool i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (bool *)realloc(t->data, t->capacity * sizeof(bool));
    }
    t->data[t->size] = i;
    t->size++;
}
bool popBoolArray(struct BoolArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 105, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
bool getBoolArray(struct BoolArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 105, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setBoolArray(struct BoolArray *t, int i, bool v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 105, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearBoolArray(struct BoolArray *t) { t->size = 0; }
void delBoolArray(struct BoolArray *t) {
    free(t->data);
    free(t);
}
bool removeBoolArray(struct BoolArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 105, "arr.h",
               "Index out of bounds!");
        ;
    }
    bool v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct BoolArray *newBoolArray() {
    struct BoolArray *t = (struct BoolArray *)malloc(sizeof(struct BoolArray));
    t->data = (bool *)malloc(10 * sizeof(bool));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushBoolArray;
    t->pop = &popBoolArray;
    t->get = &getBoolArray;
    t->set = &setBoolArray;
    t->clear = &clearBoolArray;
    t->del = &delBoolArray;
    t->remove = &removeBoolArray;
    return t;
};

struct StringArray {
    char **data;
    int size;
    int capacity;
    void (*push)(struct StringArray *, char *);
    char *(*pop)(struct StringArray *);
    char *(*get)(struct StringArray *, int);
    void (*set)(struct StringArray *, int, char *);
    void (*clear)(struct StringArray *);
    void (*del)(struct StringArray *);
    char *(*remove)(struct StringArray *, int);
};
void pushStringArray(struct StringArray *t, char *i) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        t->data = (char **)realloc(t->data, t->capacity * sizeof(char *));
    }
    t->data[t->size] = i;
    t->size++;
}
char *popStringArray(struct StringArray *t) {
    if (t->size == 0) {
        printf("ERROR (line %d in '%s'): %s\n", 107, "arr.h",
               "Cannot pop from an empty vector!");
        ;
    }
    t->size--;
    return t->data[t->size];
}
char *getStringArray(struct StringArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 107, "arr.h",
               "Index out of bounds!");
        ;
    }
    return t->data[i];
}
void setStringArray(struct StringArray *t, int i, char *v) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 107, "arr.h",
               "Index out of bounds!");
        ;
    }
    t->data[i] = v;
}
void clearStringArray(struct StringArray *t) { t->size = 0; }
void delStringArray(struct StringArray *t) {
    free(t->data);
    free(t);
}
char *removeStringArray(struct StringArray *t, int i) {
    if (i < 0 || i >= t->size) {
        printf("ERROR (line %d in '%s'): %s\n", 107, "arr.h",
               "Index out of bounds!");
        ;
    }
    char *v = t->data[i];
    for (int j = i; j < t->size - 1; j++) {
        t->data[j] = t->data[j + 1];
    }
    t->size--;
    return v;
}
struct StringArray *newStringArray() {
    struct StringArray *t =
        (struct StringArray *)malloc(sizeof(struct StringArray));
    t->data = (char **)malloc(10 * sizeof(char *));
    t->size = 0;
    t->capacity = 10;
    t->push = &pushStringArray;
    t->pop = &popStringArray;
    t->get = &getStringArray;
    t->set = &setStringArray;
    t->clear = &clearStringArray;
    t->del = &delStringArray;
    t->remove = &removeStringArray;
    return t;
};
