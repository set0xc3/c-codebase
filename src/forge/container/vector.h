#ifndef FORGE_CONTAINER_VECTOR_H
#define FORGE_CONTAINER_VECTOR_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

// V2F

typedef union
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
} V2F;

EXPORT_LIB V2F v2f(f32 x, f32 y);
EXPORT_LIB V2F v2f_add(V2F left, V2F right);
EXPORT_LIB V2F v2f_addf(V2F left, f32 right);
EXPORT_LIB V2F v2f_sub(V2F left, V2F right);
EXPORT_LIB V2F v2f_subf(V2F left, f32 right);
EXPORT_LIB V2F v2f_mul(V2F left, V2F right);
EXPORT_LIB V2F v2f_mulf(V2F left, f32 right);
EXPORT_LIB V2F v2f_div(V2F left, V2F right);
EXPORT_LIB V2F v2f_divf(V2F left, f32 right);
EXPORT_LIB f32 v2f_dot(V2F left, V2F right);
EXPORT_LIB b32 v2f_eq(V2F left, V2F right);
EXPORT_LIB V2F v2f_norm(V2F v);
EXPORT_LIB f32 v2f_sqrt_len(V2F v);
EXPORT_LIB f32 v2f_len(V2F v);
EXPORT_LIB V2F v2f_lerp(V2F left, V2F right, f32 time);

// V3F

typedef union
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
        V2F xy;
        f32 _ignored0;
    };

    struct
    {
        f32 _ignored1;
        V2F yz;
    };

    struct
    {
        V2F uv;
        f32 _ignored2;
    };

    struct
    {
        f32 _ignored3;
        V2F vw;
    };

    f32 elements[3];
} V3F;

EXPORT_LIB V3F v3f(f32 x, f32 y, f32 z);
EXPORT_LIB V3F v3f_add(V3F left, V3F right);
EXPORT_LIB V3F v3f_sub(V3F left, V3F right);
EXPORT_LIB V3F v3f_mul(V3F left, V3F right);
EXPORT_LIB V3F v3f_mulf(V3F left, f32 right);
EXPORT_LIB V3F v3f_div(V3F left, V3F right);
EXPORT_LIB V3F v3f_divf(V3F left, f32 right);
EXPORT_LIB f32 v3f_dot(V3F left, V3F right);
EXPORT_LIB b32 v3f_eq(V3F left, V3F right);
EXPORT_LIB V3F v3f_norm(V3F v);
EXPORT_LIB f32 v3f_sqrt_len(V3F v);
EXPORT_LIB f32 v3f_len(V3F v);
EXPORT_LIB V3F v3f_lerp(V3F left, V3F right, f32 time);

// V4F

typedef union
{
    struct
    {
        union
        {
            V3F xyz;
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
            V3F rgb;
            struct
            {
                f32 r, g, b;
            };
        };

        f32 a;
    };

    struct
    {
        V2F xy;
        f32 _ignored0;
        f32 _ignored1;
    };

    struct
    {
        f32 _ignored2;
        V2F yz;
        f32 _ignored3;
    };

    struct
    {
        f32 _ignored4;
        f32 _ignored5;
        V2F zw;
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
} V4F;

EXPORT_LIB V4F v4f(f32 x, f32 y, f32 z, f32 w);
EXPORT_LIB V4F v4f_add(V4F left, V4F right);
EXPORT_LIB V4F v4f_sub(V4F left, V4F right);
EXPORT_LIB V4F v4f_mul(V4F left, V4F right);
EXPORT_LIB V4F v4f_mulf(V4F left, f32 right);
EXPORT_LIB V4F v4f_div(V4F left, V4F right);
EXPORT_LIB V4F v4f_divf(V4F left, f32 right);
EXPORT_LIB f32 v4f_dot(V4F left, V4F right);
EXPORT_LIB b32 v4f_eq(V4F left, V4F right);
EXPORT_LIB V4F v4f_norm(V4F v);
EXPORT_LIB f32 v4f_sqrt_len(V4F v);
EXPORT_LIB f32 v4f_len(V4F v);
EXPORT_LIB V4F v4f_lerp(V4F left, V4F right, f32 time);

#endif // FORGE_CONTAINER_VECTOR_H
