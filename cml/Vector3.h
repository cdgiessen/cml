#pragma once

#ifndef VECTOR3_HEADER


/*
Constructors
empty, value given, copy, 

operations
 +  += ++ - -= --  *  *=  /  /=   negation, [] ! == != >= <= > <
 
 dot product
 cross product

 get/set
 
 lerp

 projection

 magnitude

 */
namespace cml {

	template<typename T>
	class Vector3
	{
	public:

		T x;
		T y;
		T z;

		//Default Constuctor
		Vector3() : x(0), y(0), z(0) {}

		//Initial value constructor
		Vector3(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal) {}





	private:

	};

	
	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	typedef Vector3<double> Vector3d;
}

#endif // !VECTOR3_HEADER
