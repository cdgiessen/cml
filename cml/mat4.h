#pragma once

#include <string>


#ifndef MATRIX44_HEADER

namespace cml {

	/* stuff to do.

	#static vars: identity and zero;

	#determinant
	#inverse
	#isIdentity
	#transpose
	#Operator * (multiply matricies)

	#get row, get column
	set row, set column

	setTRS (translation, rotation, and scaling)

	toString

	static functions. 
		Create orthographic projection matrix
		Create perspective projection matrix
		create scale matrix
		create TRS (translation, rotation, and scaling)


	*/

	//matrices are row order, 
	/*
		so data = { x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4 } 
	*/
	template<typename T>
	class mat4 {
	public:
		T data[16];

		//Identity matrix constructor
		mat4() : data{ 1,0,0,0,	0,1,0,0,	0,0,1,0,	0,0,0,1 } {}

		//Copy from array
		mat4(const T val[16]) : data{ val[0], val[1], val[2],  val[3],	val[4],  val[5],  val[6],  val[7] ,
									  val[8], val[9], val[10], val[11],	val[12], val[13], val[14], val[15]  } {}
		//Copy constructor
		mat4(const mat4<T>& val) : data{ val.at(0,0), val.at(0,1),val.at(0,2),val.at(0,3),	 val.at(1,0), val.at(1,1),val.at(1,2),val.at(1,3) ,
			val.at(2,0), val.at(2,1),val.at(2,2),val.at(2,3), val.at(3,0), val.at(3,1),val.at(3,2),val.at(3,3) } {}

		//Constructor from values
		mat4(const T n00, const T n01, const T n02, const T n03, const T n10, const T n11, const T n12, const T n13, 
			 const T n20, const T n21, const T n22, const T n23, const T n30, const T n31, const T n32, const T n33) : data
		{ n00,n01,n02,n03, n10,n11,n12,n13,	 n20,n21,n22,n23,  n30,n31,n32,n33 } {}

		//Resets matrix to identity
		void identity() {
			for (int i = 0; i < 16; i++)
				data[i] = (i % 5) ? 0 : 1;
		}

		//Checks if matrix is identity matrix
		bool isIdentity() {
			for (int i = 0; i < 4; i++)	{
				for (int j = 0; j < 4; j++) {
					if ((i == j && at(i, j) != 1) || (i != j && at(i, j) != 0))
						return false;
				}
			}
			return true;
		}

		//Resets to zero matrix
		void zero() {
			for (int i = 0; i < 16; i++)
				data[i] = 0;
		}

		//get at
		T& at(int x, int y) {
			return data[x*4 + y];
		}

		const T& at(int x, int y) const {
			return data[x * 4 + y];
		}

		//Creates a translation matrix with given vec3
		static mat4<T> createTranslationMatrix(const vec3<T> val) {
			mat4<T> out;
			out.at(0,3) = val.x;
			out.at(1,3) = val.y;
			out.at(2,3) = val.z;
			return out;
		}

		//Creates a scale matrix with given vec3
		static mat4<T> createScaleMatrix(const vec3<T> val) {
			mat4<T> out;
			out.at(0, 0) = val.x;
			out.at(1, 1) = val.y;
			out.at(2, 2) = val.z;
			return out;
		}

		//Creates a rotation matrix with specified values in degrees
		static mat4<T> createRotationMatrix(const T xRot, const T yRot, const T zRot) {
			T xRad = cml::degToRad(xRot);
			T yRad = cml::degToRad(yRot);
			T zRad = cml::degToRad(zRot);

			mat4<T> ma, mb, mc;
			float ac = cos(xRad);
			float as = sin(xRad);
			float bc = cos(yRad);
			float bs = sin(yRad);
			float cc = cos(zRad);
			float cs = sin(zRad);

			ma.at(1, 1) = ac;
			ma.at(2, 1) = as;
			ma.at(1, 2) = -as;
			ma.at(2, 2) = ac;

			mb.at(0, 0) = bc;
			mb.at(2, 0) = -bs;
			mb.at(0, 2) = bs;
			mb.at(2, 2) = bc;

			mc.at(0, 0) = cc;
			mc.at(1, 0) = cs;
			mc.at(0, 1) = -cs;
			mc.at(1, 1) = cc;

			return ma * mb * mc;

		}

