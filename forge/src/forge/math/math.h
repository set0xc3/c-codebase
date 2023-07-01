#ifndef FORGE_MATH_H
#define FORGE_MATH_H

#include "forge/base/base.h"
#include "forge/platform/platform.h"

#include <math.h>

// Angle

EXPORT_LIB f32 m_radiansf(f32 degree);
EXPORT_LIB f32 m_degreesf(f32 radian);
EXPORT_LIB f64 m_radians(f64 degree);
EXPORT_LIB f64 m_degrees(f64 radian);

#endif // FORGE_MATH_H
