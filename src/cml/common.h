#pragma once

#include <cassert>
#include <cmath>
#include <cstdint>

namespace cml
{

/* pi */
constexpr double PI = 3.14159265358979323846;

constexpr double epsilon = 4.37114e-05;

template <typename T> inline T radians (T val) { return ((val * PI) / 180.0); }

template <typename T> inline T degrees (T val) { return ((180.0 * val) / PI); }

} // namespace cml
