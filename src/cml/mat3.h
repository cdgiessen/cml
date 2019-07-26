#pragma once

#include "common.h"
#include "vec3.h"

/* stuff to do.

determinant
inverse
isIdentity
[i,j]
transpose
Operator * (multiply matricies)

setTRS (translation, rotation, and scaling)


static functions.
Create orthographic projection matrix
Create perspective projection matrix
create scale matrix
create TRS (translation, rotation, and scaling)


*/


namespace cml
{

template <typename T = float> class mat3
{
	private:
	static constexpr float identity_data[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

	public:
	T data[16]; // Stored in column major order

	// Identity matrix constructor
	mat3 () : data{ 1, 0, 0, 0, 1, 0, 0, 0, 1 } {}

	// copy from array
	mat3 (T const val[9])
	{
		for (int i = 0; i < 9; i++)
		{
			data[i] = val[i];
		}
	}

	// Constructor for values
	constexpr mat3 (
	    T const v00, T const v01, T const v02, T const v10, T const v11, T const v12, T const v20, T const v21, T const v22) noexcept
	: data{ v00, v01, v02, v10, v11, v12, v20, v21, v22 }
	{
	}

	// returns constant address to the data
	static T const* ptr (mat3<T> const& mat) { return &(mat.data[0]); }

	T get (int i) const
	{
		assert (i >= 0 && i <= 8);
		return data[i];
	}

	// Resets matrix to identity
	void set_identity () { data = identity_data; }

	void zero ()
	{
		for (int i = 0; i < 9; i++)
		{
			data[i] = 0;
		}
	}

	// Get at
	T& at (int x, int y) { return data[x * 3 + y]; }

	// Const get at
	const T& at (int x, int y) const { return data[x * 3 + y]; }

	vec3<T> get_row (int x) const
	{
		assert (x >= 0 && x < 3);
		return vec3<T> (at (x, 0), at (x, 1), at (x, 2));
	}
	vec3<T> get_col (int y) const
	{
		assert (y >= 0 && y < 3);
		return vec3<T> (at (0, y), at (1, y), at (2, y));
	}

	void set_row (const int i, const vec3<T>& val)
	{
		at (0, i) = val.x;
		at (1, i) = val.y;
		at (2, i) = val.z;
	}

	void set_column (const int i, const vec3<T>& val)
	{
		at (i, 0) = val.x;
		at (i, 1) = val.y;
		at (i, 2) = val.z;
	}

	// EQUALITY CHECK
	bool operator== (const mat3<T>& val) const
	{
		for (int i = 0; i < 9; i++)
		{
			if (data[i] != val.data[i]) return false;
		}
		return true;
	}

	bool operator!= (const mat3<T>& val) const { return !(*this == val); }

	// Creates a rotation matrix with specified values in degrees
	static mat3<T> createRotationMatrix (const T xRot, const T yRot, const T zRot)
	{
		T xRad = radians (xRot);
		T yRad = radians (yRot);
		T zRad = radians (zRot);

		mat3<T> ma, mb, mc;
		float ac = cos (xRad);
		float as = sin (xRad);
		float bc = cos (yRad);
		float bs = sin (yRad);
		float cc = cos (zRad);
		float cs = sin (zRad);

		ma.at (1, 1) = ac;
		ma.at (2, 1) = as;
		ma.at (1, 2) = -as;
		ma.at (2, 2) = ac;

		mb.at (0, 0) = bc;
		mb.at (2, 0) = -bs;
		mb.at (0, 2) = bs;
		mb.at (2, 2) = bc;

		mc.at (0, 0) = cc;
		mc.at (1, 0) = cs;
		mc.at (0, 1) = -cs;
		mc.at (1, 1) = cc;

		return ma * mb * mc;
	}

	// VECTOR MULTIPLICATION
	vec3<T> operator* (const vec3<T>& val)
	{
		return vec3<T> (data[0] * val.x + data[3] * val.y + data[6] * val.z,
		    data[1] * val.x + data[4] * val.y + data[7] * val.z,
		    data[2] * val.x + data[5] * val.y + data[8] * val.z);
	}

	// MATRIX MULTIPLICATION
	mat3<T> operator* (const mat3<T> val) const
	{
		mat3<T> w;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				T n = 0;
				for (int k = 0; k < 3; k++)
					n += val.at (i, k) * at (k, j);
				w.at (i, j) = n;
			}
		}
		return w;
	}

	// TRANSPOSE
	mat3<T> transpose () const
	{
		mat3<T> out;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				out.at (i, j) = at (j, i);
			}
		}
		return out;
	}

	static const mat3<T> identity;
};

template <typename T> const mat3<T> mat3<T>::identity = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

typedef mat3<float> mat3f;
typedef mat3<int> mat3i;
typedef mat3<double> mat3d;
} // namespace cml
