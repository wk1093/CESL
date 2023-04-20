// Vector Math
#include "arr.h"
#include <stdio.h>
#include <stdlib.h>

#define cvec(name, type, ...)                                                  \
    struct name {                                                              \
        type __VA_ARGS__;                                                      \
        struct name (*add)(struct name, struct name);                          \
        struct name (*addv)(struct name, type);                                \
        struct name (*sub)(struct name, struct name);                          \
        struct name (*subv)(struct name, type);                                \
        struct name (*mul)(struct name, struct name);                          \
        struct name (*mulv)(struct name, type);                                \
        struct name (*div)(struct name, struct name);                          \
        struct name (*divv)(struct name, type);                                \
        type (*len)(struct name);                                              \
        char *(*str)(struct name);                                             \
        struct name (*norm)(struct name);                                      \
        struct name (*cross)(struct name, struct name);                        \
        type (*dot)(struct name, struct name);                                 \
    };                                                                         \
    struct name new##name();

#define cvecun(n, name, func)                                                  \
    struct name n##name(struct name a, struct name b) {                        \
        struct name v = new##name();                                           \
        func;                                                                  \
        return v;                                                              \
    }

#define cvecd(n, name, args, newf)                                             \
    struct name n##name##args {                                                \
        struct name self;                                                      \
        newf;                                                                  \
        self.add = &add##name;                                                 \
        self.addv = &addv##name;                                               \
        self.sub = &sub##name;                                                 \
        self.subv = &subv##name;                                               \
        self.mul = &mul##name;                                                 \
        self.mulv = &mulv##name;                                               \
        self.div = &div##name;                                                 \
        self.divv = &divv##name;                                               \
        self.len = &len##name;                                                 \
        self.str = &str##name;                                                 \
        self.norm = &norm##name;                                               \
        self.cross = &cross##name;                                             \
        self.dot = &dot##name;                                                 \
        return self;                                                           \
    }

#define cvect(n, name, type, newf)                                             \
    struct name n##name(struct name a, type b) {                               \
        struct name v = new##name();                                           \
        newf;                                                                  \
        return v;                                                              \
    }

#define vecstr(name, type, stri, ...)                                          \
    char *str##name(struct name v) {                                           \
        int length = snprintf(NULL, 0, #type stri, __VA_ARGS__);               \
        char *str = (char *)malloc(sizeof(char) * (length + 1));               \
        snprintf(str, length + 1, #type stri, __VA_ARGS__);                    \
        return str;                                                            \
    }

#define vecnorm(name)                                                          \
    struct name norm##name(struct name v) { return v.divv(v, v.len(v)); }

#define __vec2_t2(n, name, type, op)                                           \
    cvect(n, name, type, {                                                     \
        v.x = a.x op b;                                                        \
        v.y = a.y op b;                                                        \
    });

#define __vec2_t(t, name, op)                                                  \
    cvecun(t, name, {                                                          \
        v.x = a.x op b.x;                                                      \
        v.y = a.y op b.y;                                                      \
    });
#define __vec2(type, name, formet)                                             \
    cvec(name, type, x, y);                                                    \
    __vec2_t(add, name, +);                                                    \
    __vec2_t2(addv, name, type, +);                                            \
    __vec2_t(sub, name, -);                                                    \
    __vec2_t2(subv, name, type, -);                                            \
    __vec2_t(mul, name, *);                                                    \
    __vec2_t2(mulv, name, type, *);                                            \
    __vec2_t(div, name, /);                                                    \
    __vec2_t2(divv, name, type, /);                                            \
    type len##name(struct name v) { return v.x + v.y; }                        \
    vecstr(name, type, "(" formet ", " formet ")", v.x, v.y);                  \
    vecnorm(name);                                                             \
    type dot##name(struct name a, struct name b) {                             \
        return a.x * b.x + a.y * b.y;                                          \
    }                                                                          \
    struct name cross##name(struct name a, struct name b) {                    \
        struct name v = new##name();                                           \
        v.x = a.x * b.y - a.y * b.x;                                           \
        v.y = a.y * b.x - a.x * b.y;                                           \
        return v;                                                              \
    }                                                                          \
    cvecd(new, name, (), {                                                     \
        self.x = 0;                                                            \
        self.y = 0;                                                            \
    });                                                                        \
    cvecd(init, name, (type x, type y), {                                      \
        self.x = x;                                                            \
        self.y = y;                                                            \
    });                                                                        \
    void print##name(struct name a) {                                          \
        printf(#type "(" formet ", " formet ")", a.x, a.y);                    \
    }

#define __vec3_t(t, name, op)                                                  \
    cvecun(t, name, {                                                          \
        v.x = a.x op b.x;                                                      \
        v.y = a.y op b.y;                                                      \
        v.z = a.z op b.z;                                                      \
    });
#define __vec3_t2(n, name, type, op)                                           \
    cvect(n, name, type, {                                                     \
        v.x = a.x op b;                                                        \
        v.y = a.y op b;                                                        \
        v.z = a.z op b;                                                        \
    });
#define __vec3(type, name, formet)                                             \
    cvec(name, type, x, y, z);                                                 \
    __vec3_t(add, name, +);                                                    \
    __vec3_t2(addv, name, type, +);                                            \
    __vec3_t(sub, name, -);                                                    \
    __vec3_t2(subv, name, type, -);                                            \
    __vec3_t(mul, name, *);                                                    \
    __vec3_t2(mulv, name, type, *);                                            \
    __vec3_t(div, name, /);                                                    \
    __vec3_t2(divv, name, type, /);                                            \
    type len##name(struct name v) { return v.x + v.y + v.z; }                  \
    vecstr(name, type, "(" formet ", " formet ", " formet ")", v.x, v.y, v.z); \
    vecnorm(name);                                                             \
    type dot##name(struct name a, struct name b) {                             \
        return a.x * b.x + a.y * b.y + a.z * b.z;                              \
    }                                                                          \
    struct name cross##name(struct name a, struct name b) {                    \
        struct name v = new##name();                                           \
        v.x = a.y * b.z - a.z * b.y;                                           \
        v.y = a.z * b.x - a.x * b.z;                                           \
        v.z = a.x * b.y - a.y * b.x;                                           \
        return v;                                                              \
    }                                                                          \
    cvecd(new, name, (), {                                                     \
        self.x = 0;                                                            \
        self.y = 0;                                                            \
        self.z = 0;                                                            \
    });                                                                        \
    cvecd(init, name, (type x, type y, type z), {                              \
        self.x = x;                                                            \
        self.y = y;                                                            \
        self.z = z;                                                            \
    });                                                                        \
    void print##name(struct name a) {                                          \
        printf(#type "(" formet ", " formet ", " formet ")", a.x, a.y, a.z);   \
    }

__vec2(int, Vec2i, "%d");
__vec2(float, Vec2f, "%f");
__vec2(double, Vec2, "%lf");

__vec3(int, Vec3i, "%d");
__vec3(float, Vec3f, "%f");
__vec3(double, Vec3, "%lf");

// a + b = addVec3i(a, b) or a->add(a, b) or b->add(a, b)...