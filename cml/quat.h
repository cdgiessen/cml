#pragma once

#ifndef QUATERNION_HEADER

/*
return euler angle representation (vec3)

look rotation - Creates a rotation with the specified forward and upwards directions.
euler - Returns a rotation that rotates z degrees around the z axis, x degrees around the x axis, and y degrees around the y axis (in that order).
slerp - Spherically interpolates between a and b by t. The parameter t is clamped to the range [0, 1].
fromToRotation - Creates a rotation which rotates from fromDirection to toDirection.
identity - static var

set (x,y,z,w)
set From To Rotation - creates a rotation from FromRotation to ToRotation
ToAngleAxis 	Converts a rotation to angle-axis representation (angles in degrees).
angle - Returns the angle in degrees between two rotations a and b.

axisangles - Creates a rotation which rotates angle degrees around axis.
dot - The dot product between two rotations.
inverse - Returns the Inverse of rotation.
rotate towards - 	Rotates a rotation from towards to.


Operators
== != *(combine lhs with rhs)
*/

namespace cml {

	template<typename T>
	class quat {
	public:
		T x;
		T y;
		T z;
		T w;

		quat(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

	private:



	};

	typedef quat<float> quatf;
	typedef quat<double> quatd;

	static const quat<float> IDENTITY(0, 0, 0, 1);

}

#endif // !QUATERNION_HEADER
