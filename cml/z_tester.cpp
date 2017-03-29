
#include <iostream>
#include <string>
#include <cstdio>
#include "cml.h"

void main() {

	cml::vec3f v1(2.0f, 3.0f, 2.5f);	
	std::cout << "v1 = 2.0f, 3.0f, 2.5f  == "<< v1 << std::endl;

	cml::vec3f v2(1.0f, 1.0f, 1.0f);
	std::cout << "v2 = 1.0f, 1.0f, 1.0f  == " << v2 << std::endl;

	v2 = v1;
	std::cout << "v2 = v1 "<< v2 << std::endl;

	cml::vec3f v3 = v1 + v2;
	std::cout << "v3 = v1 + v2  == " << v3 << std::endl;

	v3 = cml::VEC3_ZERO;
	std::cout << "reset v3 to ZERO v3 = " << v3 << std::endl;


	cml::vec3f v4 = cml::vec3<float>::cross(cml::VEC3_RIGHT, cml::VEC3_UP);
	std::cout << "v4 = v3 * v2 ==" << v4 << std::endl;

	std::cout << std::endl;

	cml::mat4<float> matA;
	matA.setScaleFactor(5);
	matA.setToTranslation(cml::vec3<float>(1, 2, 3));
	std::cout << "matA" << matA <<std::endl;

	cml::mat4<float> matB;
	matB.addTranslation(cml::vec3<float>(0.5f, 0.1f, 1.5f));
	std::cout << "matB" << matA + matB << std::endl;

	cml::vec3f vec3val(1,2,3);
	std::cout << "matA*vec3val" << matA * vec3val << std::endl;
	std::cout << "vec3val * matA" << vec3val * matA << std::endl;

	matA = cml::mat4f(4, 0, 3, 2, 5, 3, 5, 4, 1, 6, 0, 6, 8, 1, 9, 1);
	matB = cml::mat4f(1, 0, 3, 2, 5, 3, 5, 0, 1, 6, 7, 6, 0, 1, 2, 1);
	std::cout << "Following should equal [[23,40,89,15],[20,39,66,16],[21,30,87,14],[22,52,74,17]] " << std::endl;
	std::cout << "matA * matB = " << matA*matB << std::endl; 

	cml::mat4f matC(1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1);
	cml::mat4f matD(2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1);
	cml::mat4<int> matDet(3, 2, -1, 4, 2, 1, 5, 7, 0, 5, 2, -6, -1, 2, 1, 0); //determinate should be -418

	matD = matC - matD;

	std::cout << "matC" << matC << std::endl;
															
	std::cout << "matD" << matD << std::endl;						
													
	std::cout << "matDet det = " << matDet.det() << std::endl;

	std::cout << "matC * v1 = " << matC*v1 << std::endl;

	std::cout << "matA get col 2  == " << matA.getCol(2) << std::endl;

	std::cout << "matA get row 3  == " << matA.getRow(3) << std::endl;

	//cml::mat4<float> matIden;
	//std::cout << "is matrix an identity matrix == " << matIden.isIdentity() << std::endl;
	//std::cout << "matIden" << std::endl;

	//std::cout << std::endl;
	//std::cout << "Constant vec3 ZERO " << std::endl;
	//std::cout << "Constant vec3 ONE " << std::endl;
	//std::cout << "Constant vec3 RIGHT " << std::endl;
	//std::cout << "Constant vec3 LEFT " << std::endl;
	//std::cout << "Constant vec3 UP " << std::endl;
	//std::cout << "Constant vec3 DOWN "<< std::endl;
	//std::cout << "Constant vec3 FOWARD " << std::endl;
	//std::cout << "Constant vec3 BACK "  << std::endl;

	std::cout << std::endl;
	std::cout << "Quaternion identity" << cml::QUAT_IDENTITY << std::endl;

	cml::quatf quatA = cml::quatf::fromEulerAngles(30,0,180);
	std::cout << "QuatA = Rotation 30 around x, 0 around y, 180 around z" << quatA << std::endl;
	std::cout << "Mag of quatA " << quatA.mag() << std::endl;

	cml::vec3f vecToRotate(1, 0, 0);

	cml::vec3f vec1 = cml::VEC3_FORWARD;

	std::cout << "vector " << vec1 << " rotated around " << cml::QUAT_X_90 << " is " << cml::quatf::rotate(vec1, cml::QUAT_X_90) << std::endl;

	std::cout << "Press any key to continue..." << std::endl;
	std::getchar();	
}