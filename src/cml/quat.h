#pragma once

#include "vec3.h"

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

namespace cml
{

template <typename T = float> class alignas (16) quat
{
	private:
	vec3<T> imag;
	T real = 1.f; // Real Part

	public:
	constexpr quat () : imag{}, real (1.f) {}

	constexpr quat (T x, T y, T z, T real) : imag (x, y, z), real (real) {}

	constexpr quat (const vec3<T>& imag, const T real) : imag (imag), real (real) {}

	// returns pointer to the data
	static T const* ptr (quat<T> const& vec) { return &(vec.x); }

	T const* ptr () const { return &imag.x; }

	// Returns a vector of the imaginary part of a quaternion
	vec3<T> getImag () const { return imag; }

	T getReal () const { return real; }

	// OPERATORS

	// Quaternion Addition
	quat<T> operator+ (const quat<T> val) const
	{
		return quat<T> (imag + val.imag, real + val.real);
	}

	// Addition
	void operator+= (const quat<T> val)
	{
		imag += val.imag;
		real += val.real;
	}

	// Quaternion Subtraction
	quat<T> operator- (const quat<T> val) const
	{
		return quat<T> (imag - val.imag, real - val.real);
	}

	// Subtraction
	void operator-= (const quat<T> val)
	{
		imag -= val.imag;
		real -= val.real;
	}

	// Scalar Multiplication
	quat<T> operator* (const T val) const { return quat<T> (imag * val.imag, real * val.real); }

	// Quaternion multiplication
	quat<T> operator* (const quat<T> val) const
	{

		return quat<T> (
		    real * val.imag.x - imag.x * val.real + imag.y * val.imag.z - imag.z * val.imag.y,
		    real * val.imag.y - imag.x * val.imag.z + imag.y * val.real + imag.z * val.imag.x,
		    real * val.imag.z + imag.x * val.imag.y - imag.y * val.imag.x + imag.z * val.real,
		    real * val.real - imag.x * val.imag.x - imag.y * val.imag.y - imag.z * val.imag.z);
	}

	// EQUALITY
	bool operator== (const quat<T>& val) const { return imag == val.imag && real == val.real; }

	bool operator!= (const quat<T>& val) const { return !(*this == val); }

	// Negation
	quat<T> operator- () const { return quat<T> (-imag, -real); }

	// Conjugate, only inverts the imaginary portion
	quat<T> operator~ () const { return quat<T> (-imag, real); }

	// MAGNITUDE
	T mag () const { return (T)std::sqrt (imag.mag_sqrt () + real * real); }

	T magSqrd (void) const { return (imag.mag_sqrt () + real * real); }

	// Normalize
	void norm ()
	{
		T mag = (*this).mag ();
		imag /= mag;
		real /= mag;
	}

	// normalizes a given quaternion
	quat<T>& norm (quat<T>& val) const
	{
		T mag = val.mag ();
		val.imag /= mag;
		val.real /= mag;
		return (val);
	}

	// Gets an inverse quaternion of this one
	quat<T> inverse ()
	{
		T mag = (*this).magSqrd ();
		return quat<T> (-imag / mag, real / mag);
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
		double angleRad = radians (degrees);
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

	static const quat<T> identity;
};

template <typename T> const quat<T> quat<T>::identity = { 0, 0, 0, 1 };

using quatf = quat<float>;
using quatd = quat<double>;

} // namespace cml
