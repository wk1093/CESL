#pragma once
#include "ceslimpl.h"
#include "vec.h"
// CESL (C Extended Standard Library) Matrix Math

struct Mat4f {
    float m[4][4];

    // "member" functions
    struct Mat4f (*add)(struct Mat4f, struct Mat4f);
    struct Mat4f (*sub)(struct Mat4f, struct Mat4f);
    struct Mat4f (*mul)(struct Mat4f, struct Mat4f);
    struct Mat4f (*addv)(struct Mat4f, struct Vec4f);
    struct Mat4f (*subv)(struct Mat4f, struct Vec4f);
    struct Mat4f (*mulv)(struct Mat4f, struct Vec4f);
    struct Mat4f (*divv)(struct Mat4f, struct Vec4f);

    struct Mat4f (*addf)(struct Mat4f, float);
    struct Mat4f (*subf)(struct Mat4f, float);
    struct Mat4f (*mulf)(struct Mat4f, float);
    struct Mat4f (*divf)(struct Mat4f, float);

    struct Mat4f (*identity)();
    struct Mat4f (*transpose)(struct Mat4f);
    struct Mat4f (*inverse)(struct Mat4f);
    struct Mat4f (*translate)(struct Mat4f, struct Vec3f);
    struct Mat4f (*scale)(struct Mat4f, struct Vec3f);
    struct Mat4f (*rotate)(struct Mat4f, float, struct Vec3f);
    struct Mat4f (*perspective)(float, float, float, float);
    struct Mat4f (*ortho)(float, float, float, float, float, float);
    struct Mat4f (*lookAt)(struct Vec3f, struct Vec3f, struct Vec3f);
};
struct Mat4f newMat4f(); // must always be called to initialize the struct,
                         // otherwise the "member" functions will be NULL

ceslf(struct Mat4f addMat4f(struct Mat4f a, struct Mat4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
    return result;
});

ceslf(struct Mat4f subMat4f(struct Mat4f a, struct Mat4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
    return result;
});

ceslf(struct Mat4f mulMat4f(struct Mat4f a, struct Mat4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] +
                             a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j];
        }
    }
    return result;
});

ceslf(struct Mat4f addvMat4f(struct Mat4f a, struct Vec4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        result.m[i][0] = a.m[i][0] + b.x;
        result.m[i][1] = a.m[i][1] + b.y;
        result.m[i][2] = a.m[i][2] + b.z;
        result.m[i][3] = a.m[i][3] + b.w;
    }
    return result;
});

ceslf(struct Mat4f subvMat4f(struct Mat4f a, struct Vec4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        result.m[i][0] = a.m[i][0] - b.x;
        result.m[i][1] = a.m[i][1] - b.y;
        result.m[i][2] = a.m[i][2] - b.z;
        result.m[i][3] = a.m[i][3] - b.w;
    }
    return result;
});

ceslf(struct Mat4f mulvMat4f(struct Mat4f a, struct Vec4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        result.m[i][0] = a.m[i][0] * b.x;
        result.m[i][1] = a.m[i][1] * b.y;
        result.m[i][2] = a.m[i][2] * b.z;
        result.m[i][3] = a.m[i][3] * b.w;
    }
    return result;
});

ceslf(struct Mat4f divvMat4f(struct Mat4f a, struct Vec4f b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        result.m[i][0] = a.m[i][0] / b.x;
        result.m[i][1] = a.m[i][1] / b.y;
        result.m[i][2] = a.m[i][2] / b.z;
        result.m[i][3] = a.m[i][3] / b.w;
    }
    return result;
});

ceslf(struct Mat4f addfMat4f(struct Mat4f a, float b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] + b;
        }
    }
    return result;
});

ceslf(struct Mat4f subfMat4f(struct Mat4f a, float b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] - b;
        }
    }
    return result;
});

ceslf(struct Mat4f mulfMat4f(struct Mat4f a, float b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] * b;
        }
    }
    return result;
});

ceslf(struct Mat4f divfMat4f(struct Mat4f a, float b), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[i][j] / b;
        }
    }
    return result;
});

ceslf(struct Mat4f identityMat4f(), {
    struct Mat4f result = newMat4f();
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;
    return result;
});

