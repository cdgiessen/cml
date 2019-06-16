#pragma once

/*
return euler angle representation (vec3)

look rotation - Creates a rotation with the specified forward and upwards directions.
#euler - Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis,
and y degrees around the y axis (in that order). slerp - Spherically interpolates between a and b by
t. The parameter t is clamped to the range [0, 1]. fromToRotation - Creates a rotation which rotates
from fromDirection to toDirection. #identity - static var #other constant ones

set (x,y,z,w)
set From To Rotation - creates a rotation from FromRotation to ToRotation
ToAngleAxis 	Converts a rotation to angle-axis representation (angles in degrees).
angle - Returns the angle in degrees between two rotations a and b.

#axisangles - Creates a rotation which rotates angle degrees around axis.
dot - The dot product between two rotations.
#inverse - Returns the Inverse of rotation.
rotate towards - 	Rotates a rotation from towards to.


Operators
# + += - -= *
# == != *(combine lhs with rhs)
*/

#include "vec3.h"

namespace cml
{

template <typename T> class alignas (sizeof (T) * 4) quat
{
	private:
	vec3<T> imag;
	T real = 1.f; // Real Part

	public:
	constexpr quat () : imag{}, real (1.f) {}

	constexpr quat (const vec3<T>& imag, const T real) : imag (imag), real (real) {}

	// returns pointer to the data
	static T const* ptr (quat<T> const& vec) { return &(vec.x); }

	T const* ptr () { return &x; }

	// Returns a vector of the imaginary part of a quaternion
	vec3<T> getImag () { return vec3<T> (x, y, z); }

	T getReal (){ return w };

	// OPERATORS

	// Quaternion Addition
	quat<T> operator+ (const quat<T> val) const
	{
		return quat<T> (x + val.x, y + val.y, z + val.z, w + val.w);
	}

	// Addition
	void operator+= (const quat<T> val)
	{
		x += val.x;
		y += val.y;
		z += val.z;
		w += val.w;
	}

	// Quaternion Subtraction
	quat<T> operator- (const quat<T> val) const
	{
		return quat<T> (x - val.x, y - val.y, z - val.z, w - val.w);
	}

	// Subtraction
	void operator-= (const quat<T> val)
	{
		x -= val.x;
		y -= val.y;
		z -= val.z;
		w -= val.w;
	}

	// Scalar Multiplication
	quat<T> operator* (const T val) const { return quat<T> (val * x, val * y, val * z, val * w); }

	// Quaternion multiplication
	quat<T> operator* (const quat<T> val) const
	{
		return quat<T> (w * val.x - x * val.w + y * val.z - z * val.y,
		    w * val.y - x * val.z + y * val.w + z * val.x,
		    w * val.z + x * val.y - y * val.x + z * val.w,
		    w * val.w - x * val.x - y * val.y - z * val.z);
	}

	// EQUALITY
	bool operator== (const quat<T>& val) const
	{
		return x == val.x && y == val.y && z == val.z && w == val.w;
	}

	bool operator!= (const quat<T>& val) const { return !(*this == val); }

	// Negation
	quat<T> operator- () const { return quat<T> (-x, -y, -z, -w); }

	// Conjugate, only inverts the imaginary portion
	quat<T> operator~ () const { return quat<T> (-x, -y, -z, w); }

	// MAGNITUDE
	T mag () const { return (T)std::sqrt (x * x + y * y + z * z + w * w); }

	T magSqrd (void) const { return (x * x + y * y + z * z + w * w); }

	// Normalize
	void norm ()
	{
		T mag = (*this).mag ();
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
	}

	// normalizes a given quaternion
	quat<T>& norm (quat<T>& val) const
	{
		T mag = val.mag ();
		val.x /= mag;
		val.y /= mag;
		val.z /= mag;
		val.w /= mag;
		return (val);
	}

	// Gets an inverse quaternion of this one
	quat<T> inverse ()
	{
		T mag = (*this).magSqrd ();
		return quat<T> (-x / mag, -y / mag, -z / mag, w / mag);
	}

	vec3<T> rotate (const vec3<T> vecIN)
	{

		return (((*this) * quat<T> (vecIN, 0)) * inverse ()).getImag ();
	}

	static vec3<T> rotate (const vec3<T> vecIN, quat<T> quatIN)
	{

		return ((quatIN * quat<T> (vecIN, 0)) * quatIN.inverse ()).getImag ();
	}

	// axisangles - Creates a rotation which rotates angle degrees around axis.
	static quat<T> axisAngles (vec3<T> axis, T degrees)
	{
		double angleRad = degToRad (degrees);
		double sin_anlge_div2 = std::sin (angleRad / 2);
		double cos_anlge_div2 = std::cos (angleRad / 2);
		return quat<T> (axis * sin_anlge_div2, cos_anlge_div2);
	}

	static quat<T> axisAngles (T x, T y, T z, T degrees)
	{
		return axisAngles (vec3<T> (x, y, z), degrees);
	}

	// Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis, and y degrees around the y axis(in that order).
	static quat<T> fromEulerAngles (T x, T y, T z)
	{
		return quat<T> (axisAngles (vec3<T> (1, 0, 0), x) * axisAngles (vec3<T> (0, 1, 0), y) *
		                axisAngles (vec3<T> (0, 0, 1), z));
	}

	static vec3<T> axis (quat<T> const& x)
	{
		T tmp1 = static_cast<T> (1) - x.w * x.w;
		if (tmp1 <= static_cast<T> (0)) return vec3<T> (0, 0, 1);
		T tmp2 = static_cast<T> (1) / sqrt (tmp1);
		return vec3<T> (x.x * tmp2, x.y * tmp2, x.z * tmp2);
	}

	// Lerp TODO
	// quat<T> lerp(T factor, const quat<T>& val) const
	//{
	//	return quat<T>((*this).getImag().lerp(factor,val), (1 - factor) * w + factor * val.w);
	//}

	constexpr static quat<T> identity{};
};


using quatf = quat<float>;
using quatd = quat<double>;

} // namespace cml
