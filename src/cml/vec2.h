#pragma once

#include "common.h"

namespace cml
{

template <typename T = float> class alignas (8) vec2
{
	public:
	T x = 0.f;
	T y = 0.f;

	constexpr vec2 () noexcept {}

	constexpr vec2 (T fill) noexcept : x (fill), y (fill) {}

	constexpr vec2 (T x, T y) noexcept : x (x), y (y) {}

	T const* ptr () const { return &x; }

	// returns constant address to the data
	static T const* ptr (vec2<T> const& vec) { return &(vec.x); }

	T get (int i) const
	{
		assert (i >= 0 && i <= 1);
		return *(&x + i);
	}

	// ADDITIONS

	vec2<T> operator+ (vec2<T> const& val) const { return vec2<T> (x + val.x, y + val.y); }

	void operator+= (vec2<T> const& val)
	{
		x += val.x;
		y += val.y;
	}

	vec2<T> operator+ (T const val) const { return vec2<T> (x + val, y + val); }

	// SUBTRACTIONS

	vec2<T> operator- (vec2<T> const& val) const { return vec2<T> (x - val.x, y - val.y); }

	void operator-= (vec2<T> const& val)
	{
		x -= val.x;
		y -= val.y;
	}

	// scalar
	vec2<T> operator- (T const val) const { return vec2<T> (x - val, y - val); }

	// MULTIPLICATION

	vec2<T> operator* (T const val) const { return vec2<T> (x * val, y * val); }

	void operator*= (T const val)
	{
		x *= val;
		y *= val;
	}

	vec2<T> operator* (vec2<T> const val) const { return vec2<T> (x * val.x, y * val.y); }

	void operator*= (vec2<T> const val)
	{
		x *= val.x;
		y *= val.y;
	}

	// DIVISION

	vec2<T> operator/ (T const val) const { return vec2<T> (x / val, y / val); }

	void operator/= (T const val)
	{
		x /= val;
		y /= val;
	}

	vec2<T> operator/ (vec2<T> const val) const { return vec2<T> (x / val.x, y / val.y); }

	void operator/= (vec2<T> const val)
	{
		x /= val.x;
		y /= val.y;
	}

	// NEGATION

	vec2<T> operator- () const { return vec2<T> (-x, -y); }

	// EQUALITY
	bool operator== (vec2 const& val) const { return x == val.x && y == val.y; }

	bool operator!= (vec2 const& val) const { return !(*this == val); }

	// LENGTH
	T length () const { return (T)std::sqrt (x * x + y * y); }

	static T length (vec2<T> const& v) { return v.length (); }

	// Magnitude w/o sqrt
	T mag_sqrt () const { return (x * x + y * y); }

	static T mag_sqrt (vec2<T> const& v) { return v.mag_sqrt (); }


	// NORMALIZE

	void norm ()
	{
		T mag = length ();
		x /= mag;
		y /= mag;
	}

	static const vec2<T> one;
	static const vec2<T> zero;
	static const vec2<T> right;
	static const vec2<T> left;
	static const vec2<T> up;
	static const vec2<T> down;
};
template <typename T> const vec2<T> vec2<T>::one = { 1, 1 };
template <typename T> const vec2<T> vec2<T>::zero = { 0, 0 };
template <typename T> const vec2<T> vec2<T>::right = { 1, 0 };
template <typename T> const vec2<T> vec2<T>::left = { -1, 0 };
template <typename T> const vec2<T> vec2<T>::up = { 0, 1 };
template <typename T> const vec2<T> vec2<T>::down = { 0, -1 };

template <typename T> vec2<T> operator+ (T const& val, vec2<T> const& v)
{
	return vec2<T> (val + v.x, val + v.y);
}
template <typename T> vec2<T> operator- (T const& val, vec2<T> const& v)
{
	return vec2<T> (val - v.x, val - v.y);
}
template <typename T> vec2<T> operator* (T const& val, vec2<T> const& v)
{
	return vec2<T> (val * v.x, val * v.y);
}
template <typename T> vec2<T> operator/ (T const& val, vec2<T> const& v)
{
	return vec2<T> (val / v.x, val / v.y);
}

template <typename T> vec2<T> operator+ (T& val, vec2<T>& v)
{
	return vec2<T> (val + v.x, val + v.y);
}
template <typename T> vec2<T> operator- (T& val, vec2<T>& v)
{
	return vec2<T> (val - v.x, val - v.y);
}
template <typename T> vec2<T> operator* (T& val, vec2<T>& v)
{
	return vec2<T> (val * v.x, val * v.y);
}
template <typename T> vec2<T> operator/ (T& val, vec2<T>& v)
{
	return vec2<T> (val / v.x, val / v.y);
}

// NORMALIZE

template <typename T> vec2<T> normalize (vec2<T> const& val)
{
	vec2<T> out = val;
	T mag = val.length ();
	out.x /= mag;
	out.y /= mag;
	return out;
}

// DOT PRODUCT

template <typename T> constexpr T dot (vec2<T> const& a, vec2<T> const& b)
{
	return a.x * b.x + a.y * b.y;
}

// LINEAR INTERPOLATION

template <typename T>
constexpr vec2<T> lerp (vec2<T> const& a, vec2<T> const& b, vec2<T> const& fact)
{
	return vec2<T>{ (static_cast<T> (1.0) - fact.x) * a.x + fact.x * b.x,
		(static_cast<T> (1.0) - fact.y) * a.y + fact.y * b.y };
}

template <typename T> constexpr vec2<T> lerp (vec2<T> const& a, vec2<T> const& b, T const& fact)
{
	return vec2<T>{ (static_cast<T> (1.0) - fact) * a.x + fact * b.x,
		(static_cast<T> (1.0) - fact) * a.y + fact.y * b.y };
}

// PROJECTION

template <typename T> constexpr vec2<T> proj (vec2<T> const& p, vec2<T> const& q)
{
	return (q * (dot (p, q) / q.mag_sqrt ()));
}

// PERPINDICULAR

template <typename T> constexpr vec2<T> perp (vec2<T> const& p, vec2<T> const& q)
{
	return (p - proj (p, q));
}

// CLAMP

template <typename T> vec2<T> clamp (vec2<T> min, vec2<T> max, vec2<T> value)
{
	return vec2<T> (value.x > min.x ? (value.x < max.x ? value.x : max.x) : min.x,
	    value.y > min.y ? (value.y < max.y ? value.y : max.y) : min.y);
}
template <typename T> vec2<T> clamp (vec2<T> min, vec2<T> max, T value)
{
	return vec2<T> (value > min.x ? (value < max.x ? value : max.x) : min.x,
	    value > min.y ? (value < max.y ? value : max.y) : min.y);
}

// MIN/MAX

template <typename T> vec2<T> min (vec2<T> const a, vec2<T> const b)
{
	return vec2<T> (std::min (a.x, b.x), std::min (a.y, b.y));
}

template <typename T> vec2<T> max (vec2<T> const a, vec2<T> const b)
{
	return vec2<T> (std::max (a.x, b.x), std::max (a.y, b.y));
}

// DISTANCE

template <typename T> vec2<T> distance (vec2<T> const v1, vec2<T> const v2)
{
	return (v2 - v1).length ();
}

// base raised to the exp power
template <typename T> vec2<T> pow (vec2<T> const base, vec2<T> const exp)
{
	return vec2<T> (std::pow (base.x, exp.x), std::pow (base.y, exp.y));
}

// e to the exp power
template <typename T> vec2<T> pow (vec2<T> const exp)
{
	return vec2<T> (std::exp (exp.x), std::exp (exp.y));
}

// 2 to the exp power
template <typename T> vec2<T> exp2 (vec2<T> const exp)
{
	return vec2<T> (std::pow (exp.x), std::exp2 (exp.y));
}


// LOG

// natural log of base
template <typename T> vec2<T> log (vec2<T> const base)
{
	return vec2<T> (std::log (base.x), std::log (base.y));
}

// log2 of base
template <typename T> vec2<T> log2 (vec2<T> const base)
{
	return vec2<T> (std::log2 (base.x), std::log2 (base.y));
}

// log10 of base
template <typename T> vec2<T> log10 (vec2<T> const base)
{
	return vec2<T> (std::log10 (base.x), std::log10 (base.y));
}

} // namespace cml
