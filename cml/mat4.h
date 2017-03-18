#pragma once

#include <string>
#include <sstream>

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
		T data[16]; //Stored in column major order, because of OPENGL

					//Identity matrix constructor
		mat4() : data{ 1,0,0,0,	0,1,0,0,	0,0,1,0,	0,0,0,1 } {}

		//Copy from array
		mat4(const T val[16]) : data{ val[0], val[1], val[2],  val[3],	val[4],  val[5],  val[6],  val[7] ,
			val[8], val[9], val[10], val[11],	val[12], val[13], val[14], val[15] } {}
		//Copy constructor
		mat4(const mat4<T>& val) : data{ val.at(0,0), val.at(1,0), val.at(2,0), val.at(3, 0),	 val.at(0, 1), val.at(1,1),val.at(2,1),val.at(3,1) ,
			val.at(0,2), val.at(1,2),val.at(2,2),val.at(3,2), val.at(0,3), val.at(1,3),val.at(2,3),val.at(3,3) } {}

		//Constructor from values
		mat4(const T n00, const T n10, const T n20, const T n30, const T n01, const T n11, const T n21, const T n31,
			const T n02, const T n12, const T n22, const T n32, const T n03, const T n13, const T n23, const T n33) : data
		{ n00,n10,n20,n30,  n01,n11,n21,n31,	 n02,n12,n22,n32,  n03,n13,n23,n33 } {}

		//returns constant address to the data
		static T const * value_ptr(mat4<T> const & mat) {
			return &(mat.data[0]);
		}

		//Resets matrix to identity
		void identity() {
			for (int i = 0; i < 16; i++)
				data[i] = (i % 5) ? 0 : 1;
		}

		//Checks if matrix is identity matrix
		bool isIdentity() {
			for (int i = 0; i < 4; i++) {
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
			return data[x * 4 + y];
		}

		const T& at(int x, int y) const {
			return data[x * 4 + y];
		}

		//Creates a translation matrix with given vec3
		static mat4<T> createTranslationMatrix(const vec3<T> val) {
			mat4<T> out;
			out.at(3, 0) = val.x;
			out.at(3, 1) = val.y;
			out.at(3, 2) = val.z;
			return out;
		}

		//Creates a translation matrix with given vec3
		static mat4<T> createTranslationMatrix(const T x, const T y, const T z) {
			mat4<T> out;
			out.at(3, 0) = x;
			out.at(3, 1) = y;
			out.at(3, 2) = z;
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
			double ac = cos(xRad);
			double as = sin(xRad);
			double bc = cos(yRad);
			double bs = sin(yRad);
			double cc = cos(zRad);
			double cs = sin(zRad);

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

		vec4<T> getCol(const int i) {
			return vec4<T>(at(0, i), at(1, i), at(2, i), at(3, i));
		}

		vec4<T> getRow(const int i) {
			return vec4<T>(at(i, 0), at(i, 1), at(i, 2), at(i, 3));
		}

		//TRANSLATION

		void setToTranslation(const vec3<T>& trans) {
			at(3, 0) = trans.x;
			at(3, 1) = trans.y;
			at(3, 2) = trans.z;
			at(3, 3) = 1;
		}

		void addTranslation(const vec3<T>& trans) {
			at(3, 0) += trans.x;
			at(3, 1) += trans.y;
			at(3, 2) += trans.z;
			at(3, 3) = 1;
		}

		vec3<T> getTranslation() {
			return vec3<T>(at(3, 0), at(3, 1), at(3, 2));
		}


		//SCALE

		void setScaleFactor(const T scale) {
			at(0, 0) = scale;
			at(1, 1) = scale;
			at(2, 2) = scale;
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
			return vec3<T>(at(0, 0), at(1, 1), at(2, 2));
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

		//VECTOR MULTIPLICATION
		vec3<T> operator*(const vec3<T>& val) {
			return vec3<T>(data[0] * val.x + data[4] * val.y + data[8] * val.z,
				data[1] * val.x + data[5] * val.y + data[9] * val.z,
				data[2] * val.x + data[6] * val.y + data[10] * val.z);
		}

		//vec4 multiplication
		vec4<T> operator*(const vec4<T>& val) {
			return vec4<T>(data[0] * val.x + data[4] * val.y + data[8] * val.z + data[12] * val.w,
				data[1] * val.x + data[5] * val.y + data[9] * val.z + data[13] * val.w,
				data[2] * val.x + data[6] * val.y + data[10] * val.z + data[14] * val.w,
				data[3] * val.x + data[7] * val.y + data[11] * val.z + data[15] * val.w);
		}

		//MATRIX MULTIPLICATION
		mat4<T> operator*(const mat4<T>& val) {
			mat4<T> out;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
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
				out.data[i] = data[i] / val;
			return out;
		}

		//EQUALITY CHECK
		bool operator==(const mat4<T>& val) const {
			for (int i = 0; i < 16; i++)
			{
				if (!cml::cmpf(data[i], val.data[i]))
					return false;
			}
			return true;
		}

		bool operator!=(const mat4<T>& val) const {
			return !(*this == val);
		}

		//TRANSPOSE
		mat4<T> transpose()
		{
			mat4<T> out;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					out.at(i, j) = at(j, i);
				}
			}
			return out;
		}

		T det() {
			return
				at(0, 0)*at(1, 1)*at(2, 2)*at(3, 3) + at(0, 0)*at(2, 1)*at(3, 2)*at(1, 3) + at(0, 0)*at(3, 1)*at(1, 2)*at(2, 3) +

				at(1, 0)*at(0, 1)*at(3, 2)*at(2, 3) + at(1, 0)*at(2, 1)*at(0, 2)*at(3, 3) + at(1, 0)*at(3, 1)*at(2, 2)*at(0, 3) +

				at(2, 0)*at(0, 1)*at(1, 2)*at(3, 3) + at(2, 0)*at(1, 1)*at(3, 2)*at(0, 3) + at(2, 0)*at(3, 1)*at(0, 2)*at(1, 3) +

				at(3, 0)*at(0, 1)*at(2, 2)*at(1, 3) + at(3, 0)*at(1, 1)*at(0, 2)*at(2, 3) + at(3, 0)*at(2, 1)*at(1, 2)*at(0, 3) -

				at(0, 0)*at(1, 1)*at(3, 2)*at(2, 3) - at(0, 0)*at(2, 1)*at(1, 2)*at(3, 3) - at(0, 0)*at(3, 1)*at(2, 2)*at(1, 3) -

				at(1, 0)*at(0, 1)*at(2, 2)*at(3, 3) - at(1, 0)*at(2, 1)*at(3, 2)*at(0, 3) - at(1, 0)*at(3, 1)*at(0, 2)*at(2, 3) -

				at(2, 0)*at(0, 1)*at(3, 2)*at(1, 3) - at(2, 0)*at(1, 1)*at(0, 2)*at(3, 3) - at(2, 0)*at(3, 1)*at(1, 2)*at(0, 3) -

				at(3, 0)*at(0, 1)*at(1, 2)*at(2, 3) - at(3, 0)*at(1, 1)*at(2, 2)*at(0, 3) - at(3, 0)*at(2, 1)*at(0, 2)*at(1, 3);
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

		static mat4<T> createLookAt(const vec3<T>& eyePos, const vec3<T>& centerPos, vec3<T>& upDir)
		{
			mat4<T> m;
			vec3<T> x, y, z;
			z = eyePos - centerPos;
			z.norm();
			y = upDir;
			x = vec3<T>::cross(y, z);
			y = vec3<T>::cross(z, x);

			x.norm();
			y.norm();

			m.at(0, 0) = x.x;
			m.at(0, 1) = x.y;
			m.at(0, 2) = x.z;
			m.at(0, 3) = -vec3<T>::dot(x, eyePos);
			m.at(1, 0) = y.x;
			m.at(1, 1) = y.y;
			m.at(1, 2) = y.z;
			m.at(1, 3) = -vec3<T>::dot(y, eyePos);
			m.at(2, 0) = z.x;
			m.at(2, 1) = z.y;
			m.at(2, 2) = z.z;
			m.at(2, 3) = -vec3<T>::dot(z, eyePos);

			return m;
		}

		static mat4<T> createFrustum(T left, T right, T bottom, T top, T zNear, T zFar)
		{
			/*
			*
			2 zNear
			------------       0              A              0
			right - left

			2 zNear
			0         ------------        B              0
			top - bottom

			0              0              C              D

			0              0              -1             0

			A = (right + left) / (right - left)

			B = (top + bottom) / (top - bottom)

			C = - (zFar + zNear) / (zFar - zNear)

			D = - (2 zFar zNear) / (zFar - zNear)
			*
			*/
			mat4<T> ret;

			const T invWidth = 1.0 / (right - left);
			const T invHeight = 1.0 / (top - bottom);
			const T invDepth = 1.0 / (zFar - zNear);

			const T twoZNear = 2 * zNear;

			ret.at(0, 0) = twoZNear * invWidth;
			ret.at(1, 1) = twoZNear * invHeight;

			ret.at(2, 0) = (right + left) * invWidth;
			ret.at(2, 1) = (top + bottom) * invHeight;
			ret.at(2, 2) = -(zFar + zNear) * invDepth;
			ret.at(2, 3) = -1;

			ret.at(3, 2) = -twoZNear * zFar * invDepth;

			return ret;
		}

		static mat4<T> createPerspective(T fovy, T aspect, T zNear, T zFar)
		{
			//assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

			T const tanHalfFovy = tan(fovy / static_cast<T>(2));
			mat4<T> out;
			out.at(0, 0) = static_cast<T>(1) / (tanHalfFovy * aspect);
			out.at(1, 1) = static_cast<T>(1) / (tanHalfFovy);
			out.at(3, 2) = -(static_cast<T>(1));

			out.at(2, 2) = -(zFar + zNear) / (zFar - zNear);
			out.at(2, 3) = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
			//out.at(3, 3) = 0;
			return out;
		}

		static mat4<T> createOrtho(T left, T right, T bottom, T top, T near, T far) {
			mat4<T> out;

			out.at(0, 0) = 2 / (right - left);
			out.at(1, 1) = 2 / (top - bottom);
			out.at(2, 2) = -2 / (far - near);

			out.at(3, 0) = -(left + right) / (right - left);
			out.at(3, 1) = -(top + bottom) / (top - bottom);
			out.at(3, 2) = -(far + near) / (far - near);

			return out;
		}

		//put to output
		friend std::ostream& operator<<(std::ostream &strm, const mat4<T> &m) {
			return strm << std::endl << "[[" << m.data[0] << ", " << m.data[4] << ", " << m.data[8] << ", " << m.data[12] << "],	" << std::endl
				<< "[" << m.data[1] << ", " << m.data[5] << ", " << m.data[9] << ", " << m.data[13] << "],	" << std::endl
				<< "[" << m.data[2] << ", " << m.data[6] << ", " << m.data[10] << ", " << m.data[14] << "],	" << std::endl
				<< "[" << m.data[3] << ", " << m.data[7] << ", " << m.data[11] << ", " << m.data[15] << "]]" << std::endl;
		}

		//To string
		std::string toString() const {
			std::ostringstream stream;
			stream << *this;
			return stream.str();
		}
	};


	typedef mat4<float> mat4f;
	typedef mat4<double> mat4d;


}

#endif // !MATRIX44_HEADER
