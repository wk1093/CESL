#include "cesl/vec.h"

int main() {
    struct Vec3f v = initVec3f(2, 3, 5);
    struct Vec3f w = initVec3f(1, 2, 3);

    struct Vec3f r = v.cross(v, w);
    float d = v.dot(v, w);

    printf("r = %s, d = %f\n", r.str(r), d);

    return 0;
}