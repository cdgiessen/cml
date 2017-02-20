#pragma once

#ifndef VECTOR3_HEADER

#include <cmath>
#include <cassert>

/*
Constructors
empty, value given, copy, 

operations
 DONE :+  += - -= *  *=  /  /=   negation, [] == != 
 >= <= > <
 
 #dot product
 #cross product

 #get/set
 
 #lerp

 #mag
 #magSqrd
 
 #normalize

 #constants right, left, forward, back, up, down, one, zero

 #projection

 #perpindicular

 toString

 angle - Returns the angle in degrees between from and to.

 distance - from a to b

 max - vec made up of largest element

 min - vec made up of smallest element.

 scale - multiplies two vectors component wise (* and *= )

 reflect (inDirection, inNormal) - reflects a vector off a plane define by a normal

 */
namespace cml {

	template<typename T = float>
	class vec3
	{
	public:

		T x;
		T y;
		T z;

		//Default Constuctor
		vec3() : x(0), y(0), z(0) {}

		//Initial value constructor
		vec3(const T xVal, const T yVal, const T zVal) : x(xVal), y(yVal), z(zVal) {}

		//Copy from vec3
		vec3(const vec3<T>& val) : x(val.x), y(val.y), z(val.z) {}

		//Copy from vec2
		vec3(const vec2<T>& val) : x(val.x), y(val.y), z(0) {}

		//Set the values explicitely
		vec3<T> set(const T a, const T b, const T c) {
			x = a;
			y = b;
			z = c;
			return (*this);
		}

		//ADDITIONS
		
		vec3<T> operator +(const vec3<T> rhs) const {
			return vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		vec3<T>& operator +=(const vec3<T> val) {
			x += val.x;
			y += val.y;
			z += val.z;
			return (*this);
		}

		//scalar
		vec3<T> operator +(const T val) const {
			return vec3<T>(x + val, y + val, z + val);
		}

		//SUBTRACTOINS

		vec3<T> operator -(const vec3<T> val) const {
			return vec3<T>(x - val.x, y - val.y, z - val.z);
		}

		vec3<T>& operator -=(const vec3<T> val) {
			x -= val.x;
			y -= val.y;
			z -= val.z;
			return (*this);
		}

		//scalar
		vec3<T> operator - (const T val) const {
			return vec3<T>(x - val, y - val, z - val);
		}

		//MULTIPLICATION

		vec3<T> operator *(const T val) const {
			return vec3<T>(x * val, y * val, z * val);
		}

		vec3<T>& operator *=(const T val){
			x *= val;
			y *= val;
			z *= val;
			return (*this);
		}

		//DIVISION
		
		vec3<T> operator /(const T val) const {
			return vec3<T>(x / val, y / val, z / val);
		}

		vec3<T>& operator /=(const T val) {
			x /= val;
			y /= val;
			z /= val;
			return (*this);
		}

		//NEGATION

		vec3<T> operator-() const {
			return vec3<T>(-x, -y, -z);
		}


		//ARRAY ACCESS

		//array access
		T & operator[](int n)
		{
			assert(n >= 0 && n <= 2);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else
				return z;
		}

		//constant array access
		const T & operator[](int n) const
		{
			assert(n >= 0 && n <= 2);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else
				return z;
		}



		//EQUALITY
		bool operator ==(const vec3& val) const{
			return (cmpf(x, val.x) && cmpf(y, val.y) && cmpf(z, val.z));
		}

		bool operator !=(const vec3& val) const{
			return !(*this == val);
		}


		//DOT
		static T dot(const vec3<T>& a, const vec3<T>& b){
			return a.x * b.x + a.y * b.y + a.z * b.z;
		}

		//CROSS
		static vec3<T> cross(const vec3<T>& a, const vec3<T>& b) {
			return vec3<T>(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
		}

		//MAGNITUDE
		T mag(void) const {
			return (T)std::sqrt(x*x + y*y + z*z);
		}

		T magSqrd(void) const{
			return (x*x + y*y + z*z);
		}

		//NORMALIZE

		//normalizes this vector
		void norm() {
			x /= mag();
			y /= mag();
			z /= mag();
		}

		//normalizes a given vector
		vec3<T>& norm(vec3<T>& val) const {
			val.x /= mag(); 
			val.y /= mag(); 
			val.z /= mag();
			return (val);
		}

		//LERP
		vec3<T> lerp(const T fact, const vec3<T>& val) const
		{
			return (*this) + (val - (*this)) * fact;
		}

		//PROJECTION
		vec3<T> proj(const vec3<T>& p, const vec3<T>& q) const {
			return vec3<T>(q * (dot(p, q) / q.magSqrd()));
		}

		//PERPINDICULAR
		vec3<T> perp(const vec3<T>& p, const vec3<T>& q) const {
			return vec3<T>(p - proj(p, q));
		}

		//ANGLE between p and q
		//T angle(const vec3<T>& p, const vec3<T>& q) const {
		//	return acos(dot(norm(p), norm(q)));
		//}
	

		//put to output
		friend std::ostream& operator<<(std::ostream &strm, const vec3<T> &v) {
			return strm << "[" << v.x << ", " << v.y << ", " << v.z << "]";
		}

	};
	static const vec3<float> ZERO(0, 0, 0);
	static const vec3<float> ONE(1, 1, 1);
	static const vec3<float> RIGHT(1, 0, 0);
	static const vec3<float> LEFT(-1, 0, 0);
	static const vec3<float> UP(0, 1, 0);
	static const vec3<float> DOWN(0, -1, 0);
	static const vec3<float> FORWARD(0, 0, 1);
	static const vec3<float> BACK(0, 0, -1);

	typedef vec3<float> vec3f;
	typedef vec3<int> vec3i;
	typedef vec3<double> vec3d;
}

#endif // !VECTOR3_HEADER
