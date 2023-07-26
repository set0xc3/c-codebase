#pragma once

#include "base/defines.h"

typedef union CVector2
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
} CVector2;

API CVector2 v2(f32 x, f32 y);
API CVector2 v2_add(CVector2 left, CVector2 right);
API CVector2 v2_addf(CVector2 left, f32 right);
API CVector2 v2_sub(CVector2 left, CVector2 right);
API CVector2 v2_subf(CVector2 left, f32 right);
API CVector2 v2_mul(CVector2 left, CVector2 right);
API CVector2 v2_mulf(CVector2 left, f32 right);
API CVector2 v2_div(CVector2 left, CVector2 right);
API CVector2 v2_divf(CVector2 left, f32 right);
API f32      v2_dot(CVector2 left, CVector2 right);
API b8       v2_eq(CVector2 left, CVector2 right);
API CVector2 v2_norm(CVector2 v);
API f32      v2_sqrt_len(CVector2 v);
API f32      v2_len(CVector2 v);
API CVector2 v2_lerp(CVector2 left, CVector2 right, f32 time);

typedef union CVector3
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
        CVector2 xy;
        f32      _ignored0;
    };

    struct
    {
        f32      _ignored1;
        CVector2 yz;
    };

    struct
    {
        CVector2 uv;
        f32      _ignored2;
    };

    struct
    {
        f32      _ignored3;
        CVector2 vw;
    };

    f32 elements[3];
} CVector3;

API CVector3 v3(f32 x, f32 y, f32 z);
API CVector3 v3_add(CVector3 left, CVector3 right);
API CVector3 v3_sub(CVector3 left, CVector3 right);
API CVector3 v3_mul(CVector3 left, CVector3 right);
API CVector3 v3_mulf(CVector3 left, f32 right);
API CVector3 v3_div(CVector3 left, CVector3 right);
API CVector3 v3_divf(CVector3 left, f32 right);
API f32      v3_dot(CVector3 left, CVector3 right);
API b8       v3_eq(CVector3 left, CVector3 right);
API CVector3 v3_norm(CVector3 v);
API f32      v3_sqrt_len(CVector3 v);
API f32      v3_len(CVector3 v);
API CVector3 v3_lerp(CVector3 left, CVector3 right, f32 time);

typedef union CVector4
{
    struct
    {
        union
        {
            CVector3 xyz;
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
            CVector3 rgb;
            struct
            {
                f32 r, g, b;
            };
        };

        f32 a;
    };

    struct
    {
        CVector2 xy;
        f32      _ignored0;
        f32      _ignored1;
    };

    struct
    {
        f32      _ignored2;
        CVector2 yz;
        f32      _ignored3;
    };

    struct
    {
        f32      _ignored4;
        f32      _ignored5;
        CVector2 zw;
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
} CVector4;

API CVector4 v4(f32 x, f32 y, f32 z, f32 w);
API CVector4 v4_add(CVector4 left, CVector4 right);
API CVector4 v4_sub(CVector4 left, CVector4 right);
API CVector4 v4_mul(CVector4 left, CVector4 right);
API CVector4 v4_mulf(CVector4 left, f32 right);
API CVector4 v4_div(CVector4 left, CVector4 right);
API CVector4 v4_divf(CVector4 left, f32 right);
API f32      v4_dot(CVector4 left, CVector4 right);
API b8       v4_eq(CVector4 left, CVector4 right);
API CVector4 v4_norm(CVector4 v);
API f32      v4_sqrt_len(CVector4 v);
API f32      v4_len(CVector4 v);
API CVector4 v4_lerp(CVector4 left, CVector4 right, f32 time);
