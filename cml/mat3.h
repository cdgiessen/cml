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
		T data[9];

		//Identity matrix constructor
		mat3() :data{ 1,0,0,0,1,0,0,0,1 } {	}

		//copy from array
		mat3(const T val[9]) : data{ val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7], val[8]} {}

		//Copy constructor
		mat3(const mat3<T>& in) : data{ in.at(0,0), in.at(0,1), in.at(0,2), in.at(1,0), in.at(1,1), in.at(1,2), in.at(2,0), in.at(2,1), in.at(2,2) } {}

		//Constructor for values
		mat3(const T v00, const T v01, const T v02, const T v10, const T v11, const T v12, const T v20, const T v21, const T v22) : 
			data{ v00,v01,v02,v10,v11,v12,v20,v21,v22 } {}

		//Resets matrix to identity
		void identity() {
			for (int i = 0; i < 9; i++)
			{
				data[i] = (i % 4) ? 0 : 1;
			}
		}

		void zero() {
			for (int i = 0; i < 9; i++)	{
				data[i] = 0;
			}
		}

		//Get at 
		T& at(int x, int y) {
			return data[x * 3 + y];
		}

		//Const get at
		const T& at(int x, int y) const {
			return data[x * 3 + y];
		}




		//put to output
		friend std::ostream& operator<<(std::ostream &strm, const mat3<T> &m) {
			return strm << "[[ " << m.data[0] << ", " << m.data[1] << ", " << m.data[2] << "],	"
				<< "[ " << m.data[3] << ", " << m.data[4] << ", " << m.data[5] << "],	"
				<< "[ " << m.data[6] << ", " << m.data[7] << ", " << m.data[8] << "]]";
		}
	};

	typedef mat3<float> mat3f;
	typedef mat3<int> mat3i;
	typedef mat3<double> mat3d;
}

#endif // !MATRIX3_HEADER
