#pragma once
#include "arr.h"
#include "ceslimpl.h"
#include <stdio.h>
#include <stdlib.h>
// CESL (C Extended Standard Library) Vector Math

struct Vec2i {
    int x, y;
    struct Vec2i (*add)(struct Vec2i, struct Vec2i);
    struct Vec2i (*addv)(struct Vec2i, int);
    struct Vec2i (*sub)(struct Vec2i, struct Vec2i);
    struct Vec2i (*subv)(struct Vec2i, int);
    struct Vec2i (*mul)(struct Vec2i, struct Vec2i);
    struct Vec2i (*mulv)(struct Vec2i, int);
    struct Vec2i (*div)(struct Vec2i, struct Vec2i);
    struct Vec2i (*divv)(struct Vec2i, int);
    int (*len)(struct Vec2i);
    char *(*str)(struct Vec2i);
    struct Vec2i (*norm)(struct Vec2i);
    struct Vec2i (*cross)(struct Vec2i, struct Vec2i);
    int (*dot)(struct Vec2i, struct Vec2i);
};
struct Vec2i newVec2i();
;
ceslf(struct Vec2i addVec2i(struct Vec2i a, struct Vec2i b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2i addvVec2i(struct Vec2i a, int b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x + b;
        v.y = a.y + b;
    };
    return v;
});
;
;
ceslf(struct Vec2i subVec2i(struct Vec2i a, struct Vec2i b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2i subvVec2i(struct Vec2i a, int b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x - b;
        v.y = a.y - b;
    };
    return v;
});
;
;
ceslf(struct Vec2i mulVec2i(struct Vec2i a, struct Vec2i b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2i mulvVec2i(struct Vec2i a, int b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x * b;
        v.y = a.y * b;
    };
    return v;
});
;
;
ceslf(struct Vec2i divVec2i(struct Vec2i a, struct Vec2i b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2i divvVec2i(struct Vec2i a, int b), {
    struct Vec2i v = newVec2i();
    {
        v.x = a.x / b;
        v.y = a.y / b;
    };
    return v;
});
;
;
ceslf(int lenVec2i(struct Vec2i v), { return v.x + v.y; });
ceslf(char *strVec2i(struct Vec2i v), {
    int length = snprintf(NULL, 0,
                          "int"
                          "("
                          "%d"
                          ", "
                          "%d"
                          ")",
                          v.x, v.y);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "int"
             "("
             "%d"
             ", "
             "%d"
             ")",
             v.x, v.y);
    return str;
});
;
ceslf(struct Vec2i normVec2i(struct Vec2i v), { return v.divv(v, v.len(v)); });
;
ceslf(int dotVec2i(struct Vec2i a, struct Vec2i b),
      { return a.x * b.x + a.y * b.y; });
ceslf(struct Vec2i crossVec2i(struct Vec2i a, struct Vec2i b), {
    struct Vec2i v = newVec2i();
    v.x = a.x * b.y - a.y * b.x;
    v.y = a.y * b.x - a.x * b.y;
    return v;
});
ceslf(struct Vec2i newVec2i(), {
    struct Vec2i self;
    {
        self.x = 0;
        self.y = 0;
    };
    self.add = &addVec2i;
    self.addv = &addvVec2i;
    self.sub = &subVec2i;
    self.subv = &subvVec2i;
    self.mul = &mulVec2i;
    self.mulv = &mulvVec2i;
    self.div = &divVec2i;
    self.divv = &divvVec2i;
    self.len = &lenVec2i;
    self.str = &strVec2i;
    self.norm = &normVec2i;
    self.cross = &crossVec2i;
    self.dot = &dotVec2i;
    return self;
});
;
ceslf(struct Vec2i initVec2i(int x, int y), {
    struct Vec2i self;
    {
        self.x = x;
        self.y = y;
    };
    self.add = &addVec2i;
    self.addv = &addvVec2i;
    self.sub = &subVec2i;
    self.subv = &subvVec2i;
    self.mul = &mulVec2i;
    self.mulv = &mulvVec2i;
    self.div = &divVec2i;
    self.divv = &divvVec2i;
    self.len = &lenVec2i;
    self.str = &strVec2i;
    self.norm = &normVec2i;
    self.cross = &crossVec2i;
    self.dot = &dotVec2i;
    return self;
});
;
ceslf(void printVec2i(struct Vec2i a), {
    printf("int"
           "("
           "%d"
           ", "
           "%d"
           ")",
           a.x, a.y);
});
;
struct Vec2f {
    float x, y;
    struct Vec2f (*add)(struct Vec2f, struct Vec2f);
    struct Vec2f (*addv)(struct Vec2f, float);
    struct Vec2f (*sub)(struct Vec2f, struct Vec2f);
    struct Vec2f (*subv)(struct Vec2f, float);
    struct Vec2f (*mul)(struct Vec2f, struct Vec2f);
    struct Vec2f (*mulv)(struct Vec2f, float);
    struct Vec2f (*div)(struct Vec2f, struct Vec2f);
    struct Vec2f (*divv)(struct Vec2f, float);
    float (*len)(struct Vec2f);
    char *(*str)(struct Vec2f);
    struct Vec2f (*norm)(struct Vec2f);
    struct Vec2f (*cross)(struct Vec2f, struct Vec2f);
    float (*dot)(struct Vec2f, struct Vec2f);
};
struct Vec2f newVec2f();
;
ceslf(struct Vec2f addVec2f(struct Vec2f a, struct Vec2f b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2f addvVec2f(struct Vec2f a, float b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x + b;
        v.y = a.y + b;
    };
    return v;
});
;
;
ceslf(struct Vec2f subVec2f(struct Vec2f a, struct Vec2f b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2f subvVec2f(struct Vec2f a, float b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x - b;
        v.y = a.y - b;
    };
    return v;
});
;
;
ceslf(struct Vec2f mulVec2f(struct Vec2f a, struct Vec2f b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2f mulvVec2f(struct Vec2f a, float b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x * b;
        v.y = a.y * b;
    };
    return v;
});
;
;
ceslf(struct Vec2f divVec2f(struct Vec2f a, struct Vec2f b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2f divvVec2f(struct Vec2f a, float b), {
    struct Vec2f v = newVec2f();
    {
        v.x = a.x / b;
        v.y = a.y / b;
    };
    return v;
});
;
;
ceslf(float lenVec2f(struct Vec2f v), { return v.x + v.y; });
ceslf(char *strVec2f(struct Vec2f v), {
    int length = snprintf(NULL, 0,
                          "float"
                          "("
                          "%f"
                          ", "
                          "%f"
                          ")",
                          v.x, v.y);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "float"
             "("
             "%f"
             ", "
             "%f"
             ")",
             v.x, v.y);
    return str;
});
;
ceslf(struct Vec2f normVec2f(struct Vec2f v), { return v.divv(v, v.len(v)); });
;
ceslf(float dotVec2f(struct Vec2f a, struct Vec2f b),
      { return a.x * b.x + a.y * b.y; });
