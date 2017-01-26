#pragma once
namespace cml {


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
	};

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