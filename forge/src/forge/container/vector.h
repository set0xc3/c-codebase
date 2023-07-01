#ifndef FORGE_CONTAINER_VECTOR_H
#define FORGE_CONTAINER_VECTOR_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

// Vector2

typedef union Vector2
{
    struct
    {
        f32 x, y;
    };

    struct
    {
        f32 u, v;
    };

    struct
    {
        f32 left, right;
    };

    struct
    {
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
EXPORT_LIB f32     dot_v2(Vector2 left, Vector2 right);
EXPORT_LIB b32     is_equal_v2(Vector2 left, Vector2 right);
EXPORT_LIB Vector2 norm_v2(Vector2 v);
EXPORT_LIB f32     len_sqrt_v2(Vector2 v);
EXPORT_LIB f32     len_v2(Vector2 v);
EXPORT_LIB Vector2 lerp_v2(Vector2 left, Vector2 right, f32 time);

// Vector3

typedef union Vector3
{
    struct
    {
        f32 x, y, z;
    };

    struct
    {
        f32 u, v, w;
    };

    struct
    {
        f32 r, g, b;
    };

    struct
    {
        Vector2 xy;
        f32     _ignored0;
    };

    struct
    {
        f32     _ignored1;
        Vector2 yz;
    };

    struct
    {
        Vector2 uv;
        f32     _ignored2;
    };

    struct
    {
        f32     _ignored3;
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
EXPORT_LIB f32     dot_v3(Vector3 left, Vector3 right);
EXPORT_LIB b32     is_equal_v3(Vector3 left, Vector3 right);
EXPORT_LIB Vector3 norm_v3(Vector3 v);
EXPORT_LIB f32     len_sqrt_v3(Vector3 v);
EXPORT_LIB f32     len_v3(Vector3 v);
EXPORT_LIB Vector3 lerp_v3(Vector3 left, Vector3 right, f32 time);

// Vector4

typedef union Vector4
{
    struct
    {
        union
        {
            Vector3 xyz;
            struct
            {
                f32 x, y, z;
            };
        };

        f32 w;
    };

    struct
    {
        union
        {
            Vector3 rgb;
            struct
            {
                f32 r, g, b;
            };
        };

        f32 a;
    };

    struct
    {
        Vector2 xy;
        f32     _ignored0;
        f32     _ignored1;
    };

    struct
    {
        f32     _ignored2;
        Vector2 yz;
        f32     _ignored3;
    };

    struct
    {
        f32     _ignored4;
        f32     _ignored5;
        Vector2 zw;
    };

    struct
    {
        f32 left, right, top, botton;
    };

    struct
    {
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
EXPORT_LIB f32     dot_v4(Vector4 left, Vector4 right);
EXPORT_LIB b32     is_equal_v4(Vector4 left, Vector4 right);
EXPORT_LIB Vector4 norm_v4(Vector4 v);
EXPORT_LIB f32     len_sqrt_v4(Vector4 v);
EXPORT_LIB f32     len_v4(Vector4 v);
EXPORT_LIB Vector4 lerp_v4(Vector4 left, Vector4 right, f32 time);

#endif // FORGE_CONTAINER_VECTOR_H