ceslf(struct Vec2f crossVec2f(struct Vec2f a, struct Vec2f b), {
    struct Vec2f v = newVec2f();
    v.x = a.x * b.y - a.y * b.x;
    v.y = a.y * b.x - a.x * b.y;
    return v;
});
ceslf(struct Vec2f newVec2f(), {
    struct Vec2f self;
    {
        self.x = 0;
        self.y = 0;
    };
    self.add = &addVec2f;
    self.addv = &addvVec2f;
    self.sub = &subVec2f;
    self.subv = &subvVec2f;
    self.mul = &mulVec2f;
    self.mulv = &mulvVec2f;
    self.div = &divVec2f;
    self.divv = &divvVec2f;
    self.len = &lenVec2f;
    self.str = &strVec2f;
    self.norm = &normVec2f;
    self.cross = &crossVec2f;
    self.dot = &dotVec2f;
    return self;
});
;
ceslf(struct Vec2f initVec2f(float x, float y), {
    struct Vec2f self;
    {
        self.x = x;
        self.y = y;
    };
    self.add = &addVec2f;
    self.addv = &addvVec2f;
    self.sub = &subVec2f;
    self.subv = &subvVec2f;
    self.mul = &mulVec2f;
    self.mulv = &mulvVec2f;
    self.div = &divVec2f;
    self.divv = &divvVec2f;
    self.len = &lenVec2f;
    self.str = &strVec2f;
    self.norm = &normVec2f;
    self.cross = &crossVec2f;
    self.dot = &dotVec2f;
    return self;
});
;
ceslf(void printVec2f(struct Vec2f a), {
    printf("float"
           "("
           "%f"
           ", "
           "%f"
           ")",
           a.x, a.y);
});
;
struct Vec2 {
    double x, y;
    struct Vec2 (*add)(struct Vec2, struct Vec2);
    struct Vec2 (*addv)(struct Vec2, double);
    struct Vec2 (*sub)(struct Vec2, struct Vec2);
    struct Vec2 (*subv)(struct Vec2, double);
    struct Vec2 (*mul)(struct Vec2, struct Vec2);
    struct Vec2 (*mulv)(struct Vec2, double);
    struct Vec2 (*div)(struct Vec2, struct Vec2);
    struct Vec2 (*divv)(struct Vec2, double);
    double (*len)(struct Vec2);
    char *(*str)(struct Vec2);
    struct Vec2 (*norm)(struct Vec2);
    struct Vec2 (*cross)(struct Vec2, struct Vec2);
    double (*dot)(struct Vec2, struct Vec2);
};
struct Vec2 newVec2();
;
ceslf(struct Vec2 addVec2(struct Vec2 a, struct Vec2 b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2 addvVec2(struct Vec2 a, double b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x + b;
        v.y = a.y + b;
    };
    return v;
});
;
;
ceslf(struct Vec2 subVec2(struct Vec2 a, struct Vec2 b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2 subvVec2(struct Vec2 a, double b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x - b;
        v.y = a.y - b;
    };
    return v;
});
;
;
ceslf(struct Vec2 mulVec2(struct Vec2 a, struct Vec2 b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2 mulvVec2(struct Vec2 a, double b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x * b;
        v.y = a.y * b;
    };
    return v;
});
;
;
ceslf(struct Vec2 divVec2(struct Vec2 a, struct Vec2 b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
    };
    return v;
});
;
;
ceslf(struct Vec2 divvVec2(struct Vec2 a, double b), {
    struct Vec2 v = newVec2();
    {
        v.x = a.x / b;
        v.y = a.y / b;
    };
    return v;
});
;
;
ceslf(double lenVec2(struct Vec2 v), { return v.x + v.y; });
ceslf(char *strVec2(struct Vec2 v), {
    int length = snprintf(NULL, 0,
                          "double"
                          "("
                          "%lf"
                          ", "
                          "%lf"
                          ")",
                          v.x, v.y);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "double"
             "("
             "%lf"
             ", "
             "%lf"
             ")",
             v.x, v.y);
    return str;
});
;
ceslf(struct Vec2 normVec2(struct Vec2 v), { return v.divv(v, v.len(v)); });
;
ceslf(double dotVec2(struct Vec2 a, struct Vec2 b),
      { return a.x * b.x + a.y * b.y; });
