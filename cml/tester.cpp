
#include <iostream>
#include <string>
#include <cstdio>
#include "cml.h"

int main() {

	cml::vec3f v1(2.0f, 3.0f, 2.5f);	
	std::cout << "v1 = 2.0f, 3.0f, 2.5f  == "<< v1 << std::endl;

	cml::vec3f v2(1.0f, 1.0f, 1.0f);
	std::cout << "v2 = 1.0f, 1.0f, 1.0f  == " << v2 << std::endl;

	v2 = v1;
	std::cout << "v2 = v1 "<< v2 << std::endl;

	cml::vec3f v3 = v1 + v2;
	std::cout << "v3 = v1 + v2  == " << v3 << std::endl;

	v3 = cml::ZERO;
	std::cout << "reset v3 to ZERO v3 = " << v3 << std::endl;


	cml::vec3f v4 = cml::vec3<float>::cross(cml::RIGHT, cml::UP);
	std::cout << "v4 = v3 * v2 ==" << v4 << std::endl;

	cml::mat4<float> matA;
	matA.setScaleFactor(5);
	matA.setToTranslation(cml::vec3<float>(1, 2, 3));

	cml::mat4<float> matB;
	matB.addTranslation(cml::vec3<float>(0.5f, 0.1f, 1.5f));
	matB = matA + matB;

	cml::mat4<float> matC(1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1);
	cml::mat4<float> matD(2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1);
	cml::mat4<int> matDet(3, 2, -1, 4, 2, 1, 5, 7, 0, 5, 2, -6, -1, 2, 1, 0); //determinate should be -418

	matD = matC - matD;

	std::cout << "matA" << matA <<std::endl;
															
	std::cout << "matB" << matB << std::endl;
															
	std::cout << "matC" << matC << std::endl;
															
	std::cout << "matD" << matD << std::endl;						
													
	std::cout << "matDet det = " << matDet.det() << std::endl;


	std::cout << "matA get col 2  == " << matA.getCol(2) << std::endl;

	std::cout << "matA get row 3  == " << matA.getRow(3) << std::endl;

	//cml::mat4<float> matIden;
	//std::cout << "is matrix an identity matrix == " << matIden.isIdentity() << std::endl;
	//std::cout << "matIden" << std::endl;
	//std::cout << matIden.at(0, 0) << ", " << matIden.at(1, 0) << ", " << matIden.at(2, 0) << ", " << matIden.at(3, 0) << std::endl;
	//std::cout << matIden.at(0, 1) << ", " << matIden.at(1, 1) << ", " << matIden.at(2, 1) << ", " << matIden.at(3, 1) << std::endl;
	//std::cout << matIden.at(0, 2) << ", " << matIden.at(1, 2) << ", " << matIden.at(2, 2) << ", " << matIden.at(3, 2) << std::endl;
	//std::cout << matIden.at(0, 3) << ", " << matIden.at(1, 3) << ", " << matIden.at(2, 3) << ", " << matIden.at(3, 3) << std::endl;


	//std::cout << std::endl;
	//std::cout << "Constant vec3 ZERO " << cml::ZERO.x << " " << cml::ZERO.y << " " << cml::ZERO.z << std::endl;
	//std::cout << "Constant vec3 ONE " << cml::ONE.x << " " << cml::ONE.y << " " << cml::ONE.z << std::endl;
	//std::cout << "Constant vec3 RIGHT " << cml::RIGHT.x << " " << cml::RIGHT.y << " " << cml::RIGHT.z << std::endl;
	//std::cout << "Constant vec3 LEFT " << cml::LEFT.x << " " << cml::LEFT.y << " " << cml::LEFT.z << std::endl;
	//std::cout << "Constant vec3 UP " << cml::UP.x << " " << cml::UP.y << " " << cml::UP.z << std::endl;
	//std::cout << "Constant vec3 DOWN " << cml::DOWN.x << " " << cml::DOWN.y << " " << cml::DOWN.z << std::endl;
	//std::cout << "Constant vec3 FOWARD " << cml::FORWARD.x << " " << cml::FORWARD.y << " " << cml::FORWARD.z << std::endl;
	//std::cout << "Constant vec3 BACK " << cml::BACK.x << " " << cml::BACK.y << " " << cml::BACK.z << std::endl;
	

	std::cout << "Press any key to continue..." << std::endl;
	std::getchar();
	return 0;
}