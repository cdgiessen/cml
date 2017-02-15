
#include <iostream>
#include <string>
#include <cstdio>
#include "cml.h"

int main() {

	cml::vec3f v1(2.0f, 3.0f, 2.5f);	
	std::cout << "v1 = 2.0f, 3.0f, 2.5f  == " << v1.x << " " << v1.y << " " << v1.z << std::endl;

	cml::vec3f v2(1.0f, 1.0f, 1.0f);
	std::cout << "v2 = 1.0f, 1.0f, 1.0f  == " << v2.x << " " << v2.y << " " << v2.z << std::endl;

	v2 = v1;
	std::cout << "v2 = v1 "<< v2.x << " " << v2.y << " "<< v2.z << std::endl;

	cml::vec3f v3 = v1 + v2;
	std::cout << "v3 = v1 + v2  == " << v3.x << " " << v3.y << " " << v3.z << std::endl;

	v3 = cml::ZERO;
	std::cout << "reset v3 to ZERO v3 = " << v3.x << " " << v3.y << " " << v3.z << std::endl;


	cml::vec3f v4 = cml::vec3<float>::cross(cml::RIGHT, cml::UP);
	std::cout << "v4 = v3 * v2 ==" << v4.x << " " << v4.y << " " << v4.z << std::endl;

	cml::mat4<float> matA;
	matA.setScaleFactor(5);
	matA.setToTranslation(cml::vec3<float>(1, 2, 3));

	cml::mat4<float> matB;
	matB.addTranslation(cml::vec3<float>(0.5f, 0.1f, 1.5f));
	matB = matA + matB;

	cml::mat4<float> matC(1,1,2,2,2,2,1,1,1,1,2,2,2,2,1,1);
	cml::mat4<float> matD(2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1);
	matD = matD*matC;

	std::cout << "matA" << std::endl;

	std::cout << matA.at(0, 0) << " " << matA.at(1, 0) << " " << matA.at(2, 0) << " " << matA.at(3, 0) << std::endl;
	std::cout << matA.at(0, 1) << " " << matA.at(1, 1) << " " << matA.at(2, 1) << " " << matA.at(3, 1) << std::endl;
	std::cout << matA.at(0, 2) << " " << matA.at(1, 2) << " " << matA.at(2, 2) << " " << matA.at(3, 2) << std::endl;
	std::cout << matA.at(0, 3) << " " << matA.at(1, 3) << " " << matA.at(2, 3) << " " << matA.at(3, 3) << std::endl;

	std::cout << "matB" << std::endl;

	std::cout << matB.at(0, 0) << " " << matB.at(1, 0) << " " << matB.at(2, 0) << " " << matB.at(3, 0) << std::endl;
	std::cout << matB.at(0, 1) << " " << matB.at(1, 1) << " " << matB.at(2, 1) << " " << matB.at(3, 1) << std::endl;
	std::cout << matB.at(0, 2) << " " << matB.at(1, 2) << " " << matB.at(2, 2) << " " << matB.at(3, 2) << std::endl;
	std::cout << matB.at(0, 3) << " " << matB.at(1, 3) << " " << matB.at(2, 3) << " " << matB.at(3, 3) << std::endl;

	std::cout << "matC" << std::endl;

	std::cout << matC.at(0, 0) << " " << matC.at(1, 0) << " " << matC.at(2, 0) << " " << matC.at(3, 0) << std::endl;
	std::cout << matC.at(0, 1) << " " << matC.at(1, 1) << " " << matC.at(2, 1) << " " << matC.at(3, 1) << std::endl;
	std::cout << matC.at(0, 2) << " " << matC.at(1, 2) << " " << matC.at(2, 2) << " " << matC.at(3, 2) << std::endl;
	std::cout << matC.at(0, 3) << " " << matC.at(1, 3) << " " << matC.at(2, 3) << " " << matC.at(3, 3) << std::endl;

	std::cout << "matD" << std::endl;

	std::cout << matD.at(0, 0) << " " << matD.at(1, 0) << " " << matD.at(2, 0) << " " << matD.at(3, 0) << std::endl;
	std::cout << matD.at(0, 1) << " " << matD.at(1, 1) << " " << matD.at(2, 1) << " " << matD.at(3, 1) << std::endl;
	std::cout << matD.at(0, 2) << " " << matD.at(1, 2) << " " << matD.at(2, 2) << " " << matD.at(3, 2) << std::endl;
	std::cout << matD.at(0, 3) << " " << matD.at(1, 3) << " " << matD.at(2, 3) << " " << matD.at(3, 3) << std::endl;

	std::cout << "Constant vec3 ZERO " << cml::ZERO.x << " " << cml::ZERO.y << " " << cml::ZERO.z << std::endl;
	std::cout << "Constant vec3 ONE " << cml::ONE.x << " " << cml::ONE.y << " " << cml::ONE.z << std::endl;
	std::cout << "Constant vec3 RIGHT " << cml::RIGHT.x << " " << cml::RIGHT.y << " " << cml::RIGHT.z << std::endl;
	std::cout << "Constant vec3 LEFT " << cml::LEFT.x << " " << cml::LEFT.y << " " << cml::LEFT.z << std::endl;
	std::cout << "Constant vec3 UP " << cml::UP.x << " " << cml::UP.y << " " << cml::UP.z << std::endl;
	std::cout << "Constant vec3 DOWN " << cml::DOWN.x << " " << cml::DOWN.y << " " << cml::DOWN.z << std::endl;
	std::cout << "Constant vec3 FOWARD " << cml::FORWARD.x << " " << cml::FORWARD.y << " " << cml::FORWARD.z << std::endl;
	std::cout << "Constant vec3 BACK " << cml::BACK.x << " " << cml::BACK.y << " " << cml::BACK.z << std::endl;
	

	std::cout << "Press any key to continue..." << std::endl;
	std::getchar();
	return 0;
}