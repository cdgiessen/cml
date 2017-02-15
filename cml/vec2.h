#pragma once

#ifndef VECTOR2_HEADER

#include <cmath>
#include <cassert>

namespace cml {

	template<typename T = float>
	class vec2
	{
	public:

		T x;
		T y;

		//Default Constuctor
		vec2() : x(0), y(0) {}

		//Initial value constructor
		vec2(T xVal, T yVal) : x(xVal), y(yVal) {}

		//Copy from vector
		vec2(const vec2<T>& val) : x(val.x), y(val.y) {}

		//Set the values explicitely
		vec2<T> set(const T a, const T b) {
			x = a;
			y = b;
			return (*this);
		}

		//ADDITIONS

		vec2<T> operator +(const vec2<T> val) const {
			return vec2<T>(x + val.x, y + val.y);
		}

		vec2<T>& operator +=(const vec2<T> val) {
			x += val.x;
			y += val.y;
			return (*this);
		}

		//scalar
		vec2<T> operator + (const T val) const {
			return vec2<T>(x + val, y + val);
		}

		//SUBTRACTOINS

		vec2<T> operator -(const vec2<T> val) const {
			return vec2<T>(x - val.x, y - val.y);
		}

		vec2<T>& operator -=(const vec2<T> val) {
			x -= val.x;
			y -= val.y;
			return (*this);
		}

		//scalar
		vec2<T> operator - (const T val) const {
			return vec2<T>(x - val, y - val);
		}

		//MULTIPLICATION

		vec2<T> operator *(const T val) const {
			return vec2<T>(x * val, y * val);
		}

		vec2<T>& operator *=(const T val) {
			x *= val;
			y *= val;
			return (*this);
		}

		//DIVISION

		vec2<T> operator /(const T val) const {
			return vec2<T>(x / val, y / val);
		}

		vec2<T>& operator /=(const T val) {
			x /= val;
			y /= val;
			return (*this);
		}

		//NEGATION

		vec2<T> operator-() const {
			return vec2<T>(-x, -y);
		}


		//ARRAY ACCESS

		//array access
		T & operator[](int n) {
			assert(n >= 0 && n <= 1);
			if (0 == n)
				return x;
			else
				return y;
		}

		//constant array access
		const T & operator[](int n) const {
			assert(n >= 0 && n <= 1);
			if (0 == n)
				return x;
			else
				return y;
		}



		//EQUALITY
		bool operator ==(const vec2& val) const {
			return ((x == val.x) && (y == val.y));
		}

		bool operator !=(const vec2& val) const {
			return !(*this == val);
		}


		//DOT
		T dot(const vec2<T>& a, const vec2<T>& b) const {
			return a.x * b.x + a.y * b.y;
		}


		//MAGNITUDE
		T mag(void) const {
			return (T)std::sqrt(x*x + y*y);
		}

		T magSqrd(void) const {
			return (x*x + y*y);
		}


		//NORMALIZE

		void norm() {
			x /= mag();
			y /= mag();
		}

		void norm(vec2<T>& val) const {
			val.x /= val.mag();
			val.y /= val.mag();
		}

		//LERP
		vec2<T> lerp(const T fact, const vec2<T>& val) const
		{
			return (*this) + (val - (*this)) * fact;
		}

		//PROJECTION
		vec2<T> proj(const vec2<T>& p, const vec2<T>& q) {
			return vec2<T>(q* (dot(p, q) / q.magSqrd()));
		}

		//PERPINDICULAR
		vec2<T> perp(const vec2<T>& p, const vec2<T>& q) {
			return vec2<T>(p - proj(p, q));
		}

	};

	static const vec2<float> ZERO_2(0, 0);
	static const vec2<float> ONE_2(1, 1);
	static const vec2<float> RIGHT_2(1, 0);
	static const vec2<float> LEFT_2(-1, 0);
	static const vec2<float> UP_2(0, 1);
	static const vec2<float> DOWN_2(0, -1);

	

	typedef vec2<float> vec2f;
	typedef vec2<int> vec2i;
	typedef vec2<double> vec2d;


}

#endif // !VECTOR2_HEADER