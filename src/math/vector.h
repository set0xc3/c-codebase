#pragma once

#include "base/defines.h"
#include "math/math.h"
#include "math/types.h"

INLINE CVector2
vec2_init(f32 x, f32 y)
{
    CVector2 v;
    v.x = x;
    v.y = y;
    return v;
}

INLINE CVector2
vec2_add(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

INLINE CVector2
vec2_addf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x + right;
    v.y = left.y + right;
    return v;
}

INLINE CVector2
vec2_sub(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    return v;
}

INLINE CVector2
vec2_subf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x - right;
    v.y = left.y - right;
    return v;
}

INLINE CVector2
vec2_mul(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    return v;
}

INLINE CVector2
vec2_mul_scalar(CVector2 a, f32 scalar)
{
    CVector2 v;
    v.x = a.x * scalar;
    v.y = a.y * scalar;
    return v;
}

INLINE CVector2
vec2_div(CVector2 left, CVector2 right)
{
    CVector2 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    return v;
}

INLINE CVector2
vec2_divf(CVector2 left, f32 right)
{
    CVector2 v;
    v.x = left.x / right;
    v.y = left.y / right;
    return v;
}

INLINE f32
vec2_dot(CVector2 left, CVector2 right)
{
    return (left.x * right.x) + (left.y * right.y);
}

INLINE b8
vec2_eq(CVector2 left, CVector2 right)
{
    return left.x == right.x && left.y == right.y;
}

INLINE CVector2
vec2_normalized(CVector2 v)
{
    return vec2_mul_scalar(v, 1.0f / math_sqrt(vec2_dot(v, v)));
}

INLINE f32
vec2_sqrt_len(CVector2 v)
{
    return vec2_dot(v, v);
}

INLINE f32
vec2_length(CVector2 v)
{
    return math_sqrt(vec2_sqrt_len(v));
}

INLINE CVector2
vec2_lerp(CVector2 left, CVector2 right, f32 time)
{
    return vec2_add(vec2_mul_scalar(left, 1.0f - time),
                    vec2_mul_scalar(right, time));
}

INLINE f32
vec2_distance(CVector2 a, CVector2 b)
{
    CVector2 d = vec2_init(a.x - b.x, a.y - b.y);
    return vec2_length(d);
}

INLINE CVector2
vec2_zero(void)
{
    return vec2_init(0.0f, 0.0f);
}

INLINE CVector2
vec2_one(void)
{
    return vec2_init(1.0f, 1.0f);
}

INLINE CVector2
vec2_left(void)
{
    return vec2_init(-1.0f, 0.0f);
}

INLINE CVector2
vec2_right(void)
{
    return vec2_init(1.0f, 0.0f);
}

INLINE CVector2
vec2_up(void)
{
    return vec2_init(0.0f, 1.0f);
}

INLINE CVector2
vec2_down(void)
{
    return vec2_init(0.0f, -1.0f);
}

