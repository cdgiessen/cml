#pragma once

#include <cassert>
#include <cmath>

namespace cml
{

template <typename T = float> class vec3
{
	public:
	T x = 0.f;
	T y = 0.f;
	T z = 0.f;

	// Default Constuctor
	constexpr vec3 () : x (0), y (0), z (0) {}

	// Initial value constructor
	constexpr vec3 (T x, T y, T z) : x (x), y (y), z (z) {}

	T* ptr () { return &x; }

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

	// scalar
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

	// scalar
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

	vec3<T> operator/ (const T val) const { return vec3<T> (x / val, y / val, z / val); }

	void operator/= (const T val)
	{
		x /= val;
		y /= val;
		z /= val;
	}

	// NEGATION

	vec3<T> operator- () const { return vec3<T> (-x, -y, -z); }


	// EQUALITY
	bool operator== (const vec3& val) const { return x == val.x && y == val.y && z == val.z; }

	bool operator!= (const vec3& val) const { return !(*this == val); }


	// DOT
	static T dot (const vec3<T>& a, const vec3<T>& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

	// CROSS
	static vec3<T> cross (const vec3<T>& a, const vec3<T>& b)
	{
		return vec3<T> (a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
	}

	// MAGNITUDE
	T mag (void) const { return (T)std::sqrt (x * x + y * y + z * z); }

	T magSqrd (void) const { return (x * x + y * y + z * z); }

	// NORMALIZE

	// normalizes this vector
	vec3<T> norm ()
	{
		T mag = (*this).mag ();
		x /= mag;
		y /= mag;
		z /= mag;
		return *this;
	}

	// normalizes a given vector
	vec3<T>& norm (vec3<T>& val) const
	{
		T mag = val.mag ();
		val.x /= mag;
		val.y /= mag;
		val.z /= mag;
		return (val);
	}

	// LERP
	vec3<T> lerp (const T fact, const vec3<T>& val) const
	{
		return (*this) + (val - (*this)) * fact;
	}

	// PROJECTION
	vec3<T> proj (const vec3<T>& p, const vec3<T>& q) const
	{
		return vec3<T> (q * (dot (p, q) / q.magSqrd ()));
	}

	// PERPINDICULAR
	vec3<T> perp (const vec3<T>& p, const vec3<T>& q) const { return vec3<T> (p - proj (p, q)); }

	// ANGLE between p and q
	// T angle(const vec3<T>& p, const vec3<T>& q) const {
	//	return acos(dot(norm(p), norm(q)));
	//}
	static const vec3<T> zero{ 0, 0, 0 };
	static const vec3<T> one{ 1, 1, 1 };
	static const vec3<T> right{ 1, 0, 0 };
	static const vec3<T> left{ -1, 0, 0 };
	static const vec3<T> up{ 0, 1, 0 };
	static const vec3<T> down{ 0, -1, 0 };
	static const vec3<T> forward{ 0, 0, 1 };
	static const vec3<T> back{ 0, 0, -1 };
};

using vec3f = vec3<float>;
using vec3i = vec3<int>;
using vec3d = vec3<double>;
} // namespace cml