ceslf(struct Vec2 crossVec2(struct Vec2 a, struct Vec2 b), {
    struct Vec2 v = newVec2();
    v.x = a.x * b.y - a.y * b.x;
    v.y = a.y * b.x - a.x * b.y;
    return v;
});
ceslf(struct Vec2 newVec2(), {
    struct Vec2 self;
    {
        self.x = 0;
        self.y = 0;
    };
    self.add = &addVec2;
    self.addv = &addvVec2;
    self.sub = &subVec2;
    self.subv = &subvVec2;
    self.mul = &mulVec2;
    self.mulv = &mulvVec2;
    self.div = &divVec2;
    self.divv = &divvVec2;
    self.len = &lenVec2;
    self.str = &strVec2;
    self.norm = &normVec2;
    self.cross = &crossVec2;
    self.dot = &dotVec2;
    return self;
});
;
ceslf(struct Vec2 initVec2(double x, double y), {
    struct Vec2 self;
    {
        self.x = x;
        self.y = y;
    };
    self.add = &addVec2;
    self.addv = &addvVec2;
    self.sub = &subVec2;
    self.subv = &subvVec2;
    self.mul = &mulVec2;
    self.mulv = &mulvVec2;
    self.div = &divVec2;
    self.divv = &divvVec2;
    self.len = &lenVec2;
    self.str = &strVec2;
    self.norm = &normVec2;
    self.cross = &crossVec2;
    self.dot = &dotVec2;
    return self;
});
;
ceslf(void printVec2(struct Vec2 a), {
    printf("double"
           "("
           "%lf"
           ", "
           "%lf"
           ")",
           a.x, a.y);
});
;

struct Vec3i {
    int x, y, z;
    struct Vec3i (*add)(struct Vec3i, struct Vec3i);
    struct Vec3i (*addv)(struct Vec3i, int);
    struct Vec3i (*sub)(struct Vec3i, struct Vec3i);
    struct Vec3i (*subv)(struct Vec3i, int);
    struct Vec3i (*mul)(struct Vec3i, struct Vec3i);
    struct Vec3i (*mulv)(struct Vec3i, int);
    struct Vec3i (*div)(struct Vec3i, struct Vec3i);
    struct Vec3i (*divv)(struct Vec3i, int);
    int (*len)(struct Vec3i);
    char *(*str)(struct Vec3i);
    struct Vec3i (*norm)(struct Vec3i);
    struct Vec3i (*cross)(struct Vec3i, struct Vec3i);
    int (*dot)(struct Vec3i, struct Vec3i);
};
struct Vec3i newVec3i();
;
ceslf(struct Vec3i addVec3i(struct Vec3i a, struct Vec3i b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3i addvVec3i(struct Vec3i a, int b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
    };
    return v;
});
;
;
ceslf(struct Vec3i subVec3i(struct Vec3i a, struct Vec3i b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3i subvVec3i(struct Vec3i a, int b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
    };
    return v;
});
;
;
ceslf(struct Vec3i mulVec3i(struct Vec3i a, struct Vec3i b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3i mulvVec3i(struct Vec3i a, int b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
    };
    return v;
});
;
;
ceslf(struct Vec3i divVec3i(struct Vec3i a, struct Vec3i b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3i divvVec3i(struct Vec3i a, int b), {
    struct Vec3i v = newVec3i();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
    };
    return v;
});
;
;
ceslf(int lenVec3i(struct Vec3i v), { return v.x + v.y + v.z; });
ceslf(char *strVec3i(struct Vec3i v), {
    int length = snprintf(NULL, 0,
                          "int"
                          "("
                          "%d"
                          ", "
                          "%d"
                          ", "
                          "%d"
                          ")",
                          v.x, v.y, v.z);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "int"
             "("
             "%d"
             ", "
             "%d"
             ", "
             "%d"
             ")",
             v.x, v.y, v.z);
    return str;
});
;
ceslf(struct Vec3i normVec3i(struct Vec3i v), { return v.divv(v, v.len(v)); });
;
ceslf(int dotVec3i(struct Vec3i a, struct Vec3i b),
      { return a.x * b.x + a.y * b.y + a.z * b.z; });