ceslf(struct Mat4f transposeMat4f(struct Mat4f a), {
    struct Mat4f result = newMat4f();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = a.m[j][i];
        }
    }
    return result;
});

ceslf(struct Mat4f inverseMat4f(struct Mat4f a), {
    struct Mat4f result = newMat4f();
    float det = a.m[0][0] * a.m[1][1] * a.m[2][2] * a.m[3][3] +
                a.m[0][0] * a.m[1][2] * a.m[2][3] * a.m[3][1] +
                a.m[0][0] * a.m[1][3] * a.m[2][1] * a.m[3][2] +
                a.m[0][1] * a.m[1][0] * a.m[2][3] * a.m[3][2] +
                a.m[0][1] * a.m[1][2] * a.m[2][0] * a.m[3][3] +
                a.m[0][1] * a.m[1][3] * a.m[2][2] * a.m[3][0] +
                a.m[0][2] * a.m[1][0] * a.m[2][1] * a.m[3][3] +
                a.m[0][2] * a.m[1][1] * a.m[2][3] * a.m[3][0] +
                a.m[0][2] * a.m[1][3] * a.m[2][0] * a.m[3][1] +
                a.m[0][3] * a.m[1][0] * a.m[2][2] * a.m[3][1] +
                a.m[0][3] * a.m[1][1] * a.m[2][0] * a.m[3][2] +
                a.m[0][3] * a.m[1][2] * a.m[2][1] * a.m[3][0] -
                a.m[0][0] * a.m[1][1] * a.m[2][3] * a.m[3][2] -
                a.m[0][0] * a.m[1][2] * a.m[2][1] * a.m[3][3] -
                a.m[0][0] * a.m[1][3] * a.m[2][2] * a.m[3][1] -
                a.m[0][1] * a.m[1][0] * a.m[2][2] * a.m[3][3] -
                a.m[0][1] * a.m[1][2] * a.m[2][3] * a.m[3][0] -
                a.m[0][1] * a.m[1][3] * a.m[2][0] * a.m[3][2] -
                a.m[0][2] * a.m[1][0] * a.m[2][3] * a.m[3][1] -
                a.m[0][2] * a.m[1][1] * a.m[2][0] * a.m[3][3] -
                a.m[0][2] * a.m[1][3] * a.m[2][1] * a.m[3][0] -
                a.m[0][3] * a.m[1][0] * a.m[2][1] * a.m[3][2] -
                a.m[0][3] * a.m[1][1] * a.m[2][2] * a.m[3][0] -
                a.m[0][3] * a.m[1][2] * a.m[2][0] * a.m[3][1];
    result.m[0][0] =
        (a.m[1][1] * a.m[2][2] * a.m[3][3] + a.m[1][2] * a.m[2][3] * a.m[3][1] +
         a.m[1][3] * a.m[2][1] * a.m[3][2] - a.m[1][1] * a.m[2][3] * a.m[3][2] -
         a.m[1][2] * a.m[2][1] * a.m[3][3] -
         a.m[1][3] * a.m[2][2] * a.m[3][1]) /
        det;
    result.m[0][1] =
        (a.m[0][1] * a.m[2][3] * a.m[3][2] + a.m[0][2] * a.m[2][1] * a.m[3][3] +
         a.m[0][3] * a.m[2][2] * a.m[3][1] - a.m[0][1] * a.m[2][2] * a.m[3][3] -
         a.m[0][2] * a.m[2][3] * a.m[3][1] -
         a.m[0][3] * a.m[2][1] * a.m[3][2]) /
        det;
    result.m[0][2] =
        (a.m[0][1] * a.m[1][2] * a.m[3][3] + a.m[0][2] * a.m[1][3] * a.m[3][1] +
         a.m[0][3] * a.m[1][1] * a.m[3][2] - a.m[0][1] * a.m[1][3] * a.m[3][2] -
         a.m[0][2] * a.m[1][1] * a.m[3][3] -
         a.m[0][3] * a.m[1][2] * a.m[3][1]) /
        det;
    result.m[0][3] =
        (a.m[0][1] * a.m[1][3] * a.m[2][2] + a.m[0][2] * a.m[1][1] * a.m[2][3] +
         a.m[0][3] * a.m[1][2] * a.m[2][1] - a.m[0][1] * a.m[1][2] * a.m[2][3] -
         a.m[0][2] * a.m[1][3] * a.m[2][1] -
         a.m[0][3] * a.m[1][1] * a.m[2][2]) /
        det;
    result.m[1][0] =
        (a.m[1][0] * a.m[2][3] * a.m[3][2] + a.m[1][2] * a.m[2][0] * a.m[3][3] +
         a.m[1][3] * a.m[2][2] * a.m[3][0] - a.m[1][0] * a.m[2][2] * a.m[3][3] -
         a.m[1][2] * a.m[2][3] * a.m[3][0] -
         a.m[1][3] * a.m[2][0] * a.m[3][2]) /
        det;
    result.m[1][1] =
        (a.m[0][0] * a.m[2][2] * a.m[3][3] + a.m[0][2] * a.m[2][3] * a.m[3][0] +
         a.m[0][3] * a.m[2][0] * a.m[3][2] - a.m[0][0] * a.m[2][3] * a.m[3][2] -
         a.m[0][2] * a.m[2][0] * a.m[3][3] -
         a.m[0][3] * a.m[2][2] * a.m[3][0]) /
        det;
    result.m[1][2] =
        (a.m[0][0] * a.m[1][3] * a.m[3][2] + a.m[0][2] * a.m[1][0] * a.m[3][3] +
         a.m[0][3] * a.m[1][2] * a.m[3][0] - a.m[0][0] * a.m[1][2] * a.m[3][3] -
         a.m[0][2] * a.m[1][3] * a.m[3][0] -
         a.m[0][3] * a.m[1][0] * a.m[3][2]) /
        det;
    result.m[1][3] =
        (a.m[0][0] * a.m[1][2] * a.m[2][3] + a.m[0][2] * a.m[1][3] * a.m[2][0] +
         a.m[0][3] * a.m[1][0] * a.m[2][2] - a.m[0][0] * a.m[1][3] * a.m[2][2] -
         a.m[0][2] * a.m[1][0] * a.m[2][3] -
         a.m[0][3] * a.m[1][2] * a.m[2][0]) /
        det;
    result.m[2][0] =
        (a.m[1][0] * a.m[2][1] * a.m[3][3] + a.m[1][1] * a.m[2][3] * a.m[3][0] +
         a.m[1][3] * a.m[2][0] * a.m[3][1] - a.m[1][0] * a.m[2][3] * a.m[3][1] -
         a.m[1][1] * a.m[2][0] * a.m[3][3] -
         a.m[1][3] * a.m[2][1] * a.m[3][0]) /
        det;
    result.m[2][1] =
        (a.m[0][0] * a.m[2][3] * a.m[3][1] + a.m[0][1] * a.m[2][0] * a.m[3][3] +
         a.m[0][3] * a.m[2][1] * a.m[3][0] - a.m[0][0] * a.m[2][1] * a.m[3][3] -
         a.m[0][1] * a.m[2][3] * a.m[3][0] -
         a.m[0][3] * a.m[2][0] * a.m[3][1]) /
        det;
    result.m[2][2] =
        (a.m[0][0] * a.m[1][1] * a.m[3][3] + a.m[0][1] * a.m[1][3] * a.m[3][0] +
         a.m[0][3] * a.m[1][0] * a.m[3][1] - a.m[0][0] * a.m[1][3] * a.m[3][1] -
         a.m[0][1] * a.m[1][0] * a.m[3][3] -
         a.m[0][3] * a.m[1][1] * a.m[3][0]) /
        det;
    result.m[2][3] =
        (a.m[0][0] * a.m[1][3] * a.m[2][1] + a.m[0][1] * a.m[1][0] * a.m[2][3] +
         a.m[0][3] * a.m[1][1] * a.m[2][0] - a.m[0][0] * a.m[1][1] * a.m[2][3] -
         a.m[0][1] * a.m[1][3] * a.m[2][0] -
         a.m[0][3] * a.m[1][0] * a.m[2][1]) /
        det;
    result.m[3][0] =
        (a.m[1][0] * a.m[2][2] * a.m[3][1] + a.m[1][1] * a.m[2][0] * a.m[3][2] +
         a.m[1][2] * a.m[2][1] * a.m[3][0] - a.m[1][0] * a.m[2][1] * a.m[3][2] -
         a.m[1][1] * a.m[2][2] * a.m[3][0] -
         a.m[1][2] * a.m[2][0] * a.m[3][1]) /
        det;
    result.m[3][1] =
        (a.m[0][0] * a.m[2][1] * a.m[3][2] + a.m[0][1] * a.m[2][2] * a.m[3][0] +
         a.m[0][2] * a.m[2][0] * a.m[3][1] - a.m[0][0] * a.m[2][2] * a.m[3][1] -
         a.m[0][1] * a.m[2][0] * a.m[3][2] -
         a.m[0][2] * a.m[2][1] * a.m[3][0]) /
        det;
    result.m[3][2] =
        (a.m[0][0] * a.m[1][2] * a.m[3][1] + a.m[0][1] * a.m[1][0] * a.m[3][2] +
         a.m[0][2] * a.m[1][1] * a.m[3][0] - a.m[0][0] * a.m[1][1] * a.m[3][2] -
         a.m[0][1] * a.m[1][2] * a.m[3][0] -
         a.m[0][2] * a.m[1][0] * a.m[3][1]) /
        det;
    result.m[3][3] =
        (a.m[0][0] * a.m[1][1] * a.m[2][2] + a.m[0][1] * a.m[1][2] * a.m[2][0] +
         a.m[0][2] * a.m[1][0] * a.m[2][1] - a.m[0][0] * a.m[1][2] * a.m[2][1] -
         a.m[0][1] * a.m[1][0] * a.m[2][2] -
         a.m[0][2] * a.m[1][1] * a.m[2][0]) /
        det;
    return result;
});

