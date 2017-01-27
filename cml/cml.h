#pragma once

#ifndef CML_HEADER_FILE
#define CML_HEADER_FILE

#include <math.h>  

#ifdef CML_NAMESPACE
namespace cml {
#endif

#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif

#define DEG2RAD(x) ((x * M_PI) / 180.0)
	//#define EPSILON (4.37114e-07)

const double epsilon = 4.37114e-05;
#define EPSILON epsilon

#pragma once

	//Vector operations add, sub, scalar multiply, scalar division,
	//Vector functions cross, distance, dot, faceforward, length, normalize, reflect
	template<class T>
	class vec2 {
	public:
		union {
			T x; //world coordinate space
			T s; //texture coordinate space
		}
		union {
			T y; //world coordinate space
			T t; //texture coordinate space
		}

		/* CONSTRUCTORS */

		//Default constructor of (0,0)
		vec2() : x(0) , y (0){}

		//Constructor with arguments (x,y)
		vec2(T a, T b) :x(a), y(b) {}

		//Copy constructor
		vec2(const vec2<T> &src): x(src.x), y(src.y){}

		//Casting copy constructor
		template<class FromT>
		vec2(const vec2<FromT>& src): x(static_cast<T>(src.x)), y(static_cast<T>(src.y)) {}

		/* ACCESS OPERATORS */

		//copy casting operator
		template<class FromT>
		vec2<T>& operator=(const vec2<FromT>& rhs) {
			x = static_cast<T>(rhs.x);
			y = static_cast<T>(rhs.y);
			return *this;
		}

		//copy operator
		vec2<T>& operator=(const vec2<T>& rhs) {
			x = rhs.x;
			y = rhs.y;
			return *this;
		}

		//array access operator
		T& operator[](int n) {
			assert(n >= 0 && n <= 1);
			if (0 == n)
				return x;
			else
				return y;
		}

		//Constant array access operator
		const T& operator[](int n) const {
			assert(n >= 0 && n <= 1);
			if (0 == n)
				return x;
			else
				return y;
		}

		/* VECTOR MATH OPERATIONS */

		//addition
		vec2<T> operator+(const vec2<T>& rhs) const {
			return vec2<T>(x + rhs.x, y + rhs.y);
		}

		//subtraction
		vec2<T> operator-(const vec2<T>& rhs) const {
			return vec2<T>(x - rhs.x, y - rhs.y);
		}

		//multiplication
		vec2<T> operator*(const vec2<T>& rhs) const {
			return vec2<T>(x * rhs.x, y * rhs.y);
		}

		//division
		vec2<T> operator/(const vec2<T>& rhs) const {
			return vec2<T>(x / rhs.x, y / rhs.y);
		}

		//more addition 
		vec2<T> &operator +=(const vec2<T> &rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		//more subtraction
		vec2<T> &operator -=(const vec2<T> &rhs) {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		//more multiplication
		vec2<T> &operator *=(const vec2<T> &rhs) {
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		//more division
		vec2<T> &operator /=(const vec2<T> &rhs) {
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		/* SCALAR MATH OPERATIONS */

		//Addition 
		vec2<T> operator+(const T rhs) const {
			return vec2<T>(x + rhs, y + rhs);
		}

		//Subtraction
		vec2<T> operator-(const T rhs) const {
			return vec2<T>(x - rhs, y - rhs);
		}

		//Multiplication
		vec2<T> operator*(const T rhs) const{
			return vec2<T>(x * rhs, y * rhs);
		}

		//Division
		vec2<T> operator/(const T rhs) const {
			assert(rhs != 0);
			return vec2<T>(x / rhs, y / rhs);
		}

		//More addition
		vec2<T>& operator+=(T rhs) {
			x += rhs;
			y += rhs;
			return *this;
		}

		//More subtraction
		vec2<T>& operator-=(T rhs) {
			x -= rhs;
			y -= rhs;
			return *this;
		}

		//More multiplication
		vec2<T>& operator*=(T rhs) {
			x *= rhs;
			y *= rhs;
			return *this;
		}

		//More division
		vec2<T>& operator/=(T rhs) {
			assert(rhs != 0);
			x /= rhs;
			y /= rhs;
			return *this;
		}

		/* EQUALITY OPERATORS */

		//Equal to
		bool operator==(const vec2<T>& rhs) const {
			return std::abs(x - rhs.x) < EPSILON) && (std::abs(y - rhs.y) < EPSILON);
		}

		//Not equal to
		bool operator!=(const vec2<T>& rhs) const {
			return !(*this == rhs);
		}

		//Negation operator
		vec2<T> operator-() const {
			return vec2<T>(-x, -y);
		}
		
		/* FUNCTIONAL OPERATORS */

		//Length
		T length() const {
			return (T)std:sqrt(x*x + y*y);
		}

		//Length Squared
		T lengthSq() const {
			return x*x + y*y;
		}

		//Normalize 
		void normalize() {
			T s = length();
			x /= s;
			y /= s;
		}

		//Dot product
		T dot(const vec2<T>& rhs) const {
			return x*rhs.x + y*rhs.y;
		}


		/*float dot(const vec2 &a, const vec2 &b) {
			return a.x*b.x + a.y*b.y;
		}

		float distance(const vec2 &a, const vec2 &b) {
			return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
		}

		vec2 reflect(const vec2 &I, const vec2 &N) {
			return I - 2.0f*dot(I, N)* N;
		}*/
	};

	// Typedef shortcuts for 2D vector

	// vec2 of floats
	typedef class vec2<float> Vector2f;
	// vec2 of doubles
	typedef class vec2<double> Vector2d;
	// vec2 of ints
	typedef class vec2<int> Vector2i;

	

	class vec3 {
	public:
		float x;
		float y;
		float z;

		vec3(float a, float b, float c) :x(a), y(b), z(c) {

		}

		const vec3 &operator +=(const vec3 &val) {
			x = x + val.x;
			y = y + val.y;
			z = z + val.z;
			return *this;
		}

		const vec3 &operator -=(const vec3 &val) {
			x = x - val.x;
			y = y - val.y;
			z = z - val.z;
			return *this;
		}

		const vec3 &operator+(const vec3 &b) {
			return vec3(*this) += b;
		}

		const vec3 &operator-(const vec3 &b) {
			return vec3(*this) -= b;
		}

	};

	const float dot(const vec3 &a, const vec3 &b) {
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	const float distance(const vec3 &a, const vec3 &b) {
		return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
	}


	class vec4 {
	public:
		float x;
		float y;
		float z;
		float w;
		vec4(float a, float b, float c, float d) :x(a), y(b), z(c), w(d) {

		}

		vec4(float a, float b, float c) :x(a), y(b), z(c) {

		}

		const vec4 &operator +=(const vec4 &val) {
			x = x + val.x;
			y = y + val.y;
			z = z + val.z;
			w = w + val.w;
			return *this;
		}

		const vec4 &operator -=(const vec4 &val) {
			x = x - val.x;
			y = y - val.y;
			z = z - val.z;
			w = w - val.w;
			return *this;
		}

		const vec4 &operator+(const vec4 &b) {
			return vec4(*this) += b;
		}

		const vec4 &operator-(const vec4 &b) {
			return vec4(*this) -= b;
		}
	};

#ifdef CML_NAMESPACE
}
#endif // CML_NAMESPACE

#endif // CML_HEADER_FILE