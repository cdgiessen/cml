#pragma once

#ifndef VECTOR4_HEADER

namespace cml {

	template<typename T>
	class vec4
	{
	public:

		T x;
		T y;
		T z;
		T w;

		//Default Constuctor
		vec4() : x(0), y(0), z(0) {}

		//Initial value constructor
		vec4(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}

		

	};


	typedef vec4<float> vec4f;
	typedef vec4<int> vec4i;
	typedef vec4<double> vec4d;


}

#endif // !VECTOR4_HEADER