ceslf(struct Mat4f translateMat4f(struct Mat4f a, struct Vec3f v), {
    struct Mat4f result = a;
    result.m[3][0] =
        a.m[0][0] * v.x + a.m[1][0] * v.y + a.m[2][0] * v.z + a.m[3][0];
    result.m[3][1] =
        a.m[0][1] * v.x + a.m[1][1] * v.y + a.m[2][1] * v.z + a.m[3][1];
    result.m[3][2] =
        a.m[0][2] * v.x + a.m[1][2] * v.y + a.m[2][2] * v.z + a.m[3][2];
    result.m[3][3] =
        a.m[0][3] * v.x + a.m[1][3] * v.y + a.m[2][3] * v.z + a.m[3][3];
    return result;
});

ceslf(struct Mat4f scaleMat4f(struct Mat4f a, struct Vec3f v), {
    struct Mat4f result = a;
    result.m[0][0] = a.m[0][0] * v.x;
    result.m[0][1] = a.m[0][1] * v.x;
    result.m[0][2] = a.m[0][2] * v.x;
    result.m[0][3] = a.m[0][3] * v.x;
    result.m[1][0] = a.m[1][0] * v.y;
    result.m[1][1] = a.m[1][1] * v.y;
    result.m[1][2] = a.m[1][2] * v.y;
    result.m[1][3] = a.m[1][3] * v.y;
    result.m[2][0] = a.m[2][0] * v.z;
    result.m[2][1] = a.m[2][1] * v.z;
    result.m[2][2] = a.m[2][2] * v.z;
    result.m[2][3] = a.m[2][3] * v.z;
    return result;
});

