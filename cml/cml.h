#pragma once
namespace cml {

#include <math.h>  
#pragma once

	//Vector operations add, sub, scalar multiply, scalar division,
	//Vector functions cross, distance, dot, faceforward, length, normalize, reflect
	class vec2 {
	public:
		float x;
		float y;

		vec2(float a, float b) :x(a), y(b) {

		}

		const vec2 &operator +=(const vec2 &val) {
			x = x + val.x;
			y = y + val.y;
			return *this;
		}

		const vec2 &operator -=(const vec2 &val) {
			x = x - val.x;
			y = y - val.y;
			return *this;
		}

		const vec2 &operator+(const vec2 &b) {
			return vec2(*this) += b;
		}

		const vec2 &operator-(const vec2 &b) {
			return vec2(*this) -= b;
		}

		const vec2 &operator*(const float &f) {
			x = x*f;
			y = y*f;
			return *this;
		}

		vec2 &operator/(const float &a) {
			if (a == 0) {
				std::cerr << "DIVIDE BY ZERO. DOES NOT COMPUTE" << std::endl;
				return (*this);
			}
			else {
				x = x / a;
				y = y / a;
				return *this;
			}
		}
		
		const float &length() {
			return sqrt((x)*(x) + (y)*(y));
		}
	};

	const float dot(const vec2 &a, const vec2 &b) {
		return a.x*b.x + a.y*b.y;
	}

	const float distance(const vec2 &a, const vec2 &b) {
		return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	}

	const vec2 normalize(const vec2 &a) {
		return vec2(a.x * (1.0f/ a.length), a.y * (1.0f / a.length));
	}

	const vec2 &reflect(const vec2 &I, const vec2 &N) {
		return I - 2.0f*dot(I, N)* N;
	}


	// TODO AFTER I FIGURE OUT VEC2 FIRST

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
















}