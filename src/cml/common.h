#pragma once

#include <cassert>
#include <cmath>
#include <cstdint>

namespace cml
{

/* pi */
constexpr double PI = 3.14159265358979323846;

constexpr double epsilon = 4.37114e-05;

template <typename T> inline T radians (T val) { return static_cast<T> ((val * PI) / 180.0); }

template <typename T> inline T degrees (T val) { return static_cast<T> ((180.0 * val) / PI); }

// MIN/MAX

template <typename T> T min (T const a, T const b) { return a < b ? a : b; }

template <typename T> T max (T const a, T const b) { return a > b ? a : b; }


} // namespace cml
