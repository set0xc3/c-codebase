#ifndef FORGE_VECTOR2_H
#define FORGE_VECTOR2_H

#include "forge_platform_types.h"
#include <forge_base_types.h>

#include <math.h>

typedef union Vector2 {
    struct {
        f32 x, y;
    };

    struct {
        f32 u, v;
    };

    struct {
        f32 left, right;
    };

    struct {
        f32 width, height;
    };

    f32 elements[2];
} Vector2;

EXPORT_LIB Vector2 v2(f32 x, f32 y);
EXPORT_LIB Vector2 add_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 add_v2f(Vector2 left, f32 right);
EXPORT_LIB Vector2 sub_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 sub_v2f(Vector2 left, f32 right);
EXPORT_LIB Vector2 mul_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 mul_v2f(Vector2 left, f32 right);
EXPORT_LIB Vector2 div_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 div_v2f(Vector2 left, f32 right);
EXPORT_LIB f32 dot_v2(Vector2 left, Vector2 right);
EXPORT_LIB b32 is_equal_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 norm_v2(Vector2 v);
EXPORT_LIB f32 len_sqrt_v2(Vector2 v);
EXPORT_LIB f32 len_v2(Vector2 v);
EXPORT_LIB Vector2 lerp_v2(Vector2 left, Vector2 right, f32 time);

#endif // FORGE_VECTOR2_H
