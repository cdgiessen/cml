#pragma once

#include "vec3.h"
#include "vec4.h"

#include "mat3.h"

namespace cml
{

/* stuff to do.

setTRS (translation, rotation, and scaling)

static functions.
Create orthographic projection matrix
Create perspective projection matrix
create scale matrix
create TRS (translation, rotation, and scaling)
*/

template <typename T = float> class alignas (16 * alignof (T)) mat4
{
	private:
	static constexpr float identity_data[16]{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

	public:
	T data[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }; // Stored in column major order

	// Identity matrix constructor
	constexpr mat4 () noexcept {}

	// fill diagonal constructor
	constexpr mat4 (T const val) noexcept
	{
		data[0] = val;
		data[5] = val;
		data[10] = val;
		data[15] = val;
	}

	// Copy from array
	constexpr mat4 (T const val[16]) noexcept
	: data{ val[0],
		  val[4],
		  val[8],
		  val[12],
		  val[1],
		  val[5],
		  val[9],
		  val[13],
		  val[2],
		  val[6],
		  val[10],
		  val[14],
		  val[3],
		  val[7],
		  val[11],
		  val[15] }

	{
	}

	constexpr mat4 (T v00,
	    T const v01,
	    T const v02,
	    T const v03,
	    T const v10,
	    T const v11,
	    T const v12,
	    T const v13,
	    T const v20,
	    T const v21,
	    T const v22,
	    T const v23,
	    T const v30,
	    T const v31,
	    T const v32,
	    T const v33) noexcept
	: data{ v00, v10, v20, v30, v01, v11, v21, v31, v02, v12, v22, v32, v03, v13, v23, v33 }
	{
	}

	mat4 (vec4<T> const row_a, vec4<T> const row_b, vec4<T> const row_c, vec4<T> const row_d)
	{
		set_row (0, row_a);
		set_row (1, row_b);
		set_row (2, row_c);
		set_row (3, row_d);
	}

	mat4 (mat3<T> const rot, vec3<T> const trans)
	{
		set_mat3 (rot);
		set_col (3, trans);
	}

	// returns constant address to the data
	static T const* ptr (mat4<T> const& mat) { return &(mat.data[0]); }

	T const* ptr () { return &(data[0]); }

	T get (int i) const
	{
		assert (i >= 0 && i < 16);
		return data[i];
	}

	// Resets matrix to identity
	void set_identity () { data = identity_data; }

	// Checks if matrix is identity matrix
	bool isIdentity () { return (*this) == identity; }

	// Resets to zero matrix
	void zero ()
	{
		for (T i = 0; i < 16; i++)
			data[i] = 0;
	}

	// get at
	T& at (int const row, int const col)
	{
		assert (row >= 0 && row < 4 && col >= 0 && col < 4);
		return data[col * 4 + row];
	}

	T const& at (int const row, int const col) const
	{
		assert (row >= 0 && row < 4 && col >= 0 && col < 4);
		return data[col * 4 + row];
	}

	void set (int const row, int const col, T const value) { at (row, col) = value; }

	vec4<T> get_row (int const x) const
	{
		assert (x >= 0 && x < 4);
		return vec4<T> (at (x, 0), at (x, 1), at (x, 2), at (x, 3));
	}
	vec4<T> get_col (int const y) const
	{
		assert (y >= 0 && y < 4);
		return vec4<T> (at (0, y), at (1, y), at (2, y), at (3, y));
	}

	void set_row (int const x, vec3<T> const& val)
	{
		at (x, 0) = val.x;
		at (x, 1) = val.y;
		at (x, 2) = val.z;
	}

	void set_row (int x, vec4<T> const& val)
	{
		at (x, 0) = val.x;
		at (x, 1) = val.y;
		at (x, 2) = val.z;
		at (x, 3) = val.w;
	}

	void set_col (int y, vec3<T> const& val)
	{
		at (0, y) = val.x;
		at (1, y) = val.y;
		at (2, y) = val.z;
	}

	void set_col (int y, vec4<T> const& val)
	{
		at (0, y) = val.x;
		at (1, y) = val.y;
		at (2, y) = val.z;
		at (3, y) = val.w;
	}

	void set_mat3 (mat3<T> const& rot)
	{
		set_row (0, rot.get_row (0));
		set_row (1, rot.get_row (2));
		set_row (2, rot.get_row (1));
	}

	// MATRIX ADDITION

	mat4<T> operator+ (mat4<T> const& val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] + val.data[i];
		return out;
	}

	// SCALAR ADDITION
	mat4<T> operator+ (T const& val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] + val;
		return out;
	}