		vec4<T> getRow(const int i) {
			return vec4<T>(at(0, i), at(1, i), at(2, i), at(3, i));
		}

		vec4<T> getCol(const int i) {
			return vec4<T>(at(i, 0), at(i, 1), at(i, 2), at(i, 3));
		}
			
		//TRANSLATION

		void setToTranslation(const vec3<T>& trans){
			at(0,3) = trans.x;
			at(1,3) = trans.y;
			at(2,3) = trans.z;
			at(3,3) = 1;
		}

		void addTranslation(const vec3<T>& trans) {
			at(0,3) += trans.x;
			at(1,3) += trans.y;
			at(2,3) += trans.z;
			at(3,3) = 1;
		}

		vec3<T> getTranslation() {
			return vec3<T>(at(3,0), at(3,1), at(3,2));
		}


		//SCALE

		void setScaleFactor(const T scale) {
			at(0,0) = scale;
			at(1,1) = scale;
			at(2,2) = scale;
		}

		void setScaleFactor(const vec3<T> scale) {
			at(0, 0) = scale.x;
			at(1, 1) = scale.y;
			at(2, 2) = scale.z;
		}

		void addScaleFactor(const T scale) {
			at(0, 0) *= scale;
			at(1, 1) *= scale;
			at(2, 2) *= scale;
		}

		void addScaleFactor(const vec3<T> scale) {
			at(0, 0) *= scale.x;
			at(1, 1) *= scale.y;
			at(2, 2) *= scale.z;
		}

		vec3<T> getScale() {
 			return vec3<T>(at(0,0), at(1,1), at(2,2));
		}

		//ROTATION 
		//TODO!!!
		
		//MATRIX ADDITION

		mat4<T> operator+(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] + val.data[i];
			return out;
		}

