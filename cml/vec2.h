#pragma once

#include <cassert>
#include <cmath>

namespace cml
{

template <typename T = float> class alignas (sizeof (T) * 2) vec2
{
	public:
	T x = 0.f;
	T y = 0.f;

	constexpr vec2 () : {}

	constexpr vec2 (T x, T y) : x (x), y (y) {}

	T const* ptr () { return &x; }

	// returns constant address to the data
	static T const* ptr (vec2<T> const& vec) { return &(vec.x); }

	// ADDITIONS

	vec2<T> operator+ (const vec2<T> val) const { return vec2<T> (x + val.x, y + val.y); }

	void operator+= (const vec2<T> val)
	{
		x += val.x;
		y += val.y;
	}

	// scalar
	vec2<T> operator+ (const T val) const { return vec2<T> (x + val, y + val); }

	// SUBTRACTIONS

	vec2<T> operator- (const vec2<T> val) const { return vec2<T> (x - val.x, y - val.y); }

	void operator-= (const vec2<T> val)
	{
		x -= val.x;
		y -= val.y;
	}

	// scalar
	vec2<T> operator- (const T val) const { return vec2<T> (x - val, y - val); }

	// MULTIPLICATION

	vec2<T> operator* (const T val) const { return vec2<T> (x * val, y * val); }

	void operator*= (const T val)
	{
		x *= val;
		y *= val;
	}

	// DIVISION

	vec2<T> operator/ (const T val) const { return vec2<T> (x / val, y / val); }

	void operator/= (const T val)
	{
		x /= val;
		y /= val;
	}

	// NEGATION

	vec2<T> operator- () const { return vec2<T> (-x, -y); }

	// EQUALITY
	bool operator== (const vec2& val) const { return x == val.x && y == val.y; }

	bool operator!= (const vec2& val) const { return !(*this == val); }

	// DOT
	T dot (const vec2<T>& a, const vec2<T>& b) const { return a.x * b.x + a.y * b.y; }

	// MAGNITUDE
	T mag (void) const { return (T)std::sqrt (x * x + y * y); }

	T magSqrd (void) const { return (x * x + y * y); }

	// NORMALIZE

	void norm ()
	{
		T mag = (*this).mag ();
		x /= mag;
		y /= mag;
	}

	void norm (vec2<T>& val)
	{
		T mag = val.mag ();
		val.x /= mag;
		val.y /= mag;
	}

	// LERP
	vec2<T> lerp (const T fact, const vec2<T>& val) const
	{
		return (*this) + (val - (*this)) * fact;
	}

	// PROJECTION
	vec2<T> proj (const vec2<T>& p, const vec2<T>& q)
	{
		return vec2<T> (q * (dot (p, q) / q.magSqrd ()));
	}

	// PERPINDICULAR
	vec2<T> perp (const vec2<T>& p, const vec2<T>& q) { return vec2<T> (p - proj (p, q)); }

	static const vec2<float> zero (0, 0);
	static const vec2<float> one (1, 1);
	static const vec2<float> right (1, 0);
	static const vec2<float> left (-1, 0);
	static const vec2<float> up (0, 1);
	static const vec2<float> down (0, -1);
};


using vec2f = vec2<float>;
using vec2i = vec2<int>;
using vec2d = vec2<double>;

} // namespace cml
