#pragma once

#include "mat3.h"
#include "mat4.h"


namespace cml
{

template <typename T>
constexpr mat4<T> lookAt (const vec3<T>& eyePos, const vec3<T>& centerPos, vec3<T>& upDir)
{

	mat4<T> m{};
	vec3<T> forward = normalize (centerPos - eyePos);
	vec3<T> side = normalize (cross (forward, upDir));
	vec3<T> up = cross (side, forward);

	m.set_row (0, side);
	m.set_row (1, up);
	m.set_row (2, -forward);
	m.at (0, 3) = -dot (side, eyePos);
	m.at (1, 3) = -dot (up, eyePos);
	m.at (2, 3) = dot (forward, eyePos);

	return m;
}

template <typename T> constexpr mat4<T> frustum (T left, T right, T bottom, T top, T zNear, T zFar)
{
	mat4<T> ret{};

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

/*
    Perspective projection matrix:
    Right handed,
    depth range 0-1,
    & reversed depth buffer

 */
template <typename T> constexpr mat4<T> perspective (T fovy, T aspect, T zNear, T zFar)
{
	// assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

	T const tanHalfFovy = tan (fovy / static_cast<T> (2));

	mat4<T> Result{};
	Result.at (0, 0) = static_cast<T> (1) / (aspect * tanHalfFovy);
	Result.at (1, 1) = static_cast<T> (1) / (tanHalfFovy);
	Result.at (2, 2) = static_cast<T> (0.0);
	Result.at (3, 3) = static_cast<T> (0.0);
	// Result.at (2, 2) = zFar / (zNear - zFar);
	// Result.at (2, 3) = -(zFar * zNear) / (zFar - zNear);
	Result.at (2, 3) = zNear;
	Result.at (3, 2) = static_cast<T> (-1.0);

	Result.at (1, 1) *= -1.f;
	return Result;

	// T const tanHalfFovy = tan (fovy / static_cast<T> (2));
	// mat4<T> out{};
	// out.at (0, 0) = static_cast<T> (1) / (aspect * tanHalfFovy);
	// out.at (1, 1) = static_cast<T> (1) / (tanHalfFovy);
	// out.at (2, 3) = -static_cast<T> (1);
	//
	// out.at (2, 2) = -(zFar + zNear) / (zFar - zNear);
	// out.at (3, 2) = -(static_cast<T> (2) * zFar * zNear) / (zFar - zNear);
	// out.at (3, 3) = 1;
	//
	// return out;
}

template <typename T> constexpr mat4<T> infinitePerspective (T fovy, T aspect, T zNear)
{
	T const range = tan (fovy / T (2)) * zNear;

	T left = -range * aspect;
	T right = range * aspect;
	T bottom = -range;
	T top = range;

	mat4<T> Result{ T (0) };
	Result.at (0, 0) = (T (2) * zNear) / (right - left);
	Result.at (1, 1) = (T (2) * zNear) / (top - bottom);
	Result.at (2, 2) = -T (1);
	Result.at (2, 3) = -T (1);
	Result.at (3, 2) = -T (2) * zNear;
	return Result;
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