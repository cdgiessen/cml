#pragma once

#include "mat3.h"
#include "mat4.h"
#include "vec3.h"
#include "vec4.h"


namespace cml
{

template <typename T>
constexpr mat4<T> lookAt (const vec3<T>& eyePos, const vec3<T>& centerPos, vec3<T>& upDir)
{

	mat4<T> m;
	vec3<T> forward = (centerPos - eyePos).norm ();
	vec3<T> side = vec3<T>::cross (forward, upDir).norm ();
	vec3<T> up = vec3<T>::cross (side, forward);

	m.set_column (0, side);
	m.set_column (1, up);
	m.set_column (2, -forward);
	m.at (3, 0) = -vec3<T>::dot (side, eyePos);
	m.at (3, 1) = -vec3<T>::dot (up, eyePos);
	m.at (3, 2) = vec3<T>::dot (forward, eyePos);

	return m;
}

template <typename T> constexpr mat4<T> frustum (T left, T right, T bottom, T top, T zNear, T zFar)
{
	mat4<T> ret;

	const T invWidth = 1.0 / (right - left);
	const T invHeight = 1.0 / (top - bottom);
	const T invDepth = 1.0 / (zFar - zNear);

	const T twoZNear = 2 * zNear;

	ret.at (0, 0) = twoZNear * invWidth;
	ret.at (1, 1) = twoZNear * invHeight;

	ret.at (2, 0) = (right + left) * invWidth;
	ret.at (2, 1) = (top + bottom) * invHeight;
	ret.at (2, 2) = -(zFar + zNear) * invDepth;
	ret.at (2, 3) = -1;

	ret.at (3, 2) = -twoZNear * zFar * invDepth;

	return ret;
}

template <typename T> constexpr mat4<T> perspective (T fovy, T aspect, T zNear, T zFar)
{
	// assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

	T const tanHalfFovy = tan (fovy / static_cast<T> (2));
	mat4<T> out;
	out.at (0, 0) = static_cast<T> (1) / (aspect * tanHalfFovy);
	out.at (1, 1) = static_cast<T> (1) / (tanHalfFovy);
	out.at (2, 3) = -static_cast<T> (1);

	out.at (2, 2) = -(zFar + zNear) / (zFar - zNear);
	out.at (3, 2) = -(static_cast<T> (2) * zFar * zNear) / (zFar - zNear);
	out.at (3, 3) = 0;

	return out;
}

template <typename T> mat4<T> ortho (T left, T right, T bottom, T top, T near, T far)
{
	mat4<T> out;

	out.at (0, 0) = 2 / (right - left);
	out.at (1, 1) = 2 / (top - bottom);
	out.at (2, 2) = -2 / (far - near);

	out.at (3, 0) = -(left + right) / (right - left);
	out.at (3, 1) = -(top + bottom) / (top - bottom);
	out.at (3, 2) = -(far + near) / (far - near);

	return out;
}


} // namespace cml