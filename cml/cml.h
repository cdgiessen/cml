#pragma once

#ifndef CML_HEADER_FILE
#define CML_HEADER_FILE

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>


namespace cml {


#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif

#define DEG2RAD(x) ((x * M_PI) / 180.0)
	//#define EPSILON (4.37114e-07)

const double epsilon = 4.37114e-07;
#define EPSILON epsilon



	//Vector operations add, sub, scalar multiply, scalar division,
	//Vector functions cross, distance, dot, faceforward, length, normalize, reflect
	template<class T>
	class vec2 {
	public:
		union {
			T x; //world coordinate space
			T s; //texture coordinate space
		};
		union {
			T y; //world coordinate space
			T t; //texture coordinate space
		};

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

		//Dot product
		T dot(const vec2<T>& rhs) const {
			return x*rhs.x + y*rhs.y;
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
			return (std::abs(x - rhs.x) < EPSILON) && (std::abs(y - rhs.y) < EPSILON);
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

		//Linear interpolation
		vec2<T> lerp(T fact, const vec2<T>& r) const {
			return (*this) + (r - (*this)) * fact;
		}

		//output to stream operator
		friend std::ostream& operator<<(std::ostream& lhs, const vec2<T>& rhs)
		{
			lhs << "[" << rhs.x << "," << rhs.y << "]";
			return lhs;
		}

		//toString to print
		std::string toString() const
		{
			std::ostringstream oss;
			oss << *this;
			return oss.str();
		}
	};

	// Typedef shortcuts for 2D vector

	// vec2 of floats
	typedef class vec2<float> vec2f;
	// vec2 of doubles
	typedef class vec2<double> vec2d;
	// vec2 of ints
	typedef class vec2<int> vec2i;

	
	template<class T>
	class vec3 {
	public:
		union {
			T x; //World coordinate
			T s; //Texture coordinate
			T r; //Color
		};
		union {
			T y; //World coordinate
			T t; //Texture coordinate
			T g; //Color
		};
		union {
			T z; //World coordinate
			T u; //Texture coordinate
			T b; //Color
		};

		/* CONSTRUCTORS */

		//Default constructor of (0,0)
		vec3() : x(0), y(0), z(0) {}

		//Constructor with arguments (x,y)
		vec3(T a, T b, T c) :x(a), y(b), z(c) {}

		//Copy constructor
		vec3(const vec3<T> &src) : x(src.x), y(src.y), z(src.z) {}

		//Casting copy constructor
		template<class FromT>
		vec3(const vec3<FromT>& src) : x(static_cast<T>(src.x)), y(static_cast<T>(src.y)), z(static_cast<T>(src.z)) {}

		/* ACCESS OPERATORS */

		//copy casting operator
		template<class FromT>
		vec3<T>& operator=(const vec3<FromT>& rhs) {
			x = static_cast<T>(rhs.x);
			y = static_cast<T>(rhs.y);
			z = static_cast<T>(rhs.z);
			return *this;
		}

		//copy operator
		vec3<T>& operator=(const vec3<T>& rhs) {
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
			return *this;
		}

		//array access operator
		T & operator[](int n) {
			assert(n >= 0 && n <= 2);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else
				return z;
		}

		//Constant array access operator
		const T& operator[](int n) const {
			assert(n >= 0 && n <= 2);
			if (0 == n)
				return x;
			else if (1 == n)
				return y;
			else
				return z;
		}

		/* VECTOR MATH OPERATIONS */

