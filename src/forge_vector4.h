#ifndef FORGE_VECTOR4_H
#define FORGE_VECTOR4_H

#include <forge_base_types.h>
#include <forge_platform_types.h>
#include <forge_vector2.h>
#include <forge_vector3.h>

#include <math.h>

typedef union Vector4 {
    struct {
        union {
            Vector3 xyz;
            struct {
                f32 x, y, z;
            };
        };

        f32 w;
    };

    struct {
        union {
            Vector3 rgb;
            struct {
                f32 r, g, b;
            };
        };

        f32 a;
    };

    struct {
        Vector2 xy;
        f32 _ignored0;
        f32 _ignored1;
    };

    struct {
        f32 _ignored2;
        Vector2 yz;
        f32 _ignored3;
    };

    struct {
        f32 _ignored4;
        f32 _ignored5;
        Vector2 zw;
    };

    struct {
        f32 left, right, top, botton;
    };

    struct {
        f32 _ignored6;
        f32 _ignored7;
        f32 width, height;
    };

    f32 elements[4];
} Vector4;

EXPORT_LIB Vector4 v4(f32 x, f32 y, f32 z, f32 w);
EXPORT_LIB Vector4 add_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 sub_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 mul_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 mul_v4f(Vector4 left, f32 right);
EXPORT_LIB Vector4 div_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 div_v4f(Vector4 left, f32 right);
EXPORT_LIB f32 dot_v4(Vector4 left, Vector4 right);
EXPORT_LIB b32 is_equal_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 norm_v4(Vector4 v);
EXPORT_LIB f32 len_sqrt_v4(Vector4 v);
EXPORT_LIB f32 len_v4(Vector4 v);
EXPORT_LIB Vector4 lerp_v4(Vector4 left, Vector4 right, f32 time);

#endif // FORGE_VECTOR4_H