INLINE CVector3
vec3_init(f32 x, f32 y, f32 z)
{
    CVector3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

INLINE CVector3
vec3_add(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    return v;
}

INLINE CVector3
vec3_sub(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    return v;
}

INLINE CVector3
vec3_mul(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    return v;
}

INLINE CVector3
vec3_mul_scalar(CVector3 a, f32 scalar)
{
    CVector3 v;
    v.x = a.x * scalar;
    v.y = a.y * scalar;
    v.z = a.z * scalar;
    return v;
}

INLINE CVector3
vec3_div(CVector3 left, CVector3 right)
{
    CVector3 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    return v;
}

INLINE CVector3
vec3_divf(CVector3 left, f32 right)
{
    CVector3 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    return v;
}

INLINE f32
vec3_dot(CVector3 left, CVector3 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

INLINE CVector3
vec3_cross(CVector3 a, CVector3 b)
{
    CVector3 v = { 0 };

    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;

    return v;
}

INLINE b8
vec3_eq(CVector3 left, CVector3 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

INLINE CVector3
vec3_normalized(CVector3 v)
{
    return vec3_mul_scalar(v, 1.0f / math_sqrt(vec3_dot(v, v)));
}

INLINE f32
vec3_sqrt_len(CVector3 v)
{
    return vec3_dot(v, v);
}

INLINE f32
vec3_length(CVector3 v)
{
    return math_sqrt(vec3_sqrt_len(v));
}

INLINE CVector3
vec3_lerp(CVector3 left, CVector3 right, f32 time)
{
    return vec3_add(vec3_mul_scalar(left, 1.0f - time),
                    vec3_mul_scalar(right, time));
}

INLINE f32
vec3_distance(CVector3 a, CVector3 b)
{
    CVector3 d = vec3_init(a.x - b.x, a.y - b.y, a.z - b.z);
    return vec3_length(d);
}

INLINE CVector3
vec3_zero(void)
{
    return vec3_init(0.0f, 0.0f, 0.0f);
}

INLINE CVector3
vec3_one(void)
{
    return vec3_init(1.0f, 1.0f, 1.0f);
}

INLINE CVector3
vec3_left(void)
{
    return vec3_init(-1.0f, 0.0f, 0.0f);
}

INLINE CVector3
vec3_right(void)
{
    return vec3_init(1.0f, 0.0f, 0.0f);
}

INLINE CVector3
vec3_up(void)
{
    return vec3_init(0.0f, 1.0f, 0.0f);
}

INLINE CVector3
vec3_down(void)
{
    return vec3_init(0.0f, -1.0f, 0.0f);
}

INLINE CVector4
vec4_init(f32 x, f32 y, f32 z, f32 w)
{
    CVector4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

INLINE CVector4
vec4_add(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    v.w = left.w + right.w;
    return v;
}

INLINE CVector4
vec4_sub(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    v.w = left.w - right.w;
    return v;
}

INLINE CVector4
vec4_mul(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    v.w = left.w * right.w;
    return v;
}

INLINE CVector4
vec4_mul_scalar(CVector4 a, f32 scalar)
{
    CVector4 v;
    v.x = a.x * scalar;
    v.y = a.y * scalar;
    v.z = a.z * scalar;
    v.w = a.w * scalar;
    return v;
}

INLINE CVector4
vec4_div(CVector4 left, CVector4 right)
{
    CVector4 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    v.w = left.w / right.w;
    return v;
}

INLINE CVector4
vec4_divf(CVector4 left, f32 right)
{
    CVector4 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    v.w = left.w / right;
    return v;
}

INLINE f32
vec4_dot(CVector4 left, CVector4 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z)
           + (left.w * right.w);
}

INLINE b8
vec4_eq(CVector4 left, CVector4 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z
           && left.w == right.w;
}

INLINE CVector4
vec4_normalized(CVector4 v)
{
    return vec4_mul_scalar(v, 1.0f / math_sqrt(vec4_dot(v, v)));
}

INLINE f32
vec4_sqrt_len(CVector4 v)
{
    return vec4_dot(v, v);
}

INLINE f32
vec4_length(CVector4 v)
{
    return math_sqrt(vec4_sqrt_len(v));
}

INLINE CVector4
vec4_lerp(CVector4 left, CVector4 right, f32 time)
{
    return vec4_add(vec4_mul_scalar(left, 1.0f - time),
                    vec4_mul_scalar(right, time));
}

INLINE f32
vec4_distance(CVector4 a, CVector4 b)
{
    CVector4 d = vec4_init(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    return vec4_length(d);
}

INLINE CVector4
vec4_zero(void)
{
    return vec4_init(0.0f, 0.0f, 0.0f, 0.0f);
}

INLINE CVector4
vec4_one(void)
{
    return vec4_init(1.0f, 1.0f, 1.0f, 1.0f);
}

INLINE CVector4
vec4_left(void)
{
    return vec4_init(-1.0f, 1.0f, 1.0f, 1.0f);
}

INLINE CVector4
vec4_right(void)
{
    return vec4_init(1.0f, 0.0f, 0.0f, 0.0f);
}

INLINE CVector4
vec4_up(void)
{
    return vec4_init(0.0f, 1.0f, 0.0f, 0.0f);
}

INLINE CVector4
vec4_down(void)
{
    return vec4_init(0.0f, -1.0f, 0.0f, 0.0f);
}
