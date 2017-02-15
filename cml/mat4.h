#pragma once

#include <string>


#ifndef MATRIX44_HEADER

namespace cml {

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

	//matrices are column order, 
	/*
		so data = { x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4 } 
	*/
	template<typename T>
	class mat4 {
	public:
		T data[4][4];

		//Identity matrix constructor
		mat4() : data{ {1,0,0,0 }, {0,1,0,0}, {0,0,1,0}, {0,0,0,1} } {}

		//Copy constructor
		mat4(const T val[4][4]) : data{ { val[0][0],val[0][1],val[0][2],val[0][3] },{ val[1][0],val[1][1],val[1][2],val[1][3] },
										{ val[2][0],val[2][1],val[2][2],val[2][3] },{ val[3][0],val[3][1],val[3][2],val[3][3] } } {}

		//Constructor from values
		mat4(const T n00, const T n01, const T n02, const T n03, const T n10, const T n11, const T n12, const T n13, 
			 const T n20, const T n21, const T n22, const T n23, const T n30, const T n31, const T n32, const T n33) : data
		{ {n00,n01,n02,n03}, { n10,n11,n12,n13 }, { n20,n21,n22,n23 }, { n30,n31,n32,n33 } } {}

		//Resets matrix to identity
		void identity() {
			//data = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
			data[0][0] = 1;	data[0][1] = 0; data[0][2] = 0; data[0][3] = 0;
			data[1][0] = 0; data[1][1] = 1; data[1][2] = 0; data[1][3] = 0;
			data[2][0] = 0; data[2][1] = 0;	data[2][2] = 1; data[2][3] = 0;
			data[3][0] = 0; data[3][1] = 0; data[3][2] = 0; data[3][3] = 1;
		}

		void zero() {
			//data = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
			data[0][0] = 0;	data[0][1] = 0; data[0][2] = 0; data[0][3] = 0;
			data[1][0] = 0; data[1][1] = 0; data[1][2] = 0; data[1][3] = 0;
			data[2][0] = 0; data[2][1] = 0;	data[2][2] = 0; data[2][3] = 0;
			data[3][0] = 0; data[3][1] = 0; data[3][2] = 0; data[3][3] = 0;
		}

		//get at
		T at(int x, int y) {
			return data[x][y];
		}

		//TRANSLATION

		void setToTranslation(const vec3<T>& trans){
			data[3][0] = trans.x;
			data[3][1] = trans.y;
			data[3][2] = trans.z;
			data[3][3] = 1;
		}

		void addTranslation(const vec3<T>& trans) {
			data[3][0] += trans.x;
			data[3][1] += trans.y;
			data[3][2] += trans.z;
			data[3][3] = 1;
		}

		vec3<T> getTranslation() {
			return vec3<T>(at(3,0), at(3,1), at(3,2));
		}


		//SCALE

		void setScaleFactor(const T scale) {
			data[0][0] = scale;
			data[1][1] = scale;
			data[2][2] = scale;
		}

		void setScaleFactor(const vec3<T> scale) {
			data[0][0] = scale.x;
			data[1][1] = scale.y;
			data[2][2] = scale.z;
		}

		void addScaleFactor(const T scale) {
			data[0][0] *= scale;
			data[1][1] *= scale;
			data[2][2] *= scale;
		}

		void addScaleFactor(const vec3<T> scale) {
			data[0][0] *= scale.x;
			data[1][1] *= scale.y;
			data[2][2] *= scale.z;
		}

		vec3<T> getScale() {
 			return vec3<T>(data[0][0], data[1][1], data[2][2]);
		}

		//ROTATION 
		//TODO!!!
		
		//MATRIX ADDITION

		mat4<T> operator+(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] + val.data[i][j];
			return out;
		}

		//SCALAR ADDITION
		mat4<T> operator+(const T val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] + val;
			return out;
		}

		//MATRIX SUBTRACTION

		mat4<T> operator-(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] - val.data[i][j];
			return out;
		}

		//SCALAR SUBTRACTION
		mat4<T> operator-(const T val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] - val;
			return out;
		}

		//SCALAR MULTIPLICATION
		mat4<T> operator*(const T val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] * val;
			return out;
		}

		//MATRIX MULTIPLICATION
		mat4<T> operator*(const mat4<T>& val){
			return (mat4<T>(data[0][0] * val.data[0][0] + data[1][0] * val.data[0][1] + data[2][0] * val.data[0][2] + data[3][0] * val.data[0][3],
						    data[0][0] * val.data[1][0] + data[1][0] * val.data[1][1] + data[2][0] * val.data[1][2] + data[3][0] * val.data[1][3],
						    data[0][0] * val.data[2][0] + data[1][0] * val.data[2][1] + data[2][0] * val.data[2][2] + data[3][0] * val.data[2][3],
						    data[0][0] * val.data[3][0] + data[1][0] * val.data[3][1] + data[2][0] * val.data[3][2] + data[3][0] * val.data[3][3],
						    data[0][1] * val.data[0][0] + data[1][1] * val.data[0][1] + data[2][1] * val.data[0][2] + data[3][1] * val.data[0][3],
						    data[0][1] * val.data[1][0] + data[1][1] * val.data[1][1] + data[2][1] * val.data[1][2] + data[3][1] * val.data[1][3],
						    data[0][1] * val.data[2][0] + data[1][1] * val.data[2][1] + data[2][1] * val.data[2][2] + data[3][1] * val.data[2][3],
						    data[0][1] * val.data[3][0] + data[1][1] * val.data[3][1] + data[2][1] * val.data[3][2] + data[3][1] * val.data[3][3],
						    data[0][2] * val.data[0][0] + data[1][2] * val.data[0][1] + data[2][2] * val.data[0][2] + data[3][2] * val.data[0][3],
						    data[0][2] * val.data[1][0] + data[1][2] * val.data[1][1] + data[2][2] * val.data[1][2] + data[3][2] * val.data[1][3],
						    data[0][2] * val.data[2][0] + data[1][2] * val.data[2][1] + data[2][2] * val.data[2][2] + data[3][2] * val.data[2][3],
						    data[0][2] * val.data[3][0] + data[1][2] * val.data[3][1] + data[2][2] * val.data[3][2] + data[3][2] * val.data[3][3],
						    data[0][3] * val.data[0][0] + data[1][3] * val.data[0][1] + data[2][3] * val.data[0][2] + data[3][3] * val.data[0][3],
						    data[0][3] * val.data[1][0] + data[1][3] * val.data[1][1] + data[2][3] * val.data[1][2] + data[3][3] * val.data[1][3],
						    data[0][3] * val.data[2][0] + data[1][3] * val.data[2][1] + data[2][3] * val.data[2][2] + data[3][3] * val.data[2][3],
						    data[0][3] * val.data[3][0] + data[1][3] * val.data[3][1] + data[2][3] * val.data[3][2] + data[3][3] * val.data[3][3]));
		}

		//SCALAR DIVISION
		//SCALAR ADDITION
		mat4<T> operator/(const T val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					out.data[i][j] = data[i][j] /val;
			return out;
		}

		//determinant
		//inverse
		//transpose
	};


}

#endif // !MATRIX44_HEADER