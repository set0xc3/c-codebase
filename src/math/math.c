#include "math/math.h"

#define M_PI 3.14159265358979323846 /* pi */

f32
math_degreesf(f32 radian)
{
    return radian * (180.0f / M_PI);
}

f64
math_radians(f64 degree)
{
    return degree * (M_PI / 180.0f);
}

f64
math_degrees(f64 radian)
{
    return radian * (180.0f / M_PI);
}