ceslf(struct Mat4f rotateMat4f(struct Mat4f a, float angle, struct Vec3f axis),
      {
          struct Mat4f result = a;
          float c = cosf(angle);
          float s = sinf(angle);
          float omc = 1.0f - c;
          float x = axis.x;
          float y = axis.y;
          float z = axis.z;
          result.m[0][0] = c + x * x * omc;
          result.m[0][1] = x * y * omc + z * s;
          result.m[0][2] = x * z * omc - y * s;
          result.m[0][3] = 0.0f;
          result.m[1][0] = y * x * omc - z * s;
          result.m[1][1] = c + y * y * omc;
          result.m[1][2] = y * z * omc + x * s;
          result.m[1][3] = 0.0f;
          result.m[2][0] = z * x * omc + y * s;
          result.m[2][1] = z * y * omc - x * s;
          result.m[2][2] = c + z * z * omc;
          result.m[2][3] = 0.0f;
          result.m[3][0] = 0.0f;
          result.m[3][1] = 0.0f;
          result.m[3][2] = 0.0f;
          result.m[3][3] = 1.0f;
          return result;
      });

ceslf(struct Mat4f perspectiveMat4f(float fov, float aspect, float near,
                                    float far),
      {
          struct Mat4f result;
          float f = 1.0f / tanf(fov / 2.0f);
          result.m[0][0] = f / aspect;
          result.m[0][1] = 0.0f;
          result.m[0][2] = 0.0f;
          result.m[0][3] = 0.0f;
          result.m[1][0] = 0.0f;
          result.m[1][1] = f;
          result.m[1][2] = 0.0f;
          result.m[1][3] = 0.0f;
          result.m[2][0] = 0.0f;
          result.m[2][1] = 0.0f;
          result.m[2][2] = (far + near) / (near - far);
          result.m[2][3] = -1.0f;
          result.m[3][0] = 0.0f;
          result.m[3][1] = 0.0f;
          result.m[3][2] = (2.0f * far * near) / (near - far);
          result.m[3][3] = 0.0f;
          return result;
      });

