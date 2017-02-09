#pragma once

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

	template<typedef T> 
	class mat4 {
	public:
		T data[4][4];

		//Identity matrix constructor
		mat4() {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i == j)
						data[i][j] = 1;
					else
						data[i][j] = 0;
				}
			}
		}

		//Resets matrix to identity
		void identity() {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i == j)
						data[i][j] = 1;
					else
						data[i][j] = 0;
				}
			}
		}

	};


}

#endif // !MATRIX44_HEADER
