#pragma once


#ifndef VECTOR4_HEADER

#include <cmath>
#include <cassert>

namespace cml {

	template<typename T = float>
	class vec4
	{
	public:

		T x;
		T y;
		T z;
		T w;

		//Default Constuctor
		vec4() : x(0), y(0), z(0), w(0) {}

		//Initial value constructor
		vec4(const T xVal, const T yVal, const T zVal, const T wVal) : x(xVal), y(yVal), z(zVal), w(wVal) {}

		//Copy from vec4
		vec4(const vec4<T>& val) : x(val.x), y(val.y), z(val.z), w(val.z) {}

		//Copy from vec4
		vec4(const vec3<T>& val) : x(val.x), y(val.y), z(val.z), w(0) {}

		//Set the values explicitely
		vec4<T> set(const T a, const T b, const T c, const T d) {
			x = a;
			y = b;
			z = c;
			w = d;
			return (*this);
		}

		//ADDITIONS

		vec4<T> operator +(const vec4<T> rhs) const {
			return vec4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		vec4<T>& operator +=(const vec4<T> val) {
			x += val.x;
			y += val.y;
			z += val.z;
			w += val.w;
			return (*this);
		}

		//scalar
		vec4<T> operator + (const T val) const {
			return vec4<T>(x + val, y + val, z + val, w + val);
		}

		//SUBTRACTOINS

		vec4<T> operator -(const vec4<T> val) const {
			return vec4<T>(x - val.x, y - val.y, z - val.z, w - val.w);
		}

		vec4<T>& operator -=(const vec4<T> val) {
			x -= val.x;
			y -= val.y;
			z -= val.z;
			w -= val.w;
			return (*this);
		}

		//scalar
		vec4<T> operator - (const T val) const {
			return vec4<T>(x - val, y - val, z - val, w - val);
		}

		//MULTIPLICATION

		vec4<T> operator *(const T val) const {
			return vec4<T>(x * val, y * val, z * val, w * val);
		}

		vec4<T>& operator *=(const T val) {
			x *= val;
			y *= val;
			z *= val;
			w *= val;
			return (*this);
		}

		//DIVISION

		vec4<T> operator /(const T val) const {
			return vec4<T>(x / val, y / val, z / val, w/val);
		}

		vec4<T>& operator /=(const T val) {
			x /= val;
			y /= val;
			z /= val;
			w /= val;
			return (*this);
		}

		//NEGATION

		vec4<T> operator-() const {
			return vec4<T>(-x, -y, -z, -w);
		}


		//ARRAY ACCESS

		//array access
		T & operator[](int n)
		{
			assert(n >= 0 && n <= 3);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else if (2 == n)
				return z;
			else
				return w;
		}

		//constant array access
		const T & operator[](int n) const
		{
			assert(n >= 0 && n <= 3);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else if (2 == n)
				return z;
			else
				return w;
		}



		//EQUALITY
		bool operator ==(const vec4& val) const {
			return (cmpf(x, val.x) && cmpf(y, val.y) && cmpf(z, val.z) && cmpf(w, val.w));
		}

		bool operator !=(const vec4& val) const {
			return !(*this == val);
		}


		//DOT
		T dot(const vec4<T>& a, const vec4<T>& b) const {
			return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
		}

		//MAGNITUDE
		T mag(void) const {
			return (T) std::sqrt(x*x + y*y + z*z + w*w);
		}

		T magSqrd(void) const {
			return (x*x + y*y + z*z + w * w);
		}

		//NORMALIZE

		void norm() {
			if (mag() != 0) {
				x /= mag();
				y /= mag();
				z /= mag();
				w /= mag();
			}
		}

		//LERP
		vec4<T> lerp(const T fact, const vec4<T>& val) const
		{
			return (*this) + (val - (*this)) * fact;
		}

		//PROJECTION
		vec4<T> proj(const vec4<T>& p, const vec4<T>& q) const {
			return vec4<T>(q*(dot(p, q) / q.magSqrd()));
		}

		//PERPINDICULAR
		vec4<T> perp(const vec4<T>& p, const vec4<T>& q) const {
			return vec4<T>(p - proj(p, q));
		}

		//put to output
		friend std::ostream& operator<<(std::ostream &strm, const vec4<T> &v) {
			return strm << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
		}
	};


	typedef vec4<float> vec4f;
	typedef vec4<int> vec4i;
	typedef vec4<double> vec4d;


}

#endif // !VECTOR4_HEADER
