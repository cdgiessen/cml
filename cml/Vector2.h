#pragma once

#ifndef VECTOR2_HEADER

namespace cml {

	template<typename T>
	class Vector2
	{
	public:

		T x;
		T y;
		T z;

		//Default Constuctor
		Vector2() : x(0), y(0), z(0) {}

		//Initial value constructor
		Vector2(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}





	private:

	};


	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<double> Vector2d;


}

#endif // !VECTOR2_HEADER
