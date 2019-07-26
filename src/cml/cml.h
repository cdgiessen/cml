#pragma once

#include "common.h"
#include "mat3.h"
#include "mat4.h"
#include "quat.h"
#include "transform.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace cml
{
template <typename T> vec2<T> to_vec2 (vec3<T> v) { return vec2<T> (v.x, v.y); }
template <typename T> vec2<T> to_vec2 (vec4<T> v) { return vec2<T> (v.x, v.y); }

template <typename T> vec3<T> to_vec3 (vec2<T> v) { return vec3<T> (v.x, v.y, 0.0); }
template <typename T> vec3<T> to_vec3 (vec4<T> v) { return vec3<T> (v.x, v.y, v.z, 0.0); }

template <typename T> vec4<T> to_vec4 (vec2<T> v) { return vec4<T> (v.x, v.y, 0.0, 0.0); }
template <typename T> vec4<T> to_vec4 (vec3<T> v) { return vec4<T> (v.x, v.y, v.z, 0.0); }

// LINEAR INTERPOLATION

template <typename T> constexpr T lerp (T const& a, T const& b, T const& fact)
{
	return (static_cast<T> (1.0) - fact) * a + fact * b;
}

// CLAMP

template <typename T> T clamp (T const min, T const max, T const value)
{
	return value > min ? (value < max ? value : max) : min;
}

// MIN/MAX

template <typename T> T min (T const a, T const b) { return std::min (a, b); }

template <typename T> T max (T const a, T const b) { return std::max (a, b); }

// POW

// base raised to the exponent power
template <typename T> T pow (T const base, T const exp) { return std::pow (base, exp); }

// e to the base power
template <typename T> T pow (T const base) { return std::pow (base); }

// e to the base power
template <typename T> T pow2 (T const base) { return std::pow (base, 2.0); }


// LOG

// natural log of e
template <typename T> T log (T const base) { return std::log (base); }

// natural log of base
template <typename T> T log2 (T const base) { return std::log2 (base); }

// natural log of base
template <typename T> T log10 (T const base) { return std::log10 (base); }


// MIX

template <typename T, typename U> T mix (T const x, T const y, U const amount)
{
	return lerp (x, y, amount);
}

// TRIG

template <typename T> T sin (T const val) { return std::sin (val); }
template <typename T> T cos (T const val) { return std::cos (val); }
template <typename T> T tan (T const val) { return std::tan (val); }
template <typename T> T asin (T const val) { return std::sin (val); }
template <typename T> T acos (T const val) { return std::cos (val); }
template <typename T> T atan (T const val) { return std::tan (val); }

// DISTANCE
template <typename T> T distance (T const v1, T const v2) { return std::abs (v2 - v1); }

} // namespace cml