ceslf(struct Mat4f orthoMat4f(float left, float right, float bottom, float top,
                              float near, float far),
      {
          struct Mat4f result;
          result.m[0][0] = 2.0f / (right - left);
          result.m[0][1] = 0.0f;
          result.m[0][2] = 0.0f;
          result.m[0][3] = 0.0f;
          result.m[1][0] = 0.0f;
          result.m[1][1] = 2.0f / (top - bottom);
          result.m[1][2] = 0.0f;
          result.m[1][3] = 0.0f;
          result.m[2][0] = 0.0f;
          result.m[2][1] = 0.0f;
          result.m[2][2] = -2.0f / (far - near);
          result.m[2][3] = 0.0f;
          result.m[3][0] = -(right + left) / (right - left);
          result.m[3][1] = -(top + bottom) / (top - bottom);
          result.m[3][2] = -(far + near) / (far - near);
          result.m[3][3] = 1.0f;
          return result;
      });

ceslf(struct Mat4f lookAtMat4f(struct Vec3f eye, struct Vec3f center,
                               struct Vec3f up),
      {
          struct Mat4f result;
          struct Vec3f f = normVec3f(subVec3f(center, eye));
          struct Vec3f s = normVec3f(crossVec3f(f, up));
          struct Vec3f u = crossVec3f(s, f);
          result.m[0][0] = s.x;
          result.m[0][1] = u.x;
          result.m[0][2] = -f.x;
          result.m[0][3] = 0.0f;
          result.m[1][0] = s.y;
          result.m[1][1] = u.y;
          result.m[1][2] = -f.y;
          result.m[1][3] = 0.0f;
          result.m[2][0] = s.z;
          result.m[2][1] = u.z;
          result.m[2][2] = -f.z;
          result.m[2][3] = 0.0f;
          result.m[3][0] = -dotVec3f(s, eye);
          result.m[3][1] = -dotVec3f(u, eye);
          result.m[3][2] = dotVec3f(f, eye);
          result.m[3][3] = 1.0f;
          return result;
      });

ceslf(struct Mat4f newMat4f(), {
    struct Mat4f result;
    // initialize 2d array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                result.m[i][j] = 1.0f;
            } else {
                result.m[i][j] = 0.0f;
            }
        }
    }
    // "member" functions
    result.add = &addMat4f;
    result.sub = &subMat4f;
    result.mul = &mulMat4f;
    result.addv = &addvMat4f;
    result.subv = &subvMat4f;
    result.mulv = &mulvMat4f;
    result.divv = &divvMat4f;
    result.addf = &addfMat4f;
    result.subf = &subfMat4f;
    result.mulf = &mulfMat4f;
    result.divf = &divfMat4f;
    result.identity = &identityMat4f;
    result.transpose = &transposeMat4f;
    result.inverse = &inverseMat4f;
    result.translate = &translateMat4f;
    result.scale = &scaleMat4f;
    result.rotate = &rotateMat4f;
    result.perspective = &perspectiveMat4f;
    result.ortho = &orthoMat4f;
    result.lookAt = &lookAtMat4f;
    return result;
});