ceslf(struct Vec3i crossVec3i(struct Vec3i a, struct Vec3i b), {
    struct Vec3i v = newVec3i();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return v;
});
ceslf(struct Vec3i newVec3i(), {
    struct Vec3i self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
    };
    self.add = &addVec3i;
    self.addv = &addvVec3i;
    self.sub = &subVec3i;
    self.subv = &subvVec3i;
    self.mul = &mulVec3i;
    self.mulv = &mulvVec3i;
    self.div = &divVec3i;
    self.divv = &divvVec3i;
    self.len = &lenVec3i;
    self.str = &strVec3i;
    self.norm = &normVec3i;
    self.cross = &crossVec3i;
    self.dot = &dotVec3i;
    return self;
});
;
ceslf(struct Vec3i initVec3i(int x, int y, int z), {
    struct Vec3i self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
    };
    self.add = &addVec3i;
    self.addv = &addvVec3i;
    self.sub = &subVec3i;
    self.subv = &subvVec3i;
    self.mul = &mulVec3i;
    self.mulv = &mulvVec3i;
    self.div = &divVec3i;
    self.divv = &divvVec3i;
    self.len = &lenVec3i;
    self.str = &strVec3i;
    self.norm = &normVec3i;
    self.cross = &crossVec3i;
    self.dot = &dotVec3i;
    return self;
});
;
ceslf(void printVec3i(struct Vec3i a), {
    printf("int"
           "("
           "%d"
           ", "
           "%d"
           ", "
           "%d"
           ")",
           a.x, a.y, a.z);
});
;
struct Vec3f {
    float x, y, z;
    struct Vec3f (*add)(struct Vec3f, struct Vec3f);
    struct Vec3f (*addv)(struct Vec3f, float);
    struct Vec3f (*sub)(struct Vec3f, struct Vec3f);
    struct Vec3f (*subv)(struct Vec3f, float);
    struct Vec3f (*mul)(struct Vec3f, struct Vec3f);
    struct Vec3f (*mulv)(struct Vec3f, float);
    struct Vec3f (*div)(struct Vec3f, struct Vec3f);
    struct Vec3f (*divv)(struct Vec3f, float);
    float (*len)(struct Vec3f);
    char *(*str)(struct Vec3f);
    struct Vec3f (*norm)(struct Vec3f);
    struct Vec3f (*cross)(struct Vec3f, struct Vec3f);
    float (*dot)(struct Vec3f, struct Vec3f);
};
struct Vec3f newVec3f();
;
ceslf(struct Vec3f addVec3f(struct Vec3f a, struct Vec3f b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3f addvVec3f(struct Vec3f a, float b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
    };
    return v;
});
;
;
ceslf(struct Vec3f subVec3f(struct Vec3f a, struct Vec3f b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3f subvVec3f(struct Vec3f a, float b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
    };
    return v;
});
;
;
ceslf(struct Vec3f mulVec3f(struct Vec3f a, struct Vec3f b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3f mulvVec3f(struct Vec3f a, float b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
    };
    return v;
});
;
;
ceslf(struct Vec3f divVec3f(struct Vec3f a, struct Vec3f b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3f divvVec3f(struct Vec3f a, float b), {
    struct Vec3f v = newVec3f();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
    };
    return v;
});
;
;
ceslf(float lenVec3f(struct Vec3f v), { return v.x + v.y + v.z; });
ceslf(char *strVec3f(struct Vec3f v), {
    int length = snprintf(NULL, 0,
                          "float"
                          "("
                          "%f"
                          ", "
                          "%f"
                          ", "
                          "%f"
                          ")",
                          v.x, v.y, v.z);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "float"
             "("
             "%f"
             ", "
             "%f"
             ", "
             "%f"
             ")",
             v.x, v.y, v.z);
    return str;
});
;
ceslf(struct Vec3f normVec3f(struct Vec3f v), { return v.divv(v, v.len(v)); });
;
ceslf(float dotVec3f(struct Vec3f a, struct Vec3f b),
      { return a.x * b.x + a.y * b.y + a.z * b.z; });