		//addition
		vec3<T> operator+(const vec3<T>& rhs) const {
			return vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		//subtraction
		vec3<T> operator-(const vec3<T>& rhs) const {
			return vec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		//multiplication
		vec3<T> operator*(const vec3<T>& rhs) const {
			return vec3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
		}

		//division
		vec3<T> operator/(const vec3<T>& rhs) const {
			return vec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
		}

		//more addition 
		vec3<T> &operator +=(const vec3<T> &rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		//more subtraction
		vec3<T> &operator -=(const vec3<T> &rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		//more multiplication
		vec3<T> &operator *=(const vec3<T> &rhs) {
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		//more division
		vec3<T> &operator /=(const vec3<T> &rhs) {
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		//Dot product
		T dot(const vec3<T>& rhs) const {
			return x * rhs.x + y * rhs.y + z * rhs.z;
		}

		//Cross product
		vec3<T> crossProduct(const vec3<T>& rhs) const {
			return vec3<T>(y * rhs.z - rhs.y * z, z * rhs.x - rhs.z * x, x * rhs.y - rhs.x * y);
		}

		/* SCALAR MATH OPERATIONS */

		//Addition 
		vec3<T> operator+(const T rhs) const {
			return vec3<T>(x + rhs, y + rhs, z + rhs);
		}

		//Subtraction
		vec3<T> operator-(const T rhs) const {
			return vec3<T>(x - rhs, y - rhs, z - rhs);
		}

		//Multiplication
		vec3<T> operator*(const T rhs) const {
			return vec3<T>(x * rhs, y * rhs, z * rhs);
		}

		//Division
		vec3<T> operator/(const T rhs) const {
			assert(rhs != 0);
			return vec3<T>(x / rhs, y / rhs, z / rhs);
		}

		//More addition
		vec3<T>& operator+=(T rhs) {
			x += rhs;
			y += rhs;
			z += rhs;
			return *this;
		}

		//More subtraction
		vec3<T>& operator-=(T rhs) {
			x -= rhs;
			y -= rhs;
			z -= rhs;
			return *this;
		}

		//More multiplication
		vec3<T>& operator*=(T rhs) {
			x *= rhs;
			y *= rhs;
			z *= rhs;
			return *this;
		}

		//More division
		vec3<T>& operator/=(T rhs) {
			assert(rhs != 0);
			x /= rhs;
			y /= rhs;
			z /= rhs;
			return *this;
		}

		/* EQUALITY OPERATORS */

		//Equal to
		bool operator==(const vec3<T>& rhs) const {
			return std::abs(x - rhs.x) < EPSILON && std::abs(y - rhs.y) < EPSILON && std::abs(z - rhs.z) < EPSILON;
		}

		//Not equal to
		bool operator!=(const vec3<T>& rhs) const {
			return !(*this == rhs);
		}

		//Negation operator
		vec3<T> operator-() const {
			return vec3<T>(-x, -y, -z);
		}

		/* FUNCTIONAL OPERATORS */

		//Length
		T length() const {
			return (T)std:sqrt(x*x + y*y + z*z);
		}

		//Length Squared
		T lengthSq() const {
			return x*x + y*y + z*z;
		}

		//Normalize 
		void normalize() {
			T s = length();
			assert(s != 0);
			x /= s;
			y /= s;
			z /= s;
		}

		//Linear interpolation
		vec3<T> lerp(T fact, const vec3<T>& r) const {
			return (*this) + (r - (*this)) * fact;
		}

		//output to stream operator
		friend std::ostream& operator<<(std::ostream& lhs, const vec3<T>& rhs)
		{
			lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z <<"]";
			return lhs;
		}

		//toString to print
		std::string toString() const
		{
			std::ostringstream oss;
			oss << *this;
			return oss.str();
		}
	};

	// vec3 of floats
	typedef class vec3<float> vec3f;
	// vec3 of doubles
	typedef class vec3<double> vec3d;
	// vec3 of ints
	typedef class vec3<int> vec3i;


	template<class T>
	class vec4 {
	public:
		union {
			T r; //Color 
			T s; //world coordinate
		};
		union {
			T g; //Color 
			T y; //world coordinate
		};
		union {
			T b; //Color 
			T z; //world coordinate
		};
		union {
			T a; //Color 
			T w; //world coordinate
		};

		/* CONSTRUCTORS */

		//Default constructor of (0,0)
		vec4() : x(0), y(0), z(0), w(0) {}

		//Constructor with arguments (x,y)
		vec4(T a, T b, T c, T d) :x(a), y(b), z(c), w(d) {}

		//Copy constructor
		vec4(const vec4<T> &src) : x(src.x), y(src.y), z(src.z), w(src.w) {}

		//Casting copy constructor
		template<class FromT>
		vec4(const vec4<FromT>& src) : x(static_cast<T>(src.x)), y(static_cast<T>(src.y)), z(static_cast<T>(src.z)), w(static_cast<T>(src.w)) {}

		/* ACCESS OPERATORS */

		//copy casting operator
		template<class FromT>
		vec4<T>& operator=(const vec4<FromT>& rhs) {
			x = static_cast<T>(rhs.x);
			y = static_cast<T>(rhs.y);
			z = static_cast<T>(rhs.z);
			w = static_cast<T>(rhs.w);
			return *this;
		}

		//copy operator
		vec4<T>& operator=(const vec4<T>& rhs) {
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
			w = rhs.w;
			return *this;
		}

		//array access operator
		T & operator[](int n) {
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

		//Constant array access operator
		const T& operator[](int n) const {
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

		/* VECTOR MATH OPERATIONS */

		//addition
		vec4<T> operator+(const vec4<T>& rhs) const {
			return vec4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}

		//subtraction
		vec4<T> operator-(const vec4<T>& rhs) const {
			return vec4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}

		//multiplication
		vec4<T> operator*(const vec4<T>& rhs) const {
			return vec4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}

		//division
		vec4<T> operator/(const vec4<T>& rhs) const {
			return vec4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}

		//more addition 
		vec4<T> &operator +=(const vec4<T> &rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}

		//more subtraction
		vec4<T> &operator -=(const vec4<T> &rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}

		//more multiplication
		vec4<T> &operator *=(const vec4<T> &rhs) {
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

		//more division
		vec4<T> &operator /=(const vec4<T> &rhs) {
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}

		//Dot product
		T dot(const vec4<T>& rhs) const {
			return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
		}

		/* SCALAR MATH OPERATIONS */

		//Addition 
		vec4<T> operator+(const T rhs) const {
			return vec4<T>(x + rhs, y + rhs, z + rhs);
		}

		//Subtraction
		vec4<T> operator-(const T rhs) const {
			return vec4<T>(x - rhs, y - rhs, z - rhs);
		}

		//Multiplication
		vec4<T> operator*(const T rhs) const {
			return vec4<T>(x * rhs, y * rhs, z * rhs);
		}

		//Division
		vec4<T> operator/(const T rhs) const {
			assert(rhs != 0);
			return vec4<T>(x / rhs, y / rhs, z / rhs);
		}

		//More addition
		vec4<T>& operator+=(T rhs) {
			x += rhs;
			y += rhs;
			z += rhs;
			return *this;
		}

		//More subtraction
		vec4<T>& operator-=(T rhs) {
			x -= rhs;
			y -= rhs;
			z -= rhs;
			return *this;
		}

		//More multiplication
		vec4<T>& operator*=(T rhs) {
			x *= rhs;
			y *= rhs;
			z *= rhs;
			return *this;
		}

		//More division
		vec4<T>& operator/=(T rhs) {
			assert(rhs != 0);
			x /= rhs;
			y /= rhs;
			z /= rhs;
			return *this;
		}

		/* EQUALITY OPERATORS */

		//Equal to
		bool operator==(const vec4<T>& rhs) const {
			return std::abs(x - rhs.x) < EPSILON && std::abs(y - rhs.y) < EPSILON && std::abs(z - rhs.z) < EPSILON;
		}

		//Not equal to
		bool operator!=(const vec4<T>& rhs) const {
			return !(*this == rhs);
		}

		//Negation operator
		vec4<T> operator-() const {
			return vec4<T>(-x, -y, -z);
		}

		/* FUNCTIONAL OPERATORS */

		//Length
		T length() const {
			return (T)std:sqrt(x*x + y*y + z*z);
		}

		//Length Squared
		T lengthSq() const {
			return x*x + y*y + z*z;
		}

		//Normalize 
		void normalize() {
			T s = length();
			assert(s != 0);
			x /= s;
			y /= s;
			z /= s;
		}

		//Linear interpolation
		vec4<T> lerp(T fact, const vec4<T>& r) const {
			return (*this) + (r - (*this)) * fact;
		}

		//output to stream operator
		friend std::ostream& operator<<(std::ostream& lhs, const vec4<T>& rhs)
		{
			lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
			return lhs;
		}

		//toString to print
		std::string toString() const
		{
			std::ostringstream oss;
			oss << *this;
			return oss.str();
		}
	};


}


#endif // CML_HEADER_FILE