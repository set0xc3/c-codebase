#ifndef FORGE_MATH_H
#define FORGE_MATH_H

#include "forge_base_types.h"

#include <math.h>

inline f32 m_to_radiansf(f32 degree) { return degree * (M_PI / 180.0f); }

inline f32 m_to_degreesf(f32 radian) { return radian * (180.0f / M_PI); }

inline f64 m_to_radians(f64 degree) { return degree * (M_PI / 180.0f); }

inline f64 m_to_degrees(f64 radian) { return radian * (180.0f / M_PI); }

#endif // FORGE_MATH_H