		//SCALAR ADDITION
		mat4<T> operator+(const T val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] + val;
			return out;
		}

		//MATRIX SUBTRACTION

		mat4<T> operator-(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] - val.data[i];
			return out;
		}

		//SCALAR SUBTRACTION
		mat4<T> operator-(const T val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] - val;
			return out;
		}

		//SCALAR MULTIPLICATION
		mat4<T> operator*(const T val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] * val;
			return out;
		}

		//MATRIX MULTIPLICATION
		mat4<T> operator*(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++)	{
				for (int j = 0; j < 4; j++)	{
					T n = 0;
					for (int k = 0; k < 4; k++)
					{
						n += val.at(i, k) * at(k, j);
					}
					out.at(i, j) = n;
				}
			}
			return out;
		}

		//SCALAR DIVISION
		//SCALAR ADDITION
		mat4<T> operator/(const T val) {
			mat4<T> out;
			for (int i = 0; i < 16; i++)
				out.data[i] = data[i] /val;
			return out;
		}

		//TRANSPOSE
		mat4<T> transpose()
		{
			mat4<T> out;
			for (int i = 0; i < 4; i++)	{
				for (int j = 0; j < 4; j++) {
					out.at(i, j) = at(j, i);
				}
			}
			return out;
		}

		T det() {
			return  at(0, 0)*at(1, 1)*at(2, 2)*at(3, 3) + at(0, 0)*at(1, 2)*at(2, 3)*at(3, 1) + at(0, 0)*at(1, 3)*at(2, 1)*at(3, 2) +

				at(0, 1)*at(1, 0)*at(2, 3)*at(3, 2) + at(0, 1)*at(1, 2)*at(2, 0)*at(3, 3) + at(0, 1)*at(1, 3)*at(2, 2)*at(3, 0) +

				at(0, 2)*at(1, 0)*at(2, 1)*at(3, 3) + at(0, 2)*at(1, 1)*at(2, 3)*at(3, 0) + at(0, 2)*at(1, 3)*at(2, 0)*at(3, 1) +

				at(0, 3)*at(1, 0)*at(2, 2)*at(3, 1) + at(0, 3)*at(1, 1)*at(2, 0)*at(3, 2) + at(0, 3)*at(1, 2)*at(2, 1)*at(3, 0) -

				at(0, 0)*at(1, 1)*at(2, 3)*at(3, 2) - at(0, 0)*at(1, 2)*at(2, 1)*at(3, 3) - at(0, 0)*at(1, 3)*at(2, 2)*at(3, 1) -

				at(0, 1)*at(1, 0)*at(2, 2)*at(3, 3) - at(0, 1)*at(1, 2)*at(2, 3)*at(3, 0) - at(0, 1)*at(1, 3)*at(2, 0)*at(3, 2) -

				at(0, 2)*at(1, 0)*at(2, 3)*at(3, 1) - at(0, 2)*at(1, 1)*at(2, 0)*at(3, 3) - at(0, 2)*at(1, 3)*at(2, 1)*at(3, 0) -

				at(0, 3)*at(1, 0)*at(2, 1)*at(3, 2) - at(0, 3)*at(1, 1)*at(2, 2)*at(3, 0) - at(0, 3)*at(1, 2)*at(2, 0)*at(3, 1) ;
		}

		//INVERSE
		mat4<T> inverse()
		{
			mat4<T> out;

			out.at(0, 0) = at(2, 1) * at(3, 2) * at(1, 3) - at(3, 1) * at(2, 2) * at(1, 3) + at(3, 1) * at(1, 2) * at(2, 3)
				- at(1, 1) * at(3, 2) * at(2, 3) - at(2, 1) * at(1, 2) * at(3, 3) + at(1, 1) * at(2, 2) * at(3, 3);

			out.at(1, 0) = at(3, 0) * at(2, 2) * at(1, 3) - at(2, 0) * at(3, 2) * at(1, 3) - at(3, 0) * at(1, 2) * at(2, 3)
				+ at(1, 0) * at(3, 2) * at(2, 3) + at(2, 0) * at(1, 2) * at(3, 3) - at(1, 0) * at(2, 2) * at(3, 3);

			out.at(2, 0) = at(2, 0) * at(3, 1) * at(1, 3) - at(3, 0) * at(2, 1) * at(1, 3) + at(3, 0) * at(1, 1) * at(2, 3)
				- at(1, 0) * at(3, 1) * at(2, 3) - at(2, 0) * at(1, 1) * at(3, 3) + at(1, 0) * at(2, 1) * at(3, 3);

			out.at(3, 0) = at(3, 0) * at(2, 1) * at(1, 2) - at(2, 0) * at(3, 1) * at(1, 2) - at(3, 0) * at(1, 1) * at(2, 2)
				+ at(1, 0) * at(3, 1) * at(2, 2) + at(2, 0) * at(1, 1) * at(3, 2) - at(1, 0) * at(2, 1) * at(3, 2);

			out.at(0, 1) = at(3, 1) * at(2, 2) * at(0, 3) - at(2, 1) * at(3, 2) * at(0, 3) - at(3, 1) * at(0, 2) * at(2, 3)
				+ at(0, 1) * at(3, 2) * at(2, 3) + at(2, 1) * at(0, 2) * at(3, 3) - at(0, 1) * at(2, 2) * at(3, 3);

			out.at(1, 1) = at(2, 0) * at(3, 2) * at(0, 3) - at(3, 0) * at(2, 2) * at(0, 3) + at(3, 0) * at(0, 2) * at(2, 3)
				- at(0, 0) * at(3, 2) * at(2, 3) - at(2, 0) * at(0, 2) * at(3, 3) + at(0, 0) * at(2, 2) * at(3, 3);

			out.at(2, 1) = at(3, 0) * at(2, 1) * at(0, 3) - at(2, 0) * at(3, 1) * at(0, 3) - at(3, 0) * at(0, 1) * at(2, 3)
				+ at(0, 0) * at(3, 1) * at(2, 3) + at(2, 0) * at(0, 1) * at(3, 3) - at(0, 0) * at(2, 1) * at(3, 3);

			out.at(3, 1) = at(2, 0) * at(3, 1) * at(0, 2) - at(3, 0) * at(2, 1) * at(0, 2) + at(3, 0) * at(0, 1) * at(2, 2)
				- at(0, 0) * at(3, 1) * at(2, 2) - at(2, 0) * at(0, 1) * at(3, 2) + at(0, 0) * at(2, 1) * at(3, 2);

			out.at(0, 2) = at(1, 1) * at(3, 2) * at(0, 3) - at(3, 1) * at(1, 2) * at(0, 3) + at(3, 1) * at(0, 2) * at(1, 3)
				- at(0, 1) * at(3, 2) * at(1, 3) - at(1, 1) * at(0, 2) * at(3, 3) + at(0, 1) * at(1, 2) * at(3, 3);

			out.at(1, 2) = at(3, 0) * at(1, 2) * at(0, 3) - at(1, 0) * at(3, 2) * at(0, 3) - at(3, 0) * at(0, 2) * at(1, 3)
				+ at(0, 0) * at(3, 2) * at(1, 3) + at(1, 0) * at(0, 2) * at(3, 3) - at(0, 0) * at(1, 2) * at(3, 3);

			out.at(2, 2) = at(1, 0) * at(3, 1) * at(0, 3) - at(3, 0) * at(1, 1) * at(0, 3) + at(3, 0) * at(0, 1) * at(1, 3)
				- at(0, 0) * at(3, 1) * at(1, 3) - at(1, 0) * at(0, 1) * at(3, 3) + at(0, 0) * at(1, 1) * at(3, 3);

			out.at(3, 2) = at(3, 0) * at(1, 1) * at(0, 2) - at(1, 0) * at(3, 1) * at(0, 2) - at(3, 0) * at(0, 1) * at(1, 2)
				+ at(0, 0) * at(3, 1) * at(1, 2) + at(1, 0) * at(0, 1) * at(3, 2) - at(0, 0) * at(1, 1) * at(3, 2);

			out.at(0, 3) = at(2, 1) * at(1, 2) * at(0, 3) - at(1, 1) * at(2, 2) * at(0, 3) - at(2, 1) * at(0, 2) * at(1, 3)
				+ at(0, 1) * at(2, 2) * at(1, 3) + at(1, 1) * at(0, 2) * at(2, 3) - at(0, 1) * at(1, 2) * at(2, 3);

			out.at(1, 3) = at(1, 0) * at(2, 2) * at(0, 3) - at(2, 0) * at(1, 2) * at(0, 3) + at(2, 0) * at(0, 2) * at(1, 3)
				- at(0, 0) * at(2, 2) * at(1, 3) - at(1, 0) * at(0, 2) * at(2, 3) + at(0, 0) * at(1, 2) * at(2, 3);

			out.at(2, 3) = at(2, 0) * at(1, 1) * at(0, 3) - at(1, 0) * at(2, 1) * at(0, 3) - at(2, 0) * at(0, 1) * at(1, 3)
				+ at(0, 0) * at(2, 1) * at(1, 3) + at(1, 0) * at(0, 1) * at(2, 3) - at(0, 0) * at(1, 1) * at(2, 3);

			out.at(3, 3) = at(1, 0) * at(2, 1) * at(0, 2) - at(2, 0) * at(1, 1) * at(0, 2) + at(2, 0) * at(0, 1) * at(1, 2)
				- at(0, 0) * at(2, 1) * at(1, 2) - at(1, 0) * at(0, 1) * at(2, 2) + at(0, 0) * at(1, 1) * at(2, 2);

			return out / det();
		}
	};


}

#endif // !MATRIX44_HEADER
