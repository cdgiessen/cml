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
#inverse - Returns the Inverse of rotation.
rotate towards - 	Rotates a rotation from towards to.


Operators
# + += - -= * 
# == != *(combine lhs with rhs)
*/

namespace cml {

	template<typename T>
	class quat {
	public:
		T x; // Imaginary x
		T y; // Imaginary y
		T z; // Imaginary z
		T w; // Real Part

		//CONSTRUCTORS

		//Default constructor
		quat() : x(0), y(0), z(0), w(0) {}

		//Constructor from arguments
		quat(T a, T b, T c, T d) : x(a), y(b), z(c), w(d) {}

		//Copy constructor
		quat(const quat<T>& copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w) {}

		//Constructor from vector and real part
		quat(const vec3<T> imagVec, const T realVal) : x(imagVec.x), y(imagVec.y), z(imagVec.z), w(realVal) {}

		//Returns a vector of the imaginary part of a quaternion
		vec3<T> getImag() {
			return vec3<T>(x, y, z);
		}

		//REturns the real part of a quaternion
		T getReal() {
			return w;
		}

		//OPERATORS

		//Quaternion Addition
		quat<T> operator+ (const quat<T> val) const {
			return quat<T>(x + val.x, y + val.y, z + val.z, w + val.w);
		}

		//Addition
		quat<T>& operator+= (const quat<T> val) {
			x += val.x;
			y += val.y;
			z += val.z;
			w += val.w;
			return *this;
		}

		//Quaternion Subtraction
		quat<T> operator- (const quat<T> val) const {
			return quat<T>(x - val.x, y - val.y, z - val.z, w - val.w);
		}

		//Subtraction
		quat<T>& operator-= (const quat<T> val) {
			x -= val.x;
			y -= val.y;
			z -= val.z;
			w -= val.w;
			return *this;
		}

		//Scalar Multiplication
		quat<T> operator *(const T val) const {
			return quat<T>(val * x, val * y, val * z, val * w);
		}

		//Quaternion multiplication
		quat<T> operator * (const quat<T> val) const {
			return quat<T>(w * val.x - x * val.w + y * val.z - z * val.y, 
						   w * val.y - x * val.z + y * val.w + z * val.x, 
						   w * val.z + x * val.y - y * val.x + z * val.w , 
						   w * val.w - x * val.x - y * val.y - z * val.z);
		}

		//EQUALITY
		bool operator ==(const quat<T>& val) const {
			return (cmpf(x, val.x) && cmpf(y, val.y) && cmpf(z, val.z) && cmpf(w, val.w));
		}

		bool operator !=(const quat<T>& val) const {
			return !(*this == val);
		}

		//Negation
		quat<T> operator-() const{
			return quat<T>(-x, -y, -z, -w);
		}

		//Conjugate, only inverts the imaginary portion
		quat<T> operator~() const {
			return quat<T>(-x, -y, -z, w);
		}

		//MAGNITUDE
		T mag() const {
			return (T)std::sqrt(x*x + y*y + z*z + w*w);
		}

		T magSqrd(void) const {
			return (x*x + y*y + z*z + w*w);
		}

		//Normalize
		void norm() {
			T mag = (*this).mag();
			x /= mag;
			y /= mag;
			z /= mag;
			w /= mag;
		}

		//normalizes a given quaternion
		quat<T>& norm(quat<T>& val) const {
			T mag = val.mag();
			val.x /= mag;
			val.y /= mag;
			val.z /= mag;
			val.w /= mag;
			return (val);
		}

		//Gets an inverse quaternion of this one 
		quat<T> inverse() {
			T mag = (*this).magSqrd();
			return quat<T>(-x / mag, -y / mag, -z / mag, w / mag);
		}

		//Lerp TODO
		//quat<T> lerp(T factor, const quat<T>& val) const
		//{
		//	return quat<T>((*this).getImag().lerp(factor,val), (1 - factor) * w + factor * val.w);
		//}

		//put to output
		friend std::ostream& operator<<(std::ostream &strm, const quat<T> &q) {
			return strm << "[(" << q.x << ", " << q.y << ", " << q.z << "), " << q.w << "]";
		}

		//To string
		std::string toString() const {
			std::ostringstream stream;
			stream << *this;
			return stream.str();
		}
	};

	typedef quat<float> quatf;
	typedef quat<double> quatd;

	static const quat<float> IDENTITY(0, 0, 0, 1);

	static const quat<float> QUAT_ABOUT_X_90(std::sqrt(0.5), 0, 0, std::sqrt(0.5));
	static const quat<float> QUAT_ABOUT_X_180(1, 0, 0, 0);
	static const quat<float> QUAT_ABOUT_X_270(-std::sqrt(0.5), 0, 0, std::sqrt(0.5));

	static const quat<float> QUAT_ABOUT_Y_90(0, std::sqrt(0.5), 0, std::sqrt(0.5));
	static const quat<float> QUAT_ABOUT_Y_180(0, 1, 0, 0);
	static const quat<float> QUAT_ABOUT_Y_270(0, -std::sqrt(0.5), 0, std::sqrt(0.5));

	static const quat<float> QUAT_ABOUT_Z_90(0, 0, std::sqrt(0.5), std::sqrt(0.5));
	static const quat<float> QUAT_ABOUT_Z_180(0, 0, 1, 0);
	static const quat<float> QUAT_ABOUT_Z_270(0, 0, -std::sqrt(0.5), std::sqrt(0.5));

}

#endif // !QUATERNION_HEADER
