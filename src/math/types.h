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

typedef CVector4 CRect;
typedef CVector2 CPoint;
typedef CVector4 CQuaternion;

typedef struct CVertex2d
{
    CVector2 position;
    CVector4 color;
    CVector2 uv;
} CVertex2d;

typedef struct CVertex3d
{
    CVector3 position;
    CVector4 color;
    CVector3 normal;
    CVector2 uv;
    CVector3 tangent;
} CVertex3d;

typedef struct CMatrix4
{
    f32 data[16];
} CMatrix4;

typedef struct CTransform
{
    CVector3           position;
    CQuaternion        rotation;
    CVector3           scale;
    CMatrix4           local;
    struct CTransform *parent;
    b8                 is_dirty;
} CTransform;
