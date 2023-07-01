#include "vector.h"

#include <math.h>

Vector4
v4(f32 x, f32 y, f32 z, f32 w)
{
    Vector4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

Vector4
add_v4(Vector4 left, Vector4 right)
{
    Vector4 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    v.w = left.w + right.w;
    return v;
}

Vector4
sub_v4(Vector4 left, Vector4 right)
{
    Vector4 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    v.w = left.w - right.w;
    return v;
}

Vector4
mul_v4(Vector4 left, Vector4 right)
{
    Vector4 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    v.w = left.w * right.w;
    return v;
}

Vector4
mul_v4f(Vector4 left, f32 right)
{
    Vector4 v;
    v.x = left.x * right;
    v.y = left.y * right;
    v.z = left.z * right;
    v.w = left.w * right;
    return v;
}

Vector4
div_v4(Vector4 left, Vector4 right)
{
    Vector4 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    v.w = left.w / right.w;
    return v;
}

Vector4
div_v4f(Vector4 left, f32 right)
{
    Vector4 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    v.w = left.w / right;
    return v;
}

f32
dot_v4(Vector4 left, Vector4 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z)
           + (left.w * right.w);
}

b32
is_equal_v4(Vector4 left, Vector4 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z
           && left.w == right.w;
}

Vector4
norm_v4(Vector4 v)
{
    return mul_v4f(v, 1.0f / sqrtf(dot_v4(v, v)));
}

f32
len_sqrt_v4(Vector4 v)
{
    return dot_v4(v, v);
}

f32
len_v4(Vector4 v)
{
    return sqrtf(len_sqrt_v4(v));
}

Vector4
lerp_v4(Vector4 left, Vector4 right, f32 time)
{
    return add_v4(mul_v4f(left, 1.0f - time), mul_v4f(right, time));
}
