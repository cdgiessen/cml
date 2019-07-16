#pragma once

#include <cassert>
#include <cmath>

namespace cml
{

template <typename T = float> class alignas (16) vec3
{
	public:
	T x = 0.f;
	T y = 0.f;
	T z = 0.f;

	// Default Constuctor
	constexpr vec3 () : x (0), y (0), z (0) {}

	constexpr vec3 (T fill) noexcept : x (fill), y (fill), z (fill) {}

	// Initial value constructor
	constexpr vec3 (T x, T y, T z) : x (x), y (y), z (z) {}

	T* ptr () const { return &x; }

	static T const* ptr (vec3<T> const& vec) { return &(vec.x); }


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

	// SUBTRACTOINS

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

	// DIVISION

	vec3<T> operator/ (T const val) const { return vec3<T> (x / val, y / val, z / val); }

	void operator/= (T const val)
	{
		x /= val;
		y /= val;
		z /= val;
	}

	// NEGATION

	vec3<T> operator- () const { return vec3<T> (-x, -y, -z); }


	// EQUALITY
	bool operator== (vec3 const& val) const { return x == val.x && y == val.y && z == val.z; }

	bool operator!= (vec3 const& val) const { return !(*this == val); }


	// MAGNITUDE
	T mag () const { return (T)std::sqrt (x * x + y * y + z * z); }

	static T mag (vec3<T> const& v) { return v.mag (); }

	// Magnitude w/o sqrt
	T mag_sqrt () const { return (x * x + y * y + z * z); }

	static T mag_sqrt (vec3<T> const& v) { return v.mag_sqrt (); }


	// NORMALIZE
	vec3<T> norm ()
	{
		T mag = (*this).mag ();
		x /= mag;
		y /= mag;
		z /= mag;
		return *this;
	}

	static vec3<T> normalize (vec3<T>& val)
	{
		vec3<T> out = val;
		T mag = val.mag ();
		out.x /= mag;
		out.y /= mag;
		out.z /= mag;
		return out;
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


using vec3f = vec3<float>;
using vec3i = vec3<int>;
using vec3d = vec3<double>;
} // namespace cml
