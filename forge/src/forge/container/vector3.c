#include "vector.h"

Vector3
v3(f32 x, f32 y, f32 z)
{
    Vector3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector3
add_v3(Vector3 left, Vector3 right)
{
    Vector3 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    v.z = left.z + right.z;
    return v;
}

Vector3
sub_v3(Vector3 left, Vector3 right)
{
    Vector3 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    v.z = left.z - right.z;
    return v;
}

Vector3
mul_v3(Vector3 left, Vector3 right)
{
    Vector3 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    v.z = left.z * right.z;
    return v;
}

Vector3
mul_v3f(Vector3 left, f32 right)
{
    Vector3 v;
    v.x = left.x * right;
    v.y = left.y * right;
    v.z = left.z * right;
    return v;
}

Vector3
div_v3(Vector3 left, Vector3 right)
{
    Vector3 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    v.z = left.z / right.z;
    return v;
}

Vector3
div_v3f(Vector3 left, f32 right)
{
    Vector3 v;
    v.x = left.x / right;
    v.y = left.y / right;
    v.z = left.z / right;
    return v;
}

f32
dot_v3(Vector3 left, Vector3 right)
{
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

b32
is_equal_v3(Vector3 left, Vector3 right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

Vector3
norm_v3(Vector3 v)
{
    return mul_v3f(v, 1.0f / sqrtf(dot_v3(v, v)));
}

f32
len_sqrt_v3(Vector3 v)
{
    return dot_v3(v, v);
}

f32
len_v3(Vector3 v)
{
    return sqrtf(len_sqrt_v3(v));
}

Vector3
lerp_v3(Vector3 left, Vector3 right, f32 time)
{
    return add_v3(mul_v3f(left, 1.0f - time), mul_v3f(right, time));
}
