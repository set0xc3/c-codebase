#ifndef FORGE_VECTOR3_H
#define FORGE_VECTOR3_H

#include <forge_base_types.h>
#include <forge_platform_types.h>
#include <forge_vector2.h>

#include <math.h>

typedef union Vector3 {
    struct {
        f32 x, y, z;
    };

    struct {
        f32 u, v, w;
    };

    struct {
        f32 r, g, b;
    };

    struct {
        Vector2 xy;
        f32 _ignored0;
    };

    struct {
        f32 _ignored1;
        Vector2 yz;
    };

    struct {
        Vector2 uv;
        f32 _ignored2;
    };

    struct {
        f32 _ignored3;
        Vector2 vw;
    };

    f32 elements[3];
} Vector3;

EXPORT_LIB Vector3 v3(f32 x, f32 y, f32 z);
EXPORT_LIB Vector3 add_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 sub_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 mul_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 mul_v3f(Vector3 left, f32 right);
EXPORT_LIB Vector3 div_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 div_v3f(Vector3 left, f32 right);
EXPORT_LIB f32 dot_v3(Vector3 left, Vector3 right);
EXPORT_LIB b32 is_equal_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 norm_v3(Vector3 v);
EXPORT_LIB f32 len_sqrt_v3(Vector3 v);
EXPORT_LIB f32 len_v3(Vector3 v);
EXPORT_LIB Vector3 lerp_v3(Vector3 left, Vector3 right, f32 time);

#endif // FORGE_VECTOR3_H
