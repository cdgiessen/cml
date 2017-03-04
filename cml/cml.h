#pragma once

#ifndef CML_HEADER

/*
Place for general functions that are outside of the other header files


*/
#include <cassert>
#include <string>
#include <ostream>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3.h"
#include "mat4.h"
#include "quat.h"

namespace cml {

#ifndef M_PI
#define M_PI           3.14159265358979323846  /* pi */
#endif

	const double epsilon = 4.37114e-05;

	//compares floating point numbers, returns true is "equal" and false if not
	template<typename T = double>
	bool cmpf(T A, T B)
	{
		return (fabs(A - B) < epsilon);
	}

	template<typename T = double>
	static inline T degToRad(T val) {
		return ((val * M_PI) / 180.0);
	}
	
	template<typename T = double>
	static inline T radToDeg(T val) {
		return ((180.0 * val) / M_PI);
	}

	template class vec2<float>;
	template class vec2<int>;
	template class vec2<double>;

	template class vec3<float>;
	template class vec3<int>;
	template class vec3<double>;

	template class vec4<float>;
	template class vec4<int>;
	template class vec4<double>;

	template class mat3<float>;
	template class mat3<int>;
	template class mat3<double>;

	template class mat4<float>;
	template class mat4<int>;
	template class mat4<double>;

	template class quat<float>;
	template class quat<double>;
}


#endif // !CML_HEADER