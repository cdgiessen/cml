#pragma once

#include "cml.h"

#include <ostream>
#include <string>

namespace cml
{

using namespace std::string_literals;

template <typename T> std::string to_string (const vec2<T>& v)
{
	return "["s + v.x + "," + v.y + "]";
}

template <typename T> std::string to_string (const vec3<T>& v)
{
	return "["s + v.x + "," + v.y + "," + v.z + "]";
}

template <typename T> std::string to_string (const vec4<T>& v)
{
	return "["s + v.x + "," + v.y + "," + v.z + "," + v.w + "]";
}

template <typename T> std::string to_string (const mat3<T>& m)
{
	return "["s + m.data[0] + "," + m.data[3] + "," + m.data[6] + "," + m.data[1] + "," +
	       m.data[4] + "," + m.data[7] + "," + m.data[2] + "," + m.data[5] + "," + m.data[8] + "]";
}

template <typename T> std::string to_string (const mat4<T>& m)
{
	return "["s + m.data[0] + "," + m.data[4] + "," + m.data[8] + "," + m.data[12] + "," +
	       m.data[1] + "," + m.data[5] + "," + m.data[9] + "," + m.data[13] + "," + m.data[2] +
	       "," + m.data[6] + "," + m.data[10] + "," + m.data[14] + "," + m.data[3] + "," +
	       m.data[7] + "," + m.data[11] + "," + m.data[15] + "]";
}

template <typename T> std::string to_string (const quat<T>& v)
{
	return "["s + to_string (v.imag) + "," + v.real + "]";
}



template <typename T> std::ostream& operator<< (std::ostream& strm, const vec2<T>& v)
{
	return strm << "[" << v.x << "," << v.y << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, const vec3<T>& v)
{
	return strm << "[" << v.x << "," << v.y << "," << v.z << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, const vec4<T>& v)
{
	return strm << "[" << v.x << "," << v.y << "," << v.z << "," << v.w << "]";
}


template <typename T> std::ostream& operator<< (std::ostream& strm, const mat3<T>& m)
{
	return strm << "[" << m.data[0] << "," << m.data[3] << "," << m.data[6] << "," << m.data[1]
	            << "," << m.data[4] << "," << m.data[7] << "," << m.data[2] << "," << m.data[5]
	            << "," << m.data[8] << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, const mat4<T>& m)
{
	return strm << "[" << m.data[0] << "," << m.data[4] << "," << m.data[8] << "," << m.data[12]
	            << "," << m.data[1] << "," << m.data[5] << "," << m.data[9] << "," << m.data[13] << ","
	            << m.data[2] << "," << m.data[6] << "," << m.data[10] << "," << m.data[14] << ","
	            << m.data[3] << "," << m.data[7] << "," << m.data[11] << "," << m.data[15] << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, const quat<T>& v)
{
	return strm << "[" << v.imag << "," << v.real << "]";
}

} // namespace cml