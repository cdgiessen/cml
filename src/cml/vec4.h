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

	// Initial value constructor
	constexpr vec4 (const T xVal, const T yVal, const T zVal, const T wVal)
	: x (xVal), y (yVal), z (zVal), w (wVal)
	{
	}

	// returns constant address to the data
	T* ptr () { return &x; }

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


	// DOT
	T dot (const vec4<T>& a, const vec4<T>& b) const
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	// MAGNITUDE
	T mag (void) const { return (T)std::sqrt (x * x + y * y + z * z + w * w); }

	T magSqrd (void) const { return (x * x + y * y + z * z + w * w); }

	// NORMALIZE

	void norm ()
	{
		if (mag () != 0)
		{
			T mag = (*this).mag ();
			x /= mag;
			y /= mag;
			z /= mag;
			w /= mag;
		}
	}

	// normalizes a given vector
	static vec4<T>& norm (vec4<T>& val)
	{
		T mag = val.mag ();
		val.x /= mag;
		val.y /= mag;
		val.z /= mag;
		val.w /= mag;
		return (val);
	}

	// LERP
	vec4<T> lerp (const T fact, const vec4<T>& val) const
	{
		return (*this) + (val - (*this)) * fact;
	}

	// PROJECTION
	vec4<T> proj (const vec4<T>& p, const vec4<T>& q) const
	{
		return vec4<T> (q * (dot (p, q) / q.magSqrd ()));
	}

	// PERPINDICULAR
	vec4<T> perp (const vec4<T>& p, const vec4<T>& q) const { return vec4<T> (p - proj (p, q)); }

	static const vec4<T> one;
	static const vec4<T> zero;
	static const vec4<T> right;
	static const vec4<T> left;
	static const vec4<T> up;
	static const vec4<T> down;
	static const vec4<T> forward;
	static const vec4<T> back;
};
template <typename T> const vec4<T> vec4<T>::one = { 1, 1, 1, 1 };
template <typename T> const vec4<T> vec4<T>::zero = { 0, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::right = { 1, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::left = { -1, 0, 0, 0 };
template <typename T> const vec4<T> vec4<T>::up = { 0, 1, 0, 0 };
template <typename T> const vec4<T> vec4<T>::down = { 0, -1, 0, 0 };
template <typename T> const vec4<T> vec4<T>::forward = { 0, 0, 1, 0 };
template <typename T> const vec4<T> vec4<T>::back = { 0, 0, -1, 0 };


using vec4f = vec4<float>;
using vec4i = vec4<int>;
using vec4d = vec4<double>;


} // namespace cml
