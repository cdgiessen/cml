#pragma once

#ifndef VECTOR2_HEADER

namespace cml {

	template<typename T>
	class vec2
	{
	public:

		T x;
		T y;
		T z;

		//Default Constuctor
		vec2() : x(0), y(0), z(0) {}

		//Initial value constructor
		vec2(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}





	private:

	};


	typedef vec2<float> vec2f;
	typedef vec2<int> vec2i;
	typedef vec2<double> vec2d;


}

#endif // !VECTOR2_HEADER
