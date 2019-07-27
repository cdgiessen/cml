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
using vec2i = vec2<int>;
using vec2f = vec2<float>;
using vec2d = vec2<double>;

using vec3i = vec3<int>;
using vec3f = vec3<float>;
using vec3d = vec3<double>;

using vec4i = vec4<int>;
using vec4f = vec4<float>;
using vec4d = vec4<double>;

// TO VEC2

template <typename T> vec2<T> to_vec2 (vec3<T> v) { return vec2<T> (v.x, v.y); }
template <typename T> vec2<T> to_vec2 (vec4<T> v) { return vec2<T> (v.x, v.y); }

// TO VEC3

template <typename T> vec3<T> to_vec3 (vec2<T> v, T z = (T)0.0) { return vec3<T> (v.x, v.y, z); }
template <typename T> vec3<T> to_vec3 (vec4<T> v) { return vec3<T> (v.x, v.y, v.z); }

// TO VEC4

template <typename T> vec4<T> to_vec4 (vec2<T> v, T z = (T)0.0, T w = (T)0.0)
{
	return vec4<T> (v.x, v.y, z, w);
}
template <typename T> vec4<T> to_vec4 (vec3<T> v, T w = (T)0.0)
{
	return vec4<T> (v.x, v.y, v.z, w);
}

// TO MAT3

template <typename T> mat3<T> to_mat3 (mat4<T> v)
{
	return mat3<T> (to_vec3<T> (v.get_row (0)), to_vec3<T> (v.get_row (1)), to_vec3<T> (v.get_row (2)));
}

// TO MAT4

template <typename T> mat4<T> to_mat4 (mat3<T> v, vec4<T> trans = vec4<T>::w_positive)
{
	mat4<T> ret = mat4<T> (
	    to_vec4<T> (v.get_row (0)), to_vec4<T> (v.get_row (1)), to_vec4<T> (v.get_row (2)), trans);
	return ret;
}

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

// base raised to the exp power
template <typename T> T pow (T const base, T const exp) { return std::pow (base, exp); }

// e to the exp power
template <typename T> T exp (T const exp) { return std::exp (exp); }

// 2 to the exp power
template <typename T> T exp2 (T const exp) { return std::exp2 (exp); }


// LOG

// natural log of base
template <typename T> T log (T const base) { return std::log (base); }

// log2 of base
template <typename T> T log2 (T const base) { return std::log2 (base); }

// log10 of base
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
