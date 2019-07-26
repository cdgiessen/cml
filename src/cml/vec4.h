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

	T get (int i) const
	{
		assert (i >= 0 && i <= 3);
		return *(&x + i);
	}

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

	vec4<T> operator* (vec4<T> const val) const
	{
		return vec4<T> (x * val.x, y * val.y, z * val.z, w * val.w);
	}

	void operator*= (vec4<T> const val)
	{
		x *= val.x;
		y *= val.y;
		z *= val.z;
		w *= val.w;
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

	vec4<T> operator/ (vec4<T> const val) const
	{
		return vec4<T> (x / val.x, y / val.y, z / val.z, w / val.w);
	}

	void operator/= (vec4<T> const val)
	{
		x /= val.x;
		y /= val.y;
		z /= val.z;
		w /= val.w;
	}

	// NEGATION

	vec4<T> operator- () const { return vec4<T> (-x, -y, -z, -w); }


	// EQUALITY
	bool operator== (const vec4<T>& val) const
	{
		return x == val.x && y == val.y && z == val.z && w == val.w;
	}

	bool operator!= (const vec4<T>& val) const { return !(*this == val); }


	// LENGTH
	T length () const { return (T)std::sqrt (x * x + y * y + z * z + w * w); }

	static T length (vec4<T> const& v) { return v.length (); }

	// Magnitude w/o sqrt
	T mag_sqrt () const { return (x * x + y * y + z * z + w * w); }

	static T mag_sqrt (vec4<T> const& v) { return v.mag_sqrt (); }


	// NORMALIZE

	void norm ()
	{
		T mag = (*this).length ();
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
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

// NORMALIZE

template <typename T> vec4<T> normalize (vec4<T> const& val)
{
	vec4<T> out = val;
	T mag = val.length ();
	out.x /= mag;
	out.y /= mag;
	out.z /= mag;
	out.w /= mag;
	return out;
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


// CLAMP

template <typename T> vec4<T> clamp (vec4<T> min, vec4<T> max, vec4<T> value)
{
	return vec4<T> (value.x > min.x ? (value.x < max.x ? value.x : max.x) : min.x,
	    value.y > min.y ? (value.y < max.y ? value.y : max.y) : min.y,
	    value.z > min.z ? (value.z < max.z ? value.z : max.z) : min.z,
	    value.w > min.w ? (value.w < max.w ? value.w : max.w) : min.w);
}
template <typename T> vec4<T> clamp (vec4<T> min, vec4<T> max, T value)
{
	return vec4<T> (value > min.x ? (value < max.x ? value : max.x) : min.x,
	    value > min.y ? (value < max.y ? value : max.y) : min.y,
	    value > min.z ? (value < max.z ? value : max.z) : min.z,
	    value > min.w ? (value < max.w ? value : max.w) : min.w);
}

// MIN/MAX

template <typename T> vec4<T> min (vec4<T> const a, vec4<T> const b)
{
	return vec4<T> (std::min (a.x, b.x), std::min (a.y, b.y), std::min (a.z, b.z), std::min (a.w, b.w));
}

template <typename T> vec4<T> max (vec4<T> const a, vec4<T> const b)
{
	return vec4<T> (std::max (a.x, b.x), std::max (a.y, b.y), std::max (a.z, b.z), std::max (a.w, b.w));
}

// DISTANCE

template <typename T> vec4<T> distance (vec4<T> const v1, vec4<T> const v2)
{
	return (v2 - v1).length ();
}

// base raised to the exp power
template <typename T> vec4<T> pow (vec4<T> const base, vec4<T> const exp)
{
	return vec4<T> (
	    std::pow (base.x, exp.x), std::pow (base.y, exp.y), std::pow (base.z, exp.z), std::pow (base.w, exp.w));
}

// e to the exp power
template <typename T> vec4<T> pow (vec4<T> const exp)
{
	return vec4<T> (std::exp (exp.x), std::exp (exp.y), std::exp (exp.z), std::exp (exp.w));
}

// 2 to the exp power
template <typename T> vec4<T> exp2 (vec4<T> const exp)
{
	return vec4<T> (std::pow (exp.x), std::exp2 (exp.y), std::exp2 (exp.z), std::exp2 (exp.w));
}

// LOG

// natural log of base
template <typename T> vec4<T> log (vec4<T> const base)
{
	return vec4<T> (std::log (base.x), std::log (base.y), std::log (base.z), std::log (base.w));
}

// log2 of base
template <typename T> vec4<T> log2 (vec4<T> const base)
{
	return vec4<T> (std::log2 (base.x), std::log2 (base.y), std::log2 (base.z), std::log2 (base.w));
}

// log10 of base
template <typename T> vec4<T> log10 (vec4<T> const base)
{
	return vec4<T> (std::log10 (base.x), std::log10 (base.y), std::log10 (base.z), std::log10 (base.w));
}

} // namespace cml
