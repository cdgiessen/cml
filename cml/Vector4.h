#pragma once

#ifndef VECTOR4_HEADER

namespace cml {

	template<typename T>
	class Vector4
	{
	public:

		T x;
		T y;
		T z;
		T w;

		//Default Constuctor
		Vector4() : x(0), y(0), z(0) {}

		//Initial value constructor
		Vector4(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}





	private:

	};


	typedef Vector4<float> Vector4f;
	typedef Vector4<int> Vector4i;
	typedef Vector4<double> Vector4d;


}

#endif // !VECTOR4_HEADER
