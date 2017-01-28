
#include <iostream>
#include <string>
#include "cml.h"

void main() {

	cml::vec2<float> v1(2.0f, 3.0f);


	std::cout << "First vector" << std::endl;
	std::cout << v1.x << " " << v1.y << std::endl;

	cml::vec2<float> v2(1.0f, 1.0f);
	std::cout << "2nd vector" << std::endl;
	std::cout << v2.x << " " << v2.y << std::endl;

	v2 = v1;
	std::cout << "reassignment vector" << std::endl;
	std::cout << v2.x << " " << v2.y << std::endl;

	cml::vec2<float> v3 = v1 + v2;
	std::cout << "added vector" << std::endl;
	std::cout << v3.x << " " << v3.y << std::endl;

	std::string waitforinput;
	std::cin >> waitforinput;
}