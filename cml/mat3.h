#pragma once

#ifndef MATRIX3_HEADER


/* stuff to do.

static vars: identity and zero;

determinant
inverse
isIdentity
[i,j]
transpose
Operator * (multiply matricies)

get row, get column
set row, set column

setTRS (translation, rotation, and scaling)

toString

static functions.
Create orthographic projection matrix
Create perspective projection matrix
create scale matrix
create TRS (translation, rotation, and scaling)


*/


namespace cml {

	template <typename T = float>
	class mat3 {
	public:
		T data[3][3];

		//Identity matrix constructor
		mat3() {
			identity();
		}

		//Resets matrix to identity
		void identity() {
			data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
			data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
			data[2][0] = 0; data[2][1] = 0; data[2][2] = 1;
		}

		void zero() {
			data[0][0] = 0; data[0][1] = 0; data[0][2] = 0;
			data[1][0] = 0;	data[1][1] = 0; data[1][2] = 0;
			data[2][0] = 0;	data[2][1] = 0; data[2][2] = 0;
		}

	};

	typedef mat3<float> mat3f;
	typedef mat3<int> mat3i;
	typedef mat3<double> mat3d;
}

#endif // !MATRIX3_HEADER
