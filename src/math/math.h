#pragma once

#include "base/defines.h"
#include "math/types.h"

#define MATH_PI       3.14159265358979323846f
#define MATH_INFINITY (1e30f * 1e30f)

API f32 math_random(void);
API f32 math_sqrt(f32 x);
API f32 math_tan(f32 x);
API f32 math_cos(f32 x);
API f32 math_sin(f32 x);
API f32 math_acos(f32 x);
API f32 math_abs(f32 x);

INLINE f32
math_deg_to_rad(f32 degree)
{
    return degree * (MATH_PI / 180.0f);
}

INLINE f32
math_rad_to_deg(f32 radian)
{
    return radian * (180.0f / MATH_PI);
}

INLINE u32
rgbu_to_u32(u32 r, u32 g, u32 b)
{
    return (((r & 0x0FF) << 16) | ((g & 0x0FF) << 8) | (b & 0x0FF));
}

INLINE void
u32_to_rgb(u32 rgbu, u32 *out_r, u32 *out_g, u32 *out_b)
{
    *out_r = (rgbu >> 16) & 0x0FF;
    *out_g = (rgbu >> 8) & 0x0FF;
    *out_b = (rgbu)&0x0FF;
}

INLINE CVector3
rgb_u32_to_vec3(u32 r, u32 g, u32 b)
{
    CVector3 out_v;

    out_v.r = r / 255.0f;
    out_v.g = g / 255.0f;
    out_v.b = b / 255.0f;

    return out_v;
}

INLINE void
vec3_to_rgb_u32(CVector3 v, u32 *out_r, u32 *out_g, u32 *out_b)
{
    *out_r = v.r * 255;
    *out_g = v.g * 255;
    *out_b = v.b * 255;
}
