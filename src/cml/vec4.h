#pragma once

#include <cassert>
#include <cmath>

namespace cml
{

template <typename T = float> class alignas (16) vec4
{
	public:
	T x = 0.f;
	T y = 0.f;
	T z = 0.f;
	T w = 0.f;


	// Default Constuctor
	constexpr vec4 () : x (0), y (0), z (0), w (0) {}

	constexpr vec4 (T fill) noexcept : x (fill), y (fill), z (fill), w (fill) {}

	// Initial value constructor
	constexpr vec4 (const T xVal, const T yVal, const T zVal, const T wVal)
	: x (xVal), y (yVal), z (zVal), w (wVal)
	{
	}

	// returns constant address to the data
	T* ptr () const { return &x; }

	static T const* ptr (vec4<T> const& vec) { return &(vec.x); }

	// ADDITIONS

	vec4<T> operator+ (const vec4<T> rhs) const
	{
		return vec4<T> (x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	}

	void operator+= (const vec4<T> val)
	{
		x += val.x;
		y += val.y;
		z += val.z;
		w += val.w;
	}

	// scalar
	vec4<T> operator+ (const T val) const { return vec4<T> (x + val, y + val, z + val, w + val); }

	// SUBTRACTOINS

	vec4<T> operator- (const vec4<T> val) const
	{
		return vec4<T> (x - val.x, y - val.y, z - val.z, w - val.w);
	}

	void operator-= (const vec4<T> val)
	{
		x -= val.x;
		y -= val.y;
		z -= val.z;
		w -= val.w;
	}

	// scalar
	vec4<T> operator- (const T val) const { return vec4<T> (x - val, y - val, z - val, w - val); }

	// MULTIPLICATION

	vec4<T> operator* (const T val) const { return vec4<T> (x * val, y * val, z * val, w * val); }

	void operator*= (const T val)
	{
		x *= val;
		y *= val;
		z *= val;
		w *= val;
	}

	// DIVISION

	vec4<T> operator/ (const T val) const { return vec4<T> (x / val, y / val, z / val, w / val); }

	void operator/= (const T val)
	{
		x /= val;
		y /= val;
		z /= val;
		w /= val;
	}

	// NEGATION

	vec4<T> operator- () const { return vec4<T> (-x, -y, -z, -w); }


	// EQUALITY
	bool operator== (const vec4<T>& val) const
	{
		return x == val.x && y == val.y && z == val.z && w == val.w;
	}

	bool operator!= (const vec4<T>& val) const { return !(*this == val); }


	// MAGNITUDE
	T mag () const { return (T)std::sqrt (x * x + y * y + z * z + w * w); }

	static T mag (vec4<T> const& v) { return v.mag (); }

	// Magnitude w/o sqrt
	T mag_sqrt () const { return (x * x + y * y + z * z + w * w); }

	static T mag_sqrt (vec4<T> const& v) { return v.mag_sqrt (); }


	// NORMALIZE

	void norm ()
	{
		T mag = (*this).mag ();
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
	}

	static vec4<T> normalize (vec4<T>& val)
	{
		vec4<T> out = val;
		T mag = val.mag ();
		out.x /= mag;
		out.y /= mag;
		out.z /= mag;
		out.w /= mag;
		return out;
	}

	static const vec4<T> one;
	static const vec4<T> zero;
	static const vec4<T> right;
	static const vec4<T> left;
	static const vec4<T> up;
	static const vec4<T> down;
	static const vec4<T> forward;
	static const vec4<T> back;
	static const vec4<T> w_positive;
	static const vec4<T> w_negative;
};
template <typename T> const vec4<T> vec4<T>::one = { 1, 1, 1, 1 };
template <typename T> const vec4<T> vec4<T>::zero = { 0, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::right = { 1, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::left = { -1, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::up = { 0, 1, 0, 0 };
template <typename T> const vec4<T> vec4<T>::down = { 0, -1, 0, 0 };
template <typename T> const vec4<T> vec4<T>::forward = { 0, 0, 1, 0 };
template <typename T> const vec4<T> vec4<T>::back = { 0, 0, -1, 0 };
template <typename T> const vec4<T> vec4<T>::w_positive = { 0, 0, 0, 1 };
template <typename T> const vec4<T> vec4<T>::w_negative = { 0, 0, 0, -1 };

template <typename T> vec4<T> operator+ (T const& val, vec4<T> const& v)
{
	return vec4<T> (val + v.x, val + v.y, val + v.z, val + v.w);
}
template <typename T> vec4<T> operator- (T const& val, vec4<T> const& v)
{
	return vec4<T> (val - v.x, val - v.y, val - v.z, val - v.w);
}
template <typename T> vec4<T> operator* (T const& val, vec4<T> const& v)
{
	return vec4<T> (val * v.x, val * v.y, val * v.z, val * v.w);
}
template <typename T> vec4<T> operator/ (T const& val, vec4<T> const& v)
{
	return vec4<T> (val / v.x, val / v.y, val / v.z, val / v.w);
}

// DOT PRODUCT

template <typename T> constexpr T dot (vec4<T> const& a, vec4<T> const& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

// LINEAR INTERPOLATION

template <typename T>
constexpr vec4<T> lerp (vec4<T> const& a, vec4<T> const& b, vec4<T> const& fact)
{
	return vec4<T> ((static_cast<T> (1.0) - fact.x) * a.x + fact.x * b.x,
	    (static_cast<T> (1.0) - fact.y) * a.y + fact.y * b.y,
	    (static_cast<T> (1.0) - fact.z) * a.z + fact.z * b.z,
	    (static_cast<T> (1.0) - fact.w) * a.w + fact.w * b.w);
}

template <typename T> constexpr vec4<T> lerp (vec4<T> const& a, vec4<T> const& b, T const& fact)
{
	return vec4<T> ((static_cast<T> (1.0) - fact) * a.x + fact * b.x,
	    (static_cast<T> (1.0) - fact) * a.y + fact * b.y,
	    (static_cast<T> (1.0) - fact) * a.z + fact * b.z,
	    (static_cast<T> (1.0) - fact) * a.w + fact * b.w);
}
// PROJECTION

template <typename T> constexpr vec4<T> proj (vec4<T> const& p, vec4<T> const& q)
{
	return (q * (dot (p, q) / q.mag_sqrt ()));
}

// PERPINDICULAR

template <typename T> constexpr vec4<T> perp (vec4<T> const& p, vec4<T> const& q)
{
	return (p - proj (p, q));
}


using vec4f = vec4<float>;
using vec4i = vec4<int>;
using vec4d = vec4<double>;


} // namespace cml