ceslf(struct Vec3f crossVec3f(struct Vec3f a, struct Vec3f b), {
    struct Vec3f v = newVec3f();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return v;
});
ceslf(struct Vec3f newVec3f(), {
    struct Vec3f self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
    };
    self.add = &addVec3f;
    self.addv = &addvVec3f;
    self.sub = &subVec3f;
    self.subv = &subvVec3f;
    self.mul = &mulVec3f;
    self.mulv = &mulvVec3f;
    self.div = &divVec3f;
    self.divv = &divvVec3f;
    self.len = &lenVec3f;
    self.str = &strVec3f;
    self.norm = &normVec3f;
    self.cross = &crossVec3f;
    self.dot = &dotVec3f;
    return self;
});
;
ceslf(struct Vec3f initVec3f(float x, float y, float z), {
    struct Vec3f self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
    };
    self.add = &addVec3f;
    self.addv = &addvVec3f;
    self.sub = &subVec3f;
    self.subv = &subvVec3f;
    self.mul = &mulVec3f;
    self.mulv = &mulvVec3f;
    self.div = &divVec3f;
    self.divv = &divvVec3f;
    self.len = &lenVec3f;
    self.str = &strVec3f;
    self.norm = &normVec3f;
    self.cross = &crossVec3f;
    self.dot = &dotVec3f;
    return self;
});
;
ceslf(void printVec3f(struct Vec3f a), {
    printf("float"
           "("
           "%f"
           ", "
           "%f"
           ", "
           "%f"
           ")",
           a.x, a.y, a.z);
});
;
struct Vec3 {
    double x, y, z;
    struct Vec3 (*add)(struct Vec3, struct Vec3);
    struct Vec3 (*addv)(struct Vec3, double);
    struct Vec3 (*sub)(struct Vec3, struct Vec3);
    struct Vec3 (*subv)(struct Vec3, double);
    struct Vec3 (*mul)(struct Vec3, struct Vec3);
    struct Vec3 (*mulv)(struct Vec3, double);
    struct Vec3 (*div)(struct Vec3, struct Vec3);
    struct Vec3 (*divv)(struct Vec3, double);
    double (*len)(struct Vec3);
    char *(*str)(struct Vec3);
    struct Vec3 (*norm)(struct Vec3);
    struct Vec3 (*cross)(struct Vec3, struct Vec3);
    double (*dot)(struct Vec3, struct Vec3);
};
struct Vec3 newVec3();
;
ceslf(struct Vec3 addVec3(struct Vec3 a, struct Vec3 b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3 addvVec3(struct Vec3 a, double b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
    };
    return v;
});
;
;
ceslf(struct Vec3 subVec3(struct Vec3 a, struct Vec3 b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3 subvVec3(struct Vec3 a, double b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
    };
    return v;
});
;
;
ceslf(struct Vec3 mulVec3(struct Vec3 a, struct Vec3 b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3 mulvVec3(struct Vec3 a, double b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
    };
    return v;
});
;
;
ceslf(struct Vec3 divVec3(struct Vec3 a, struct Vec3 b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
    };
    return v;
});
;
;
ceslf(struct Vec3 divvVec3(struct Vec3 a, double b), {
    struct Vec3 v = newVec3();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
    };
    return v;
});
;
;
ceslf(double lenVec3(struct Vec3 v), { return v.x + v.y + v.z; });
ceslf(char *strVec3(struct Vec3 v), {
    int length = snprintf(NULL, 0,
                          "double"
                          "("
                          "%lf"
                          ", "
                          "%lf"
                          ", "
                          "%lf"
                          ")",
                          v.x, v.y, v.z);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "double"
             "("
             "%lf"
             ", "
             "%lf"
             ", "
             "%lf"
             ")",
             v.x, v.y, v.z);
    return str;
});
;
ceslf(struct Vec3 normVec3(struct Vec3 v), { return v.divv(v, v.len(v)); });
;
ceslf(double dotVec3(struct Vec3 a, struct Vec3 b),
      { return a.x * b.x + a.y * b.y + a.z * b.z; });
ceslf(struct Vec3 crossVec3(struct Vec3 a, struct Vec3 b), {
    struct Vec3 v = newVec3();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return v;
});
ceslf(struct Vec3 newVec3(), {
    struct Vec3 self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
    };
    self.add = &addVec3;
    self.addv = &addvVec3;
    self.sub = &subVec3;
    self.subv = &subvVec3;
    self.mul = &mulVec3;
    self.mulv = &mulvVec3;
    self.div = &divVec3;
    self.divv = &divvVec3;
    self.len = &lenVec3;
    self.str = &strVec3;
    self.norm = &normVec3;
    self.cross = &crossVec3;
    self.dot = &dotVec3;
    return self;
});
;
ceslf(struct Vec3 initVec3(double x, double y, double z), {
    struct Vec3 self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
    };
    self.add = &addVec3;
    self.addv = &addvVec3;
    self.sub = &subVec3;
    self.subv = &subvVec3;
    self.mul = &mulVec3;
    self.mulv = &mulvVec3;
    self.div = &divVec3;
    self.divv = &divvVec3;
    self.len = &lenVec3;
    self.str = &strVec3;
    self.norm = &normVec3;
    self.cross = &crossVec3;
    self.dot = &dotVec3;
    return self;
});
;
ceslf(void printVec3(struct Vec3 a), {
    printf("double"
           "("
           "%lf"
           ", "
           "%lf"
           ", "
           "%lf"
           ")",
           a.x, a.y, a.z);
});
;

