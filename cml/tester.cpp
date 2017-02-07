
#include <iostream>
#include <string>
#include <cstdio>
#include "cml.h"
#include "cml/vec3.h"

void notmain() {

	cml::vec3f v1(2.0f, 3.0f, 2.5f);	
	std::cout << "v1 = 2.0f, 3.0f, 2.5f  == " << v1.x << " " << v1.y << " " << v1.z << std::endl;

	cml::vec3f v2(1.0f, 1.0f, 1.0f);
	std::cout << "v2 = 1.0f, 1.0f, 1.0f  == " << v2.x << " " << v2.y << " " << v2.z << std::endl;

	v2 = v1;
	std::cout << "v2 = v1 "<< v2.x << " " << v2.y << " "<< v2.z << std::endl;

	cml::vec3f v3 = v1 + v2;
	std::cout << "v3 = v1 + v2  == " << v3.x << " " << v3.y << " " << v3.z << std::endl;



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

}