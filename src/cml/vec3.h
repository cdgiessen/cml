#pragma once

#include "common.h"

namespace cml
{

template <typename T = float> class alignas (16) vec3
{
	public:
	T x = 0.f;
	T y = 0.f;
	T z = 0.f;

	constexpr vec3 () : x (0), y (0), z (0) {}

	constexpr vec3 (T fill) noexcept : x (fill), y (fill), z (fill) {}

	constexpr vec3 (T x, T y, T z) : x (x), y (y), z (z) {}

	T* ptr () const { return &x; }

	static T const* ptr (vec3<T> const& vec) { return &(vec.x); }

	T get (int i) const
	{
		assert (i >= 0 && i <= 2);
		return *(&x + i);
	}

	// ADDITIONS

	vec3<T> operator+ (vec3<T> const rhs) const
	{
		return vec3<T> (x + rhs.x, y + rhs.y, z + rhs.z);
	}

	void operator+= (vec3<T> const val)
	{
		x += val.x;
		y += val.y;
		z += val.z;
	}

	vec3<T> operator+ (T const val) const { return vec3<T> (x + val, y + val, z + val); }

	// SUBTRACTIONS

	vec3<T> operator- (vec3<T> const val) const
	{
		return vec3<T> (x - val.x, y - val.y, z - val.z);
	}

	void operator-= (vec3<T> const val)
	{
		x -= val.x;
		y -= val.y;
		z -= val.z;
	}

	vec3<T> operator- (T const val) const { return vec3<T> (x - val, y - val, z - val); }

	void operator-= (T const val)
	{
		x -= val;
		y -= val;
		z -= val;
	}


	// MULTIPLICATION

	vec3<T> operator* (T const val) const { return vec3<T> (x * val, y * val, z * val); }

	void operator*= (T const val)
	{
		x *= val;
		y *= val;
		z *= val;
	}

	vec3<T> operator* (vec3<T> const val) const
	{
		return vec3<T> (x * val.x, y * val.y, z * val.z);
	}

	void operator*= (vec3<T> const val)
	{
		x *= val.x;
		y *= val.y;
		z *= val.z;
	}

	// DIVISION

	vec3<T> operator/ (T const val) const { return vec3<T> (x / val, y / val, z / val); }

	void operator/= (T const val)
	{
		x /= val;
		y /= val;
		z /= val;
	}

	vec3<T> operator/ (vec3<T> const val) const
	{
		return vec3<T> (x / val.x, y / val.y, z / val.z);
	}

	void operator/= (vec3<T> const val)
	{
		x /= val.x;
		y /= val.y;
		z /= val.z;
	}

	// NEGATION

	vec3<T> operator- () const { return vec3<T> (-x, -y, -z); }


	// EQUALITY
	bool operator== (vec3 const& val) const { return x == val.x && y == val.y && z == val.z; }

	bool operator!= (vec3 const& val) const { return !(*this == val); }


	// LENGTH
	T length () const { return (T)std::sqrt (x * x + y * y + z * z); }

	static T length (vec3<T> const& v) { return v.length (); }

	// Magnitude w/o sqrt
	T mag_sqrt () const { return (x * x + y * y + z * z); }

	static T mag_sqrt (vec3<T> const& v) { return v.mag_sqrt (); }


	// NORMALIZE
	vec3<T> norm ()
	{
		T mag = (*this).length ();
		x /= mag;
		y /= mag;
		z /= mag;
		return *this;
	}

	// ANGLE between p and q
	// T angle(const vec3<T>& p, const vec3<T>& q) const {
	//	return acos(dot(norm(p), norm(q)));
	//}

	static const vec3<T> one;
	static const vec3<T> zero;
	static const vec3<T> right;
	static const vec3<T> left;
	static const vec3<T> up;
	static const vec3<T> down;
	static const vec3<T> forward;
	static const vec3<T> back;
};
template <typename T> const vec3<T> vec3<T>::one = { 1, 1, 1 };
template <typename T> const vec3<T> vec3<T>::zero = { 0, 0, 0 };
template <typename T> const vec3<T> vec3<T>::right = { 1, 0, 0 };
template <typename T> const vec3<T> vec3<T>::left = { -1, 0, 0 };
template <typename T> const vec3<T> vec3<T>::up = { 0, 1, 0 };
template <typename T> const vec3<T> vec3<T>::down = { 0, -1, 0 };
template <typename T> const vec3<T> vec3<T>::forward = { 0, 0, 1 };
template <typename T> const vec3<T> vec3<T>::back = { 0, 0, -1 };

template <typename T> vec3<T> operator+ (T const& val, vec3<T> const& v)
{
	return vec3<T> (val + v.x, val + v.y, val + v.z);
}
template <typename T> vec3<T> operator- (T const& val, vec3<T> const& v)
{
	return vec3<T> (val - v.x, val - v.y, val - v.z);
}
template <typename T> vec3<T> operator* (T const& val, vec3<T> const& v)
{
	return vec3<T> (val * v.x, val * v.y, val * v.z);
}
template <typename T> vec3<T> operator/ (T const& val, vec3<T> const& v)
{
	return vec3<T> (val / v.x, val / v.y, val / v.z);
}

// NORMALIZE

template <typename T> vec3<T> normalize (vec3<T> const& val)
{
	vec3<T> out = val;
	T mag = val.length ();
	out.x /= mag;
	out.y /= mag;
	out.z /= mag;
	return out;
}


// DOT PRODUCT

template <typename T> constexpr T dot (vec3<T> const& a, vec3<T> const& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// CROSS PRODUCT

template <typename T> constexpr vec3<T> cross (vec3<T> const& a, vec3<T> const& b)
{
	return vec3<T> (a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
}

// LINEAR INTERPOLATION

template <typename T>
constexpr vec3<T> lerp (vec3<T> const& a, vec3<T> const& b, vec3<T> const& fact)
{
	return vec3<T> ((static_cast<T> (1.0) - fact.x) * a.x + fact.x * b.x,
	    (static_cast<T> (1.0) - fact.y) * a.y + fact.y * b.y,
	    (static_cast<T> (1.0) - fact.z) * a.z + fact.z * b.z);
}

template <typename T> constexpr vec3<T> lerp (vec3<T> const& a, vec3<T> const& b, T const& fact)
{
	return vec3<T> ((static_cast<T> (1.0) - fact) * a.x + fact * b.x,
	    (static_cast<T> (1.0) - fact) * a.y + fact * b.y,
	    (static_cast<T> (1.0) - fact) * a.z + fact * b.z);
}

// PROJECTION

template <typename T> constexpr vec3<T> proj (vec3<T> const& p, vec3<T> const& q)
{
	return (q * (dot (p, q) / q.mag_sqrt ()));
}

// PERPINDICULAR

template <typename T> constexpr vec3<T> perp (vec3<T> const& p, vec3<T> const& q)
{
	return (p - proj (p, q));
}

// CLAMP

template <typename T> vec3<T> clamp (vec3<T> min, vec3<T> max, vec3<T> value)
{
	return vec3<T> (value.x > min.x ? (value.x < max.x ? value.x : max.x) : min.x,
	    value.y > min.y ? (value.y < max.y ? value.y : max.y) : min.y,
	    value.z > min.z ? (value.z < max.z ? value.z : max.z) : min.z);
}
template <typename T> vec3<T> clamp (vec3<T> min, vec3<T> max, T value)
{
	return vec3<T> (value > min.x ? (value < max.x ? value : max.x) : min.x,
	    value > min.y ? (value < max.y ? value : max.y) : min.y,
	    value > min.z ? (value < max.z ? value : max.z) : min.z);
}

// MIN/MAX

template <typename T> vec3<T> min (vec3<T> const a, vec3<T> const b)
{
	return vec3<T> (std::min (a.x, b.x), std::min (a.y, b.y), std::min (a.z, b.z));
}

template <typename T> vec3<T> max (vec3<T> const a, vec3<T> const b)
{
	return vec3<T> (std::max (a.x, b.x), std::max (a.y, b.y), std::max (a.z, b.z));
}

// DISTANCE

template <typename T> vec3<T> distance (vec3<T> const v1, vec3<T> const v2)
{
	return (v2 - v1).length ();
}

// base raised to the exp power
template <typename T> vec3<T> pow (vec3<T> const base, vec3<T> const exp)
{
	return vec3<T> (std::pow (base.x, exp.x), std::pow (base.y, exp.y), std::pow (base.z, exp.z));
}

// e to the exp power
template <typename T> vec3<T> pow (vec3<T> const exp)
{
	return vec3<T> (std::exp (exp.x), std::exp (exp.y), std::exp (exp.z));
}

// 2 to the exp power
template <typename T> vec3<T> exp2 (vec3<T> const exp)
{
	return vec3<T> (std::pow (exp.x), std::exp2 (exp.y), std::exp2 (exp.z));
}


// LOG

// natural log of base
template <typename T> vec3<T> log (vec3<T> const base)
{
	return vec3<T> (std::log (base.x), std::log (base.y), std::log (base.z));
}

// log2 of base
template <typename T> vec3<T> log2 (vec3<T> const base)
{
	return vec3<T> (std::log2 (base.x), std::log2 (base.y), std::log2 (base.z));
}

// log10 of base
template <typename T> vec3<T> log10 (vec3<T> const base)
{
	return vec3<T> (std::log10 (base.x), std::log10 (base.y), std::log10 (base.z));
}

} // namespace cml