struct Vec4i {
    int x, y, z, w;
    struct Vec4i (*add)(struct Vec4i, struct Vec4i);
    struct Vec4i (*addv)(struct Vec4i, int);
    struct Vec4i (*sub)(struct Vec4i, struct Vec4i);
    struct Vec4i (*subv)(struct Vec4i, int);
    struct Vec4i (*mul)(struct Vec4i, struct Vec4i);
    struct Vec4i (*mulv)(struct Vec4i, int);
    struct Vec4i (*div)(struct Vec4i, struct Vec4i);
    struct Vec4i (*divv)(struct Vec4i, int);
    int (*len)(struct Vec4i);
    char *(*str)(struct Vec4i);
    struct Vec4i (*norm)(struct Vec4i);
    struct Vec4i (*cross)(struct Vec4i, struct Vec4i);
    int (*dot)(struct Vec4i, struct Vec4i);
};
struct Vec4i newVec4i();
;
ceslf(struct Vec4i addVec4i(struct Vec4i a, struct Vec4i b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
        v.w = a.w + b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4i addvVec4i(struct Vec4i a, int b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
        v.w = a.w + b;
    };
    return v;
});
;
;
ceslf(struct Vec4i subVec4i(struct Vec4i a, struct Vec4i b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
        v.w = a.w - b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4i subvVec4i(struct Vec4i a, int b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
        v.w = a.w - b;
    };
    return v;
});
;
;
ceslf(struct Vec4i mulVec4i(struct Vec4i a, struct Vec4i b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
        v.w = a.w * b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4i mulvVec4i(struct Vec4i a, int b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
        v.w = a.w * b;
    };
    return v;
});
;
;
ceslf(struct Vec4i divVec4i(struct Vec4i a, struct Vec4i b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
        v.w = a.w / b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4i divvVec4i(struct Vec4i a, int b), {
    struct Vec4i v = newVec4i();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
        v.w = a.w / b;
    };
    return v;
});
;
;
ceslf(int lenVec4i(struct Vec4i v), { return v.x + v.y + v.z + v.w; });
ceslf(char *strVec4i(struct Vec4i v), {
    int length = snprintf(NULL, 0,
                          "int"
                          "("
                          "%d"
                          ", "
                          "%d"
                          ", "
                          "%d"
                          ", "
                          "%d"
                          ")",
                          v.x, v.y, v.z, v.w);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "int"
             "("
             "%d"
             ", "
             "%d"
             ", "
             "%d"
             ", "
             "%d"
             ")",
             v.x, v.y, v.z, v.w);
    return str;
});
;
ceslf(struct Vec4i normVec4i(struct Vec4i v), { return v.divv(v, v.len(v)); });
;
ceslf(int dotVec4i(struct Vec4i a, struct Vec4i b),
      { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; });
ceslf(struct Vec4i crossVec4i(struct Vec4i a, struct Vec4i b), {
    struct Vec4i v = newVec4i();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    v.w = 0;
    return v;
});
ceslf(struct Vec4i newVec4i(), {
    struct Vec4i self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
        self.w = 0;
    };
    self.add = &addVec4i;
    self.addv = &addvVec4i;
    self.sub = &subVec4i;
    self.subv = &subvVec4i;
    self.mul = &mulVec4i;
    self.mulv = &mulvVec4i;
    self.div = &divVec4i;
    self.divv = &divvVec4i;
    self.len = &lenVec4i;
    self.str = &strVec4i;
    self.norm = &normVec4i;
    self.cross = &crossVec4i;
    self.dot = &dotVec4i;
    return self;
});
;
ceslf(struct Vec4i initwVec4i(int x, int y, int z, int w), {
    struct Vec4i self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = w;
    };
    self.add = &addVec4i;
    self.addv = &addvVec4i;
    self.sub = &subVec4i;
    self.subv = &subvVec4i;
    self.mul = &mulVec4i;
    self.mulv = &mulvVec4i;
    self.div = &divVec4i;
    self.divv = &divvVec4i;
    self.len = &lenVec4i;
    self.str = &strVec4i;
    self.norm = &normVec4i;
    self.cross = &crossVec4i;
    self.dot = &dotVec4i;
    return self;
});
;
ceslf(struct Vec4i initVec4i(int x, int y, int z), {
    struct Vec4i self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = 0;
    };
    self.add = &addVec4i;
    self.addv = &addvVec4i;
    self.sub = &subVec4i;
    self.subv = &subvVec4i;
    self.mul = &mulVec4i;
    self.mulv = &mulvVec4i;
    self.div = &divVec4i;
    self.divv = &divvVec4i;
    self.len = &lenVec4i;
    self.str = &strVec4i;
    self.norm = &normVec4i;
    self.cross = &crossVec4i;
    self.dot = &dotVec4i;
    return self;
});
;
ceslf(void printVec4i(struct Vec4i a), {
    printf("int"
           "("
           "%d"
           ", "
           "%d"
           ", "
           "%d"
           ", "
           "%d"
           ")",
           a.x, a.y, a.z, a.w);
});
;
struct Vec4f {
    float x, y, z, w;
    struct Vec4f (*add)(struct Vec4f, struct Vec4f);
    struct Vec4f (*addv)(struct Vec4f, float);
    struct Vec4f (*sub)(struct Vec4f, struct Vec4f);
    struct Vec4f (*subv)(struct Vec4f, float);
    struct Vec4f (*mul)(struct Vec4f, struct Vec4f);
    struct Vec4f (*mulv)(struct Vec4f, float);
    struct Vec4f (*div)(struct Vec4f, struct Vec4f);
    struct Vec4f (*divv)(struct Vec4f, float);
    float (*len)(struct Vec4f);
    char *(*str)(struct Vec4f);
    struct Vec4f (*norm)(struct Vec4f);
    struct Vec4f (*cross)(struct Vec4f, struct Vec4f);
    float (*dot)(struct Vec4f, struct Vec4f);
};
struct Vec4f newVec4f();
;
ceslf(struct Vec4f addVec4f(struct Vec4f a, struct Vec4f b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
        v.w = a.w + b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4f addvVec4f(struct Vec4f a, float b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
        v.w = a.w + b;
    };
    return v;
});
;
;
ceslf(struct Vec4f subVec4f(struct Vec4f a, struct Vec4f b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
        v.w = a.w - b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4f subvVec4f(struct Vec4f a, float b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
        v.w = a.w - b;
    };
    return v;
});
;
;
ceslf(struct Vec4f mulVec4f(struct Vec4f a, struct Vec4f b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
        v.w = a.w * b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4f mulvVec4f(struct Vec4f a, float b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
        v.w = a.w * b;
    };
    return v;
});
;
;
ceslf(struct Vec4f divVec4f(struct Vec4f a, struct Vec4f b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
        v.w = a.w / b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4f divvVec4f(struct Vec4f a, float b), {
    struct Vec4f v = newVec4f();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
        v.w = a.w / b;
    };
    return v;
});
;
;
ceslf(float lenVec4f(struct Vec4f v), { return v.x + v.y + v.z + v.w; });
ceslf(char *strVec4f(struct Vec4f v), {
    int length = snprintf(NULL, 0,
                          "float"
                          "("
                          "%f"
                          ", "
                          "%f"
                          ", "
                          "%f"
                          ", "
                          "%f"
                          ")",
                          v.x, v.y, v.z, v.w);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "float"
             "("
             "%f"
             ", "
             "%f"
             ", "
             "%f"
             ", "
             "%f"
             ")",
             v.x, v.y, v.z, v.w);
    return str;
});
;
ceslf(struct Vec4f normVec4f(struct Vec4f v), { return v.divv(v, v.len(v)); });
;
ceslf(float dotVec4f(struct Vec4f a, struct Vec4f b),
      { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; });
