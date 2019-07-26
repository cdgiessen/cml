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
	return "["s + m.get (0) + "," + m.get (3) + "," + m.get (6) + "," + m.get (1) + "," +
	       m.get (4) + "," + m.get (7) + "," + m.get (2) + "," + m.get (5) + "," + m.get (8) + "]";
}

template <typename T> std::string to_string (mat4<T> const& m)
{
	return "["s + m.get (0) + "," + m.get (4) + "," + m.get (8) + "," + m.get (12) + "," +
	       m.get (1) + "," + m.get (5) + "," + m.get (9) + "," + m.get (13) + "," + m.get (2) +
	       "," + m.get (6) + "," + m.get (10) + "," + m.get (14) + "," + m.get (3) + "," +
	       m.get (7) + "," + m.get (11) + "," + m.get (15) + "]";
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
	strm << "[";
	for (int i = 0; i < 8; i++)
	{
		strm << m.get (i) << ",";
	}
	return strm << m.get (8) << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, mat4<T> const& m)
{
	strm << "[";
	for (int i = 0; i < 15; i++)
	{
		strm << m.get (i) << ",";
	}
	return strm << m.get (15) << "]";
}

template <typename T> std::ostream& operator<< (std::ostream& strm, quat<T> const& v)
{
	return strm << "[" << v.getImag () << "," << v.getReal () << "]";
}

} // namespace cml