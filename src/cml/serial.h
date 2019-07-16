#pragma once

#include "cml.h"

#include <ostream>
#include <string>

namespace cml
{

using namespace std::string_literals;

template <typename T> std::string to_string (vec2<T> const& v)
{
	return "["s + v.x + "," + v.y + "]";
}

template <typename T> std::string to_string (vec3<T> const& v)
{
	return "["s + v.x + "," + v.y + "," + v.z + "]";
}

template <typename T> std::string to_string (vec4<T> const& v)
{
	return "["s + v.x + "," + v.y + "," + v.z + "," + v.w + "]";
}

template <typename T> std::string to_string (mat3<T> const& m)
{
	return "["s + m.data[0] + "," + m.data[3] + "," + m.data[6] + "," + m.data[1] + "," +
	       m.data[4] + "," + m.data[7] + "," + m.data[2] + "," + m.data[5] + "," + m.data[8] + "]";
}

template <typename T> std::string to_string (mat4<T> const& m)
{
	return "["s + m.data[0] + "," + m.data[4] + "," + m.data[8] + "," + m.data[12] + "," +
	       m.data[1] + "," + m.data[5] + "," + m.data[9] + "," + m.data[13] + "," + m.data[2] +
	       "," + m.data[6] + "," + m.data[10] + "," + m.data[14] + "," + m.data[3] + "," +
	       m.data[7] + "," + m.data[11] + "," + m.data[15] + "]";
}

template <typename T> std::string to_string (quat<T> const& v)
{
	return "["s + to_string (v.imag) + "," + v.real + "]";
}


template <typename T> std::ostream& operator<< (std::ostream& strm, vec2<T> const& v)
{
	return strm << "[" << v.x << "," << v.y << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, vec3<T> const& v)
{
	return strm << "[" << v.x << "," << v.y << "," << v.z << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, vec4<T> const& v)
{
	return strm << "[" << v.x << "," << v.y << "," << v.z << "," << v.w << "]";
}


template <typename T> std::ostream& operator<< (std::ostream& strm, mat3<T> const& m)
{
	return strm << "[" << m.data[0] << "," << m.data[3] << "," << m.data[6] << "," << m.data[1]
	            << "," << m.data[4] << "," << m.data[7] << "," << m.data[2] << "," << m.data[5]
	            << "," << m.data[8] << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, mat4<T> const& m)
{
	return strm << "[" << m.data[0] << "," << m.data[4] << "," << m.data[8] << "," << m.data[12]
	            << "," << m.data[1] << "," << m.data[5] << "," << m.data[9] << "," << m.data[13] << ","
	            << m.data[2] << "," << m.data[6] << "," << m.data[10] << "," << m.data[14] << ","
	            << m.data[3] << "," << m.data[7] << "," << m.data[11] << "," << m.data[15] << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, quat<T> const& v)
{
	return strm << "[" << v.getImag () << "," << v.getReal () << "]";
}

} // namespace cml