#pragma once

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

// temp!

namespace cml
{

template <typename T = float> class mat3
{
	private:
	static constexpr float identity_data[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

	public:
	T data[9]; // Stored in column major order

	// Identity matrix constructor
	constexpr mat3 () : data{ 1, 0, 0, 0, 1, 0, 0, 0, 1 } {}

	// copy from array
	constexpr mat3 (T const val[9])
	: data{ val[0], val[3], val[6], val[1], val[4], val[7], val[2], val[5], val[8] }
	{
	}

	// Constructor for values
	constexpr mat3 (
	    T const v00, T const v01, T const v02, T const v10, T const v11, T const v12, T const v20, T const v21, T const v22) noexcept
	: data{ v00, v10, v20, v01, v11, v21, v02, v12, v22 }
	{
	}

	constexpr mat3 (vec3<T> const row_a, vec3<T> const row_b, vec3<T> const row_c)
	{
		set_row (0, row_a);
		set_row (1, row_b);
		set_row (2, row_c);
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
	T& at (int row, int col) { return data[col * 3 + row]; }

	// Const get at
	const T& at (int row, int col) const { return data[col * 3 + row]; }

	void set (int const row, int const col, T const val) const { at (row, col) = val; }

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

	// MATRIX ADDITION

	mat3<T> operator+ (mat3<T> const& val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] + val.data[i];
		return out;
	}

	// SCALAR ADDITION
	mat3<T> operator+ (vec3<T> const& val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] + val;
		return out;
	}

	// MATRIX SUBTRACTION

	mat3<T> operator- (mat3<T> const& val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] - val.data[i];
		return out;
	}

	// SCALAR SUBTRACTION
	mat3<T> operator- (T const val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] - val;
		return out;
	}

	// SCALAR MULTIPLICATION
	mat3<T> operator* (T const val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] * val;
		return out;
	}

	// VECTOR MULTIPLICATION
	vec3<T> operator* (const vec3<T>& val)
	{
		return vec3<T> (data[0] * val.x + data[3] * val.y + data[6] * val.z,
		    data[1] * val.x + data[4] * val.y + data[7] * val.z,
		    data[2] * val.x + data[5] * val.y + data[8] * val.z);
	}

	// MATRIX MULTIPLICATION
	mat3<T> operator* (mat3<T> const& val) const
	{
		return mat3<T> (at (0, 0) * val.at (0, 0) + at (0, 1) * val.at (1, 0) + at (0, 2) * val.at (2, 0),
		    at (0, 0) * val.at (0, 1) + at (0, 1) * val.at (1, 1) + at (0, 2) * val.at (2, 1),
		    at (0, 0) * val.at (0, 2) + at (0, 1) * val.at (1, 2) + at (0, 2) * val.at (2, 2),
		    at (1, 0) * val.at (0, 0) + at (1, 1) * val.at (1, 0) + at (1, 2) * val.at (2, 0),
		    at (1, 0) * val.at (0, 1) + at (1, 1) * val.at (1, 1) + at (1, 2) * val.at (2, 1),
		    at (1, 0) * val.at (0, 2) + at (1, 1) * val.at (1, 2) + at (1, 2) * val.at (2, 2),
		    at (2, 0) * val.at (0, 0) + at (2, 1) * val.at (1, 0) + at (2, 2) * val.at (2, 0),
		    at (2, 0) * val.at (0, 1) + at (2, 1) * val.at (1, 1) + at (2, 2) * val.at (2, 1),
		    at (2, 0) * val.at (0, 2) + at (2, 1) * val.at (1, 2) + at (2, 2) * val.at (2, 2));
	}

	// SCALAR DIVISION
	mat3<T> operator/ (T const val) const
	{
		mat3<T> out;
		for (int i = 0; i < 9; i++)
			out.data[i] = data[i] / val;
		return out;
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

	T det () const
	{
		return at (0, 0) * (at (1, 1) * at (2, 2) - at (1, 2) * at (2, 1)) -
		       at (0, 1) * (at (1, 0) * at (2, 2) - at (1, 2) * at (2, 0)) +
		       at (0, 2) * (at (1, 0) * at (2, 1) - at (1, 1) * at (2, 0));
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

	mat3<T> inverse () const
	{
		// m_row_col
		T m00 = at (1, 1) * at (2, 2) - at (1, 2) * at (2, 1);
		T m01 = at (1, 0) * at (2, 2) - at (1, 2) * at (2, 0);
		T m02 = at (1, 0) * at (2, 1) - at (1, 1) * at (2, 0);

		T m10 = at (0, 1) * at (2, 2) - at (0, 2) * at (2, 1);
		T m11 = at (0, 0) * at (2, 2) - at (0, 2) * at (2, 0);
		T m12 = at (0, 0) * at (2, 1) - at (0, 1) * at (2, 0);

		T m20 = at (0, 1) * at (1, 2) - at (0, 2) * at (1, 1);
		T m21 = at (0, 0) * at (1, 2) - at (0, 2) * at (1, 0);
		T m22 = at (0, 0) * at (1, 1) - at (0, 1) * at (1, 0);

		return mat3<T> (m00, -m01, m02, -m10, m11, -m12, m20, -m21, m22).transpose () / det ();
	}


	static const mat3<T> identity;
};

template <typename T> const mat3<T> mat3<T>::identity = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

typedef mat3<float> mat3f;
typedef mat3<int> mat3i;
typedef mat3<double> mat3d;
} // namespace cml
