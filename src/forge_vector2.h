#ifndef FORGE_VECTOR2_H
#define FORGE_VECTOR2_H

#include <forge_base_types.h>

#include <math.h>

typedef union Vec2 {
    struct {
        f32 x, y;
    };

    struct {
        f32 u, v;
    };

    struct {
        f32 left, right;
    };

    struct {
        f32 width, height;
    };

    f32 elements[2];
} Vec2;

inline Vec2 v2(f32 x, f32 y) {
    Vec2 v;
    v.x = x;
    v.y = y;
    return v;
}

inline Vec2 add_v2(Vec2 left, Vec2 right) {
    Vec2 v;
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

inline Vec2 sub_v2(Vec2 left, Vec2 right) {
    Vec2 v;
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    return v;
}

inline Vec2 mul_v2(Vec2 left, Vec2 right) {
    Vec2 v;
    v.x = left.x * right.x;
    v.y = left.y * right.y;
    return v;
}

inline Vec2 mul_v2f(Vec2 left, f32 right) {
    Vec2 v;
    v.x = left.x * right;
    v.y = left.y * right;
    return v;
}

inline Vec2 div_v2(Vec2 left, Vec2 right) {
    Vec2 v;
    v.x = left.x / right.x;
    v.y = left.y / right.y;
    return v;
}

inline Vec2 div_v2f(Vec2 left, f32 right) {
    Vec2 v;
    v.x = left.x / right;
    v.y = left.y / right;
    return v;
}

inline f32 dot_v2(Vec2 left, Vec2 right) {
    return (left.x * right.x) + (left.y * right.y);
}

inline b32 is_equal_v2(Vec2 left, Vec2 right) {
    return left.x == right.x && left.y == right.y;
}

inline Vec2 norm_v2(Vec2 v) {
    return mul_v2f(v, 1.0f / sqrtf(dot_v2(v, v)));
}

inline f32 len_sqrt_v2(Vec2 v) { return dot_v2(v, v); }

inline f32 len_v2(Vec2 v) { return sqrtf(len_sqrt_v2(v)); }

inline Vec2 lerp_v2(Vec2 left, Vec2 right, f32 time) {
    return add_v2(mul_v2f(left, 1.0f - time), mul_v2f(right, time));
}

#endif // FORGE_VECTOR2_H
