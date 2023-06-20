#include "forge_vector2.h"

Vector2 v2(f32 x, f32 y) {
    Vector2 v;
    v.x = x;
    v.y = y;
    return v;
}

Vector2 add_v2(Vector2 left, Vector2 right) {
    Vector2 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

Vector2 sub_v2(Vector2 left, Vector2 right) {
    Vector2 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    return v;
}

Vector2 mul_v2(Vector2 left, Vector2 right) {
    Vector2 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    return v;
}

Vector2 mul_v2f(Vector2 left, f32 right) {
    Vector2 v;
    v.x = left.x * right;
    v.y = left.y * right;
    return v;
}

Vector2 div_v2(Vector2 left, Vector2 right) {
    Vector2 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    return v;
}

Vector2 div_v2f(Vector2 left, f32 right) {
    Vector2 v;
    v.x = left.x / right;
    v.y = left.y / right;
    return v;
}

f32 dot_v2(Vector2 left, Vector2 right) {
    return (left.x * right.x) + (left.y * right.y);
}

b32 is_equal_v2(Vector2 left, Vector2 right) {
    return left.x == right.x && left.y == right.y;
}

Vector2 norm_v2(Vector2 v) { return mul_v2f(v, 1.0f / sqrtf(dot_v2(v, v))); }

f32 len_sqrt_v2(Vector2 v) { return dot_v2(v, v); }

f32 len_v2(Vector2 v) { return sqrtf(len_sqrt_v2(v)); }

Vector2 lerp_v2(Vector2 left, Vector2 right, f32 time) {
    return add_v2(mul_v2f(left, 1.0f - time), mul_v2f(right, time));
}
