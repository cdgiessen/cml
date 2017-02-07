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

		/* DATA */

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
		
		/* FUNCTIONS */

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

		/* DATA */

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

		/* FUNCTIONS */

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

		/* DATA */

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
			return vec4<T>(x + rhs, y + rhs, z + rhs, w + rhs);
		}

		//Subtraction
		vec4<T> operator-(const T rhs) const {
			return vec4<T>(x - rhs, y - rhs, z - rhs, w - rhs);
		}

		//Multiplication
		vec4<T> operator*(const T rhs) const {
			return vec4<T>(x * rhs, y * rhs, z * rhs, w * rhs);
		}

		//Division
		vec4<T> operator/(const T rhs) const {
			assert(rhs != 0);
			return vec4<T>(x / rhs, y / rhs, z / rhs, w / rhs);
		}

		//More addition
		vec4<T>& operator+=(T rhs) {
			x += rhs;
			y += rhs;
			z += rhs;
			w += rhs;
			return *this;
		}

		//More subtraction
		vec4<T>& operator-=(T rhs) {
			x -= rhs;
			y -= rhs;
			z -= rhs;
			w -= rhs;
			return *this;
		}

		//More multiplication
		vec4<T>& operator*=(T rhs) {
			x *= rhs;
			y *= rhs;
			z *= rhs;
			w *= rhs;
			return *this;
		}

		//More division
		vec4<T>& operator/=(T rhs) {
			assert(rhs != 0);
			x /= rhs;
			y /= rhs;
			z /= rhs;
			w /= rhs;
			return *this;
		}

		/* EQUALITY OPERATORS */

		//Equal to
		bool operator==(const vec4<T>& rhs) const {
			return std::abs(x - rhs.x) < EPSILON && std::abs(y - rhs.y) < EPSILON && std::abs(z - rhs.z) < EPSILON && std::abs(w - rhs.w) < EPSILON;
		}

		//Not equal to
		bool operator!=(const vec4<T>& rhs) const {
			return !(*this == rhs);
		}

		//Negation operator
		vec4<T> operator-() const {
			return vec4<T>(-x, -y, -z, -w);
		}

		/* FUNCTIONS */

		//Length
		T length() const {
			return (T)std:sqrt(x*x + y*y + z*z + w*w);
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
			w /= s;
		}

		//Linear interpolation
		vec4<T> lerp(T fact, const vec4<T>& r) const {
			return (*this) + (r - (*this)) * fact;
		}

		//output to stream operator
		friend std::ostream& operator<<(std::ostream& lhs, const vec4<T>& rhs)
		{
			lhs << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.w << "]";
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

	// vec4 of floats
	typedef class vec4<float> vec4f;
	// vec4 of doubles
	typedef class vec4<double> vec4d;
	// vec4 of ints
	typedef class vec4<int> vec4i;


	template<class T>
	class Quaternion
	{
	public:
		/* DATA */

		T w; //real part

		vec3<T> v; //imaginary part

		/* CONSTRUCTORS */

		//Empty Constructor
		Quaternion() : w(0), v(0, 0, 0) {}

		//Copy Constructor
		Quaternion(const Quaternion<T>& q): w(q.w), v(q.v) {}

		//Copy Casting Constructor
		template<class FromT>
		Quaternion(const Quaternion<FromT>& q): w(static_cast<T>(q.w)), v(q.v) {}
	
		//Creates quaternion from real part v and imaginary part w
		Quaternion(T w_, const vec3<T>& v_): w(w_), v(v_) {}

		//Creates a quaternion from the given 4 values. in w, x, y, z order
		Quaternion(T w_, T x, T y, T z) : w(w_), v(x, y, z) {}

		/* COPY OPERATORS */

		//copy operator
		Quaternion<T>& operator=(const Quaternion<T>& rhs) {
			v = rhs.v;
			w = rhs.w;
			return *this;
		}

		//Copy and convert operator
		template<class FromT>
		Quaternion<T>& operator=(const Quaternion<FromT>& rhs) {
			v = rhs.v;
			w = static_cast<T>(rhs.w);
			return *this;
		}

		/* MATH OPERATORS */

		//Addition operator
		Quaternion<T> operator+(const Quaternion<T>& rhs) const {
			const Quaternion<T>& lhs = *this;
			return Quaternion<T>(lhs.w + rhs.w, lhs.v + rhs.v);
		}

		//Subtraction operator
		Quaternion<T> operator-(const Quaternion<T>& rhs) const {
			const Quaternion<T>& lhs = *this;
			return Quaternion<T>(lhs.w - rhs.w, lhs.v - rhs.v);
		}

		//Quaternion multiplication operator
		Quaternion<T> operator*(const Quaternion<T>& rhs) const	{
			const Quaternion<T>& lhs = *this;
			return Quaternion<T>(lhs.w * rhs.w - lhs.v.x * rhs.v.x - lhs.v.y * rhs.v.y - lhs.v.z * rhs.v.z,
				lhs.w * rhs.v.x + lhs.v.x * rhs.w + lhs.v.y * rhs.v.z - lhs.v.z * rhs.v.y,
				lhs.w * rhs.v.y - lhs.v.x * rhs.v.z + lhs.v.y * rhs.w + lhs.v.z * rhs.v.x,
				lhs.w * rhs.v.z + lhs.v.x * rhs.v.y - lhs.v.y * rhs.v.x + lhs.v.z * rhs.w);
		}

		//Scalar multiplication operator
		Quaternion<T> operator*(T rhs) const {
			return Quaternion<T>(w * rhs, v * rhs);
		}

		//Addition operator 
		Quaternion<T>& operator+=(const Quaternion<T>& rhs) {
			w += rhs.w;
			v += rhs.v;
			return *this;
		}

		//Subtraction operator
		Quaternion<T>& operator-=(const Quaternion<T>& rhs) {
			w -= rhs.w;
			v -= rhs.v;
			return *this;
		}

		//Quaternion multiplication operator
		Quaternion<T>& operator*=(const Quaternion<T>& rhs)	{
			Quaternion q = (*this) * rhs;
			v = q.v;
			w = q.w;
			return *this;
		}

		//Scalar multiplication operator
		Quaternion<T>& operator*=(T rhs) {
			w *= rhs;
			v *= rhs;
			return *this;
		}

		/* EQUALITY OPERATORS*/

		//Equality operator
		bool operator==(const Quaternion<T>& rhs) const {
			const Quaternion<T>& lhs = *this;
			return (std::abs(lhs.w - rhs.w) < EPSILON) && lhs.v == rhs.v;
		}

		//Inequality operator
		bool operator!=(const Quaternion<T>& rhs) const {
			return !(*this == rhs);
		}

		/* UNARY OPERATORS */

		//Negation
		Quaternion<T> operator-() const	{
			return Quaternion<T>(-w, -v);
		}

		//Conjugate
		Quaternion<T> operator~() const {
			return Quaternion<T>(w, -v);
		}

		/* FUNCTIONS */

		//Length
		T length() const {
			return (T)std::sqrt(w * w + v.lengthSq());
		}

		//Normalize
		void normalize() {
			T len = length();
			w /= len;
			v /= len;
		}

		//Creates a quaternion from euler angles
		static Quaternion<T> fromEulerAngles(T x, T y, T z) {
			Quaternion<T> ret = fromAxisRot(vec2<T>(1, 0, 0), x) * fromAxisRot(vec3<T>(0, 1, 0), y)
				* fromAxisRot(vec3<T>(0, 0, 1), z);
			return ret;
		}

		//Creates a quaternion as rotation around an axis
		static Quaternion<T> fromAxisRot(vec3<T> axis, float angleDeg) {
			double angleRad = DEG2RAD(angleDeg);
			double sa2 = std::sin(angleRad / 2);
			double ca2 = std::cos(angleRad / 2);
			return Quaternion<T>(ca2, axis * sa2);
		}

		//linear interpolation
		Quaternion<T> lerp(T fact, const Quaternion<T>& rhs) const {
			return Quaternion<T>((1 - fact) * w + fact * rhs.w, v.lerp(fact, rhs.v));
		}

		//Spherical interpolation
		Quaternion<T> slerp(T r, const Quaternion<T>& q2) const	{
			Quaternion<T> ret;
			T cosTheta = w * q2.w + v.x * q2.v.x + v.y * q2.v.y + v.z * q2.v.z;
			T theta = (T)acos(cosTheta);
			if (std::fabs(theta) < epsilon)
			{
				ret = *this;
			}
			else
			{
				T sinTheta = (T)std::sqrt(1.0 - cosTheta * cosTheta);
				if (std::fabs(sinTheta) < epsilon)
				{
					ret.w = 0.5 * w + 0.5 * q2.w;
					ret.v = v.lerp(0.5, q2.v);
				}
				else
				{
					T rA = (T)sin((1.0 - r) * theta) / sinTheta;
					T rB = (T)sin(r * theta) / sinTheta;

					ret.w = w * rA + q2.w * rB;
					ret.v.x = v.x * rA + q2.v.x * rB;
					ret.v.y = v.y * rA + q2.v.y * rB;
					ret.v.z = v.z * rA + q2.v.z * rB;
				}
			}
			return ret;
		}

		//Outputs to standard output stream
		friend std::ostream& operator <<(std::ostream& oss, const Quaternion<T>& q)	{
			oss << "Re: " << q.w << " Im: " << q.v;
			return oss;
		}

		//Gets string representation
		std::string toString() const {
			std::ostringstream oss;
			oss << *this;
			return oss.str();
		}
	};

	typedef Quaternion<float> Quatf;
	typedef Quaternion<double> Quatd;



	template <class T>
	class matrix44 {
	public:
		/* DATA */
		T data[16];

		/* CONSTRUCTORS */

		//Identity constructor
		matrix44() {
			for (int i = 0; i < 16; i++)
				data[i] = (i % 5) ? 0 : 1;
		}

		//Copy constructor
		template<class FromT>
		Matrix4(const Matrix4<FromT>& src) {
			for (int i = 0; i < 16; i++)
			{
				data[i] = static_cast<T>(src.data[i]);
			}
		}

		//Copy constructor
		Matrix4(const Matrix4<T>& src) {
			std::memcpy(data, src.data, sizeof(T) * 16);
		}

		/* FUNCTIONS */

		//Resets it to an identity matrix
		void identity() {
			for (int i = 0; i < 16; i++)
				data[i] = (i % 5) ? 0 : 1;
		}

		//Get at i,j 
		const T& at(int x, int y) const {
			assert(x >= 0 && x < 4);
			assert(y >= 0 && y < 4);
			return data[x * 4 + y];
		}

		//operator overload for at
		T& operator()(int i, int j)
		{
			assert(i >= 1 && i <= 4);
			assert(j >= 1 && j <= 4);
			return data[(j - 1) * 4 + i - 1];
		}

	};

	/// Matrix 4x4 of floats
	typedef matrix44<float> matrix44f;
	/// Matrix 4x4 of doubles
	typedef matrix44<double> matrix44d;
	/// Matrix 4x4 of int
	typedef matrix44<int> matrix44i;
}


#endif // CML_HEADER_FILE