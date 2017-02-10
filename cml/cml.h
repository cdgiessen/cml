#pragma once

#ifndef CML_HEADER

/*
Place for general functions that are outside of the other header files


*/
#include <cassert>

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

	template<typename T = float>
	bool cmpf(T A, T B)
	{
		return (fabs(A - B) < epsilon);
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