ceslf(struct Vec4f crossVec4f(struct Vec4f a, struct Vec4f b), {
    struct Vec4f v = newVec4f();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    v.w = 0;
    return v;
});
ceslf(struct Vec4f newVec4f(), {
    struct Vec4f self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
        self.w = 0;
    };
    self.add = &addVec4f;
    self.addv = &addvVec4f;
    self.sub = &subVec4f;
    self.subv = &subvVec4f;
    self.mul = &mulVec4f;
    self.mulv = &mulvVec4f;
    self.div = &divVec4f;
    self.divv = &divvVec4f;
    self.len = &lenVec4f;
    self.str = &strVec4f;
    self.norm = &normVec4f;
    self.cross = &crossVec4f;
    self.dot = &dotVec4f;
    return self;
});
;
ceslf(struct Vec4f initwVec4f(float x, float y, float z, float w), {
    struct Vec4f self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = w;
    };
    self.add = &addVec4f;
    self.addv = &addvVec4f;
    self.sub = &subVec4f;
    self.subv = &subvVec4f;
    self.mul = &mulVec4f;
    self.mulv = &mulvVec4f;
    self.div = &divVec4f;
    self.divv = &divvVec4f;
    self.len = &lenVec4f;
    self.str = &strVec4f;
    self.norm = &normVec4f;
    self.cross = &crossVec4f;
    self.dot = &dotVec4f;
    return self;
});
;
ceslf(struct Vec4f initVec4f(float x, float y, float z), {
    struct Vec4f self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = 0;
    };
    self.add = &addVec4f;
    self.addv = &addvVec4f;
    self.sub = &subVec4f;
    self.subv = &subvVec4f;
    self.mul = &mulVec4f;
    self.mulv = &mulvVec4f;
    self.div = &divVec4f;
    self.divv = &divvVec4f;
    self.len = &lenVec4f;
    self.str = &strVec4f;
    self.norm = &normVec4f;
    self.cross = &crossVec4f;
    self.dot = &dotVec4f;
    return self;
});
;
ceslf(void printVec4f(struct Vec4f a), {
    printf("float"
           "("
           "%f"
           ", "
           "%f"
           ", "
           "%f"
           ", "
           "%f"
           ")",
           a.x, a.y, a.z, a.w);
});
;
struct Vec4 {
    double x, y, z, w;
    struct Vec4 (*add)(struct Vec4, struct Vec4);
    struct Vec4 (*addv)(struct Vec4, double);
    struct Vec4 (*sub)(struct Vec4, struct Vec4);
    struct Vec4 (*subv)(struct Vec4, double);
    struct Vec4 (*mul)(struct Vec4, struct Vec4);
    struct Vec4 (*mulv)(struct Vec4, double);
    struct Vec4 (*div)(struct Vec4, struct Vec4);
    struct Vec4 (*divv)(struct Vec4, double);
    double (*len)(struct Vec4);
    char *(*str)(struct Vec4);
    struct Vec4 (*norm)(struct Vec4);
    struct Vec4 (*cross)(struct Vec4, struct Vec4);
    double (*dot)(struct Vec4, struct Vec4);
};
struct Vec4 newVec4();
;
ceslf(struct Vec4 addVec4(struct Vec4 a, struct Vec4 b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        v.z = a.z + b.z;
        v.w = a.w + b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4 addvVec4(struct Vec4 a, double b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x + b;
        v.y = a.y + b;
        v.z = a.z + b;
        v.w = a.w + b;
    };
    return v;
});
;
;
ceslf(struct Vec4 subVec4(struct Vec4 a, struct Vec4 b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v.z = a.z - b.z;
        v.w = a.w - b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4 subvVec4(struct Vec4 a, double b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x - b;
        v.y = a.y - b;
        v.z = a.z - b;
        v.w = a.w - b;
    };
    return v;
});
;
;
ceslf(struct Vec4 mulVec4(struct Vec4 a, struct Vec4 b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x * b.x;
        v.y = a.y * b.y;
        v.z = a.z * b.z;
        v.w = a.w * b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4 mulvVec4(struct Vec4 a, double b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x * b;
        v.y = a.y * b;
        v.z = a.z * b;
        v.w = a.w * b;
    };
    return v;
});
;
;
ceslf(struct Vec4 divVec4(struct Vec4 a, struct Vec4 b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x / b.x;
        v.y = a.y / b.y;
        v.z = a.z / b.z;
        v.w = a.w / b.w;
    };
    return v;
});
;
;
ceslf(struct Vec4 divvVec4(struct Vec4 a, double b), {
    struct Vec4 v = newVec4();
    {
        v.x = a.x / b;
        v.y = a.y / b;
        v.z = a.z / b;
        v.w = a.w / b;
    };
    return v;
});
;
;
ceslf(double lenVec4(struct Vec4 v), { return v.x + v.y + v.z + v.w; });
ceslf(char *strVec4(struct Vec4 v), {
    int length = snprintf(NULL, 0,
                          "double"
                          "("
                          "%lf"
                          ", "
                          "%lf"
                          ", "
                          "%lf"
                          ", "
                          "%lf"
                          ")",
                          v.x, v.y, v.z, v.w);
    char *str = (char *)malloc(sizeof(char) * (length + 1));
    snprintf(str, length + 1,
             "double"
             "("
             "%lf"
             ", "
             "%lf"
             ", "
             "%lf"
             ", "
             "%lf"
             ")",
             v.x, v.y, v.z, v.w);
    return str;
});
;
ceslf(struct Vec4 normVec4(struct Vec4 v), { return v.divv(v, v.len(v)); });
;
ceslf(double dotVec4(struct Vec4 a, struct Vec4 b),
      { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; });
