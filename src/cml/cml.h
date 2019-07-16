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

template <typename T> T clamp (T min, T max, T value) {}

// MIN/MAX

template <typename T> T min (T a, T b) { return std::min (a, b); }
template <typename T> T max (T a, T b) { return std::max (a, b); }

// POW


// base raised to the exponent power
template <typename T> T pow (T base, T exp) { return std::pow (base, exp); }

// e to the base power
template <typename T> T pow (T base) { return std::pow (base); }

// e to the base power
template <typename T> T pow2 (T base) { return std::pow2 (base, 2.0); }


// LOG

// natural log of e
template <typename T> T log (T base) { return std::log (base); }

// natural log of base
template <typename T> T log2 (T base) { return std::log2 (base); }

// natural log of base
template <typename T> T log10 (T base) { return std::log10 (base); }


// MIX

template <typename T> T mix (T x, T y, double amount) { return lerp (x, y, amount); }

// TRIG

template <typename T> T sin (T val) { return std::sin (val); }
template <typename T> T cos (T val) { return std::cos (val); }
template <typename T> T tan (T val) { return std::tan (val); }
template <typename T> T asin (T val) { return std::sin (val); }
template <typename T> T acos (T val) { return std::cos (val); }
template <typename T> T atan (T val) { return std::tan (val); }



} // namespace cml