	// MATRIX SUBTRACTION

	mat4<T> operator- (mat4<T> const& val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] - val.data[i];
		return out;
	}

	// SCALAR SUBTRACTION
	mat4<T> operator- (T const val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] - val;
		return out;
	}

	// SCALAR MULTIPLICATION
	mat4<T> operator* (T const val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] * val;
		return out;
	}

	// VECTOR MULTIPLICATION

	vec4<T> operator* (vec4<T> const& val) const
	{
		return vec4<T> (data[0] * val.x + data[4] * val.y + data[8] * val.z + data[12] * val.w,
		    data[1] * val.x + data[5] * val.y + data[9] * val.z + data[13] * val.w,
		    data[2] * val.x + data[6] * val.y + data[10] * val.z + data[14] * val.w,
		    data[3] * val.x + data[7] * val.y + data[11] * val.z + data[15] * val.w);
	}

	// MATRIX MULTIPLICATION
	mat4<T> operator* (mat4<T> const& val) const
	{
		mat4<T> out;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				T n = 0;
				for (int k = 0; k < 4; k++)
				{
					n += at (i, k) * val.at (k, j);
				}
				out.at (i, j) = n;
			}
		}
		return out;
	}

	// SCALAR DIVISION
	mat4<T> operator/ (T const val) const
	{
		mat4<T> out;
		for (int i = 0; i < 16; i++)
			out.data[i] = data[i] / val;
		return out;
	}

	// EQUALITY CHECK
	bool operator== (mat4<T> const& val) const
	{
		for (int i = 0; i < 16; i++)
		{
			if (data[i] != val.data[i]) return false;
		}
		return true;
	}

	bool operator!= (mat4<T> const& val) { return !(*this == val); }

	// TRANSPOSE
	mat4<T> transpose () const
	{
		mat4<T> out;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				out.at (i, j) = at (j, i);
			}
		}
		return out;
	}

	T det () const
	{
		return at (0, 0) * at (1, 1) * at (2, 2) * at (3, 3) +
		       at (0, 0) * at (2, 1) * at (3, 2) * at (1, 3) +
		       at (0, 0) * at (3, 1) * at (1, 2) * at (2, 3) +
		       at (1, 0) * at (0, 1) * at (3, 2) * at (2, 3) +
		       at (1, 0) * at (2, 1) * at (0, 2) * at (3, 3) +
		       at (1, 0) * at (3, 1) * at (2, 2) * at (0, 3) +
		       at (2, 0) * at (0, 1) * at (1, 2) * at (3, 3) +
		       at (2, 0) * at (1, 1) * at (3, 2) * at (0, 3) +
		       at (2, 0) * at (3, 1) * at (0, 2) * at (1, 3) +
		       at (3, 0) * at (0, 1) * at (2, 2) * at (1, 3) +
		       at (3, 0) * at (1, 1) * at (0, 2) * at (2, 3) +
		       at (3, 0) * at (2, 1) * at (1, 2) * at (0, 3) -
		       at (0, 0) * at (1, 1) * at (3, 2) * at (2, 3) -
		       at (0, 0) * at (2, 1) * at (1, 2) * at (3, 3) -
		       at (0, 0) * at (3, 1) * at (2, 2) * at (1, 3) -
		       at (1, 0) * at (0, 1) * at (2, 2) * at (3, 3) -
		       at (1, 0) * at (2, 1) * at (3, 2) * at (0, 3) -
		       at (1, 0) * at (3, 1) * at (0, 2) * at (2, 3) -
		       at (2, 0) * at (0, 1) * at (3, 2) * at (1, 3) -
		       at (2, 0) * at (1, 1) * at (0, 2) * at (3, 3) -
		       at (2, 0) * at (3, 1) * at (1, 2) * at (0, 3) -
		       at (3, 0) * at (0, 1) * at (1, 2) * at (2, 3) -
		       at (3, 0) * at (1, 1) * at (2, 2) * at (0, 3) -
		       at (3, 0) * at (2, 1) * at (0, 2) * at (1, 3);
	}

	// INVERSE
	mat4<T> inverse () const
	{
		mat4<T> out;

		out.at (0, 0) = at (2, 1) * at (3, 2) * at (1, 3) - at (3, 1) * at (2, 2) * at (1, 3) +
		                at (3, 1) * at (1, 2) * at (2, 3) - at (1, 1) * at (3, 2) * at (2, 3) -
		                at (2, 1) * at (1, 2) * at (3, 3) + at (1, 1) * at (2, 2) * at (3, 3);

		out.at (1, 0) = at (3, 0) * at (2, 2) * at (1, 3) - at (2, 0) * at (3, 2) * at (1, 3) -
		                at (3, 0) * at (1, 2) * at (2, 3) + at (1, 0) * at (3, 2) * at (2, 3) +
		                at (2, 0) * at (1, 2) * at (3, 3) - at (1, 0) * at (2, 2) * at (3, 3);

		out.at (2, 0) = at (2, 0) * at (3, 1) * at (1, 3) - at (3, 0) * at (2, 1) * at (1, 3) +
		                at (3, 0) * at (1, 1) * at (2, 3) - at (1, 0) * at (3, 1) * at (2, 3) -
		                at (2, 0) * at (1, 1) * at (3, 3) + at (1, 0) * at (2, 1) * at (3, 3);

		out.at (3, 0) = at (3, 0) * at (2, 1) * at (1, 2) - at (2, 0) * at (3, 1) * at (1, 2) -
		                at (3, 0) * at (1, 1) * at (2, 2) + at (1, 0) * at (3, 1) * at (2, 2) +
		                at (2, 0) * at (1, 1) * at (3, 2) - at (1, 0) * at (2, 1) * at (3, 2);

		out.at (0, 1) = at (3, 1) * at (2, 2) * at (0, 3) - at (2, 1) * at (3, 2) * at (0, 3) -
		                at (3, 1) * at (0, 2) * at (2, 3) + at (0, 1) * at (3, 2) * at (2, 3) +
		                at (2, 1) * at (0, 2) * at (3, 3) - at (0, 1) * at (2, 2) * at (3, 3);

		out.at (1, 1) = at (2, 0) * at (3, 2) * at (0, 3) - at (3, 0) * at (2, 2) * at (0, 3) +
		                at (3, 0) * at (0, 2) * at (2, 3) - at (0, 0) * at (3, 2) * at (2, 3) -
		                at (2, 0) * at (0, 2) * at (3, 3) + at (0, 0) * at (2, 2) * at (3, 3);

		out.at (2, 1) = at (3, 0) * at (2, 1) * at (0, 3) - at (2, 0) * at (3, 1) * at (0, 3) -
		                at (3, 0) * at (0, 1) * at (2, 3) + at (0, 0) * at (3, 1) * at (2, 3) +
		                at (2, 0) * at (0, 1) * at (3, 3) - at (0, 0) * at (2, 1) * at (3, 3);

		out.at (3, 1) = at (2, 0) * at (3, 1) * at (0, 2) - at (3, 0) * at (2, 1) * at (0, 2) +
		                at (3, 0) * at (0, 1) * at (2, 2) - at (0, 0) * at (3, 1) * at (2, 2) -
		                at (2, 0) * at (0, 1) * at (3, 2) + at (0, 0) * at (2, 1) * at (3, 2);

		out.at (0, 2) = at (1, 1) * at (3, 2) * at (0, 3) - at (3, 1) * at (1, 2) * at (0, 3) +
		                at (3, 1) * at (0, 2) * at (1, 3) - at (0, 1) * at (3, 2) * at (1, 3) -
		                at (1, 1) * at (0, 2) * at (3, 3) + at (0, 1) * at (1, 2) * at (3, 3);

		out.at (1, 2) = at (3, 0) * at (1, 2) * at (0, 3) - at (1, 0) * at (3, 2) * at (0, 3) -
		                at (3, 0) * at (0, 2) * at (1, 3) + at (0, 0) * at (3, 2) * at (1, 3) +
		                at (1, 0) * at (0, 2) * at (3, 3) - at (0, 0) * at (1, 2) * at (3, 3);

		out.at (2, 2) = at (1, 0) * at (3, 1) * at (0, 3) - at (3, 0) * at (1, 1) * at (0, 3) +
		                at (3, 0) * at (0, 1) * at (1, 3) - at (0, 0) * at (3, 1) * at (1, 3) -
		                at (1, 0) * at (0, 1) * at (3, 3) + at (0, 0) * at (1, 1) * at (3, 3);

		out.at (3, 2) = at (3, 0) * at (1, 1) * at (0, 2) - at (1, 0) * at (3, 1) * at (0, 2) -
		                at (3, 0) * at (0, 1) * at (1, 2) + at (0, 0) * at (3, 1) * at (1, 2) +
		                at (1, 0) * at (0, 1) * at (3, 2) - at (0, 0) * at (1, 1) * at (3, 2);

		out.at (0, 3) = at (2, 1) * at (1, 2) * at (0, 3) - at (1, 1) * at (2, 2) * at (0, 3) -
		                at (2, 1) * at (0, 2) * at (1, 3) + at (0, 1) * at (2, 2) * at (1, 3) +
		                at (1, 1) * at (0, 2) * at (2, 3) - at (0, 1) * at (1, 2) * at (2, 3);

		out.at (1, 3) = at (1, 0) * at (2, 2) * at (0, 3) - at (2, 0) * at (1, 2) * at (0, 3) +
		                at (2, 0) * at (0, 2) * at (1, 3) - at (0, 0) * at (2, 2) * at (1, 3) -
		                at (1, 0) * at (0, 2) * at (2, 3) + at (0, 0) * at (1, 2) * at (2, 3);

		out.at (2, 3) = at (2, 0) * at (1, 1) * at (0, 3) - at (1, 0) * at (2, 1) * at (0, 3) -
		                at (2, 0) * at (0, 1) * at (1, 3) + at (0, 0) * at (2, 1) * at (1, 3) +
		                at (1, 0) * at (0, 1) * at (2, 3) - at (0, 0) * at (1, 1) * at (2, 3);

		out.at (3, 3) = at (1, 0) * at (2, 1) * at (0, 2) - at (2, 0) * at (1, 1) * at (0, 2) +
		                at (2, 0) * at (0, 1) * at (1, 2) - at (0, 0) * at (2, 1) * at (1, 2) -
		                at (1, 0) * at (0, 1) * at (2, 2) + at (0, 0) * at (1, 1) * at (2, 2);

		return out / det ();
	}

	constexpr mat4<T>& set_translation (vec3<T> v)
	{
		set_col (3, v);
		return *this;
	}
	constexpr mat4<T>& set_translation (vec4<T> v)
	{
		set_col (3, v);
		return *this;
	}

	constexpr mat4<T>& translate (vec3<T> v)
	{
		set_col (3, vec4<T> (v.x, v.y, v.z, 0) + get_col (3));
		return *this;
	}
	constexpr mat4<T>& translate (vec4<T> v)
	{
		set_col (3, v + get_col (3));
		return *this;
	}

	constexpr mat4<T>& scale (T s)
	{
		set (0, 0, at (0, 0) * s);
		set (1, 1, at (1, 1) * s);
		set (2, 2, at (2, 2) * s);
		return *this;
	}
	constexpr mat4<T>& scale (vec3<T> s)
	{
		set (0, 0, at (0, 0) * s.x);
		set (1, 1, at (1, 1) * s.y);
		set (2, 2, at (2, 2) * s.z);
		return *this;
	}

	constexpr mat4<T>& set_scale (T s)
	{
		set (0, 0, at (0, 0) * s);
		set (1, 1, at (1, 1) * s);
		set (2, 2, at (2, 2) * s);
		return *this;
	}
	constexpr mat4<T>& set_scale (vec3<T> s)
	{
		set (0, 0, at (0, 0) * s.x);
		set (1, 1, at (1, 1) * s.y);
		set (2, 2, at (2, 2) * s.z);
		return *this;
	}


	static mat4<T> identity;
};

template <typename T> vec4<T> operator* (vec4<T> const& val, mat4<T> const& m)
{
	return vec4<T> (m.data[0] * val.x + m.data[4] * val.y + m.data[8] * val.z + m.data[12] * val.w,
	    m.data[1] * val.x + m.data[5] * val.y + m.data[9] * val.z + m.data[13] * val.w,
	    m.data[2] * val.x + m.data[6] * val.y + m.data[10] * val.z + m.data[14] * val.w,
	    m.data[3] * val.x + m.data[7] * val.y + m.data[11] * val.z + m.data[15] * val.w);
}

template <typename T>
mat4<T> mat4<T>::identity = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

typedef mat4<float> mat4f;
typedef mat4<double> mat4d;




} // namespace cml