ceslf(struct Vec4 crossVec4(struct Vec4 a, struct Vec4 b), {
    struct Vec4 v = newVec4();
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    v.w = 0;
    return v;
});
ceslf(struct Vec4 newVec4(), {
    struct Vec4 self;
    {
        self.x = 0;
        self.y = 0;
        self.z = 0;
        self.w = 0;
    };
    self.add = &addVec4;
    self.addv = &addvVec4;
    self.sub = &subVec4;
    self.subv = &subvVec4;
    self.mul = &mulVec4;
    self.mulv = &mulvVec4;
    self.div = &divVec4;
    self.divv = &divvVec4;
    self.len = &lenVec4;
    self.str = &strVec4;
    self.norm = &normVec4;
    self.cross = &crossVec4;
    self.dot = &dotVec4;
    return self;
});
;
ceslf(struct Vec4 initwVec4(double x, double y, double z, double w), {
    struct Vec4 self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = w;
    };
    self.add = &addVec4;
    self.addv = &addvVec4;
    self.sub = &subVec4;
    self.subv = &subvVec4;
    self.mul = &mulVec4;
    self.mulv = &mulvVec4;
    self.div = &divVec4;
    self.divv = &divvVec4;
    self.len = &lenVec4;
    self.str = &strVec4;
    self.norm = &normVec4;
    self.cross = &crossVec4;
    self.dot = &dotVec4;
    return self;
});
;
ceslf(struct Vec4 initVec4(double x, double y, double z), {
    struct Vec4 self;
    {
        self.x = x;
        self.y = y;
        self.z = z;
        self.w = 0;
    };
    self.add = &addVec4;
    self.addv = &addvVec4;
    self.sub = &subVec4;
    self.subv = &subvVec4;
    self.mul = &mulVec4;
    self.mulv = &mulvVec4;
    self.div = &divVec4;
    self.divv = &divvVec4;
    self.len = &lenVec4;
    self.str = &strVec4;
    self.norm = &normVec4;
    self.cross = &crossVec4;
    self.dot = &dotVec4;
    return self;
});
;
ceslf(void printVec4(struct Vec4 a), {
    printf("double"
           "("
           "%lf"
           ", "
           "%lf"
           ", "
           "%lf"
           ", "
           "%lf"
           ")",
           a.x, a.y, a.z, a.w);
});
;

// a + b = addVec3i(a, b) or a->add(a, b) or b->add(a, b)...
