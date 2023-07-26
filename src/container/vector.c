#include "container/vector.h"

#include <math.h>

CVector2
v2(f32 x, f32 y)
{
    CVector2 v;
    v.x = x;
    v.y = y;
    return v;
}

CVector2
v2_add(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

CVector2
v2_addf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x + right;
    v.y = left.y + right;
    return v;
}

CVector2
v2_sub(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    return v;
}

CVector2
v2_subf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x - right;
    v.y = left.y - right;
    return v;
}

CVector2
v2_mul(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    return v;
}

CVector2
v2_mulf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x * right;
    v.y = left.y * right;
    return v;
}

CVector2
v2_div(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    return v;
}

CVector2
v2_divf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x / right;
    v.y = left.y / right;
    return v;
}

f32
v2_dot(CVector2 left, CVector2 right)
{
    return (left.x * right.x) + (left.y * right.y);
}

b8
v2_eq(CVector2 left, CVector2 right)
{
    return left.x == right.x && left.y == right.y;
}

CVector2
v2_norm(CVector2 v)
{
    return v2_mulf(v, 1.0f / sqrtf(v2_dot(v, v)));
}

f32
v2_sqrt_len(CVector2 v)
{
    return v2_dot(v, v);
}

f32
v2_len(CVector2 v)
{
    return sqrtf(v2_sqrt_len(v));
}

CVector2
v2_lerp(CVector2 left, CVector2 right, f32 time)
{
    return v2_add(v2_mulf(left, 1.0f - time), v2_mulf(right, time));
}

CVector3
v3(f32 x, f32 y, f32 z)
{
    CVector3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

CVector3
v3_add(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    return v;
}

CVector3
v3_sub(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    return v;
}

CVector3
v3_mul(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    return v;
}

CVector3
v3_mulf(CVector3 left, f32 right)
{
    CVector3 v;
    v.x = left.x * right;
    v.y = left.y * right;
    v.z = left.z * right;
    return v;
}

CVector3
v3_div(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    return v;
}

CVector3
v3_divf(CVector3 left, f32 right)
{
    CVector3 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    return v;
}

f32
v3_dot(CVector3 left, CVector3 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

b8
v3_eq(CVector3 left, CVector3 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

CVector3
v3_norm(CVector3 v)
{
    return v3_mulf(v, 1.0f / sqrtf(v3_dot(v, v)));
}

f32
v3_sqrt_len(CVector3 v)
{
    return v3_dot(v, v);
}

f32
v3_len(CVector3 v)
{
    return sqrtf(v3_sqrt_len(v));
}

CVector3
v3_lerp(CVector3 left, CVector3 right, f32 time)
{
    return v3_add(v3_mulf(left, 1.0f - time), v3_mulf(right, time));
}

CVector4
v4(f32 x, f32 y, f32 z, f32 w)
{
    CVector4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

CVector4
v4_add(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    v.w = left.w + right.w;
    return v;
}

CVector4
v4_sub(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    v.w = left.w - right.w;
    return v;
}

CVector4
v4_mul(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    v.w = left.w * right.w;
    return v;
}

CVector4
v4_mulf(CVector4 left, f32 right)
{
    CVector4 v;
    v.x = left.x * right;
    v.y = left.y * right;
    v.z = left.z * right;
    v.w = left.w * right;
    return v;
}

CVector4
v4_div(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    v.w = left.w / right.w;
    return v;
}

CVector4
v4_divf(CVector4 left, f32 right)
{
    CVector4 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    v.w = left.w / right;
    return v;
}

f32
v4_dot(CVector4 left, CVector4 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z)
           + (left.w * right.w);
}

b8
v4_eq(CVector4 left, CVector4 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z
           && left.w == right.w;
}

CVector4
v4_norm(CVector4 v)
{
    return v4_mulf(v, 1.0f / sqrtf(v4_dot(v, v)));
}

f32
v4_sqrt_len(CVector4 v)
{
    return v4_dot(v, v);
}

f32
v4_len(CVector4 v)
{
    return sqrtf(v4_sqrt_len(v));
}

CVector4
v4_lerp(CVector4 left, CVector4 right, f32 time)
{
    return v4_add(v4_mulf(left, 1.0f - time), v4_mulf(right, time));
}
