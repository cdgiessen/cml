#pragma once

#include <cassert>

#include "mat3.h"
#include "mat4.h"
#include "quat.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace cml
{

/* pi */
constexpr double PI = 3.14159265358979323846;


constexpr double epsilon = 4.37114e-05;

// compares floating point numbers, returns true if "equal" and false if not
template <typename T = double> bool cmpf (T A, T B) { return (fabs (A - B) < epsilon); }

template <typename T = double> static inline T degToRad (T val) { return ((val * PI) / 180.0); }

template <typename T = double> static inline T radToDeg (T val) { return ((180.0 * val) / PI); }

} // namespace cml
