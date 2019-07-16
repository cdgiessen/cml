
#include "cml/cml.h"
#include "cml/serial.h"
#include <cstdio>
#include <iostream>
#include <string>

void test_vector ()
{
	std::cout << "\n";
	cml::vec2 a{ 2, 3 };
	cml::vec3 b{ 2, 3, 4 };
	cml::vec4 c{ 2, 3, 4, 5 };

	cml::vec3f v1 (2.0f, 3.0f, 2.5f);
	std::cout << "v1 = 2.0f, 3.0f, 2.5f  == " << v1 << "\n";

	cml::vec3f v2 (1.0f, 1.0f, 1.0f);
	std::cout << "v2 = 1.0f, 1.0f, 1.0f  == " << v2 << "\n";

	v2 = v1;
	std::cout << "v2 = v1 " << v2 << "\n";

	cml::vec3f v3 = v1 + v2;
	std::cout << "v3 = v1 + v2  == " << v3 << "\n";

	v3 = cml::vec3f::zero;
	std::cout << "reset v3 to ZERO v3 = " << v3 << "\n";
}

void test_matrix ()
{
	std::cout << "\n";
	cml::vec4f vec4val (1, 2, 3, 4);
	auto matA = cml::mat4f (4, 0, 3, 2, 5, 3, 5, 4, 1, 6, 0, 6, 8, 1, 9, 1);
	auto matB = cml::mat4f (1, 0, 3, 2, 5, 3, 5, 0, 1, 6, 7, 6, 0, 1, 2, 1);

	std::cout << "matA*vec3val" << matA * vec4val << "\n";
	std::cout << "vec3val * matA" << vec4val * matA << "\n";

	std::cout << "Following should equal\n[23,40,89,15,20,39,66,16,21,30,87,14,22,52,74,17]\n";
	std::cout << "matA * matB = \n" << matA * matB << "\n";


	cml::mat4f matC (1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1);
	cml::mat4f matD (2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1);
	cml::mat4<int> matDet (3, 2, -1, 4, 2, 1, 5, 7, 0, 5, 2, -6, -1, 2, 1, 0); // determinate should be -418

	matD = matC - matD;

	std::cout << "matC" << matC << "\n";

	std::cout << "matD" << matD << "\n";

	std::cout << "matDet det = " << matDet.det () << "\n";

	cml::vec3f a{ 0, 2, -3 };
	std::cout << "matC * v1 = " << matC * to_vec4 (a) << "\n";

	std::cout << "matA get col 2  == " << matA.get_col (2) << "\n";

	std::cout << "matA get row 3  == " << matA.get_row (3) << "\n";
}

void test_quaternion ()
{
	std::cout << "\n";
	std::cout << "Quaternion identity" << cml::quatf::identity << "\n";

	cml::quatf quatA = cml::quatf::fromEulerAngles (30, 0, 180);
	std::cout << "QuatA = Rotation 30 around x, 0 around y, 180 around z" << quatA << "\n";
	std::cout << "Mag of quatA " << quatA.mag () << "\n";
}

void test_transform ()
{
	std::cout << "\n";

	cml::mat4 matA;
	matA.scale (5);
	matA.set_translation (cml::vec3<float> (1, 2, 3));
	std::cout << "matA" << matA << "\n";

	cml::mat4f matB;
	matB.translate (cml::vec3<float> (0.5, 0.1, 1.5));
	matB.scale ({ 3, 1, 1 });
	std::cout << "matA + matB" << matA + matB << "\n";


	// std::cout << "vector " << vec1 << " rotated around " << cml::QUAT_X_90 << " is "
	//           << cml::quatf::rotate (vec1, cml::QUAT_X_90) << "\n";
}

void test_constants ()
{
	cml::mat4<float> matIden;
	std::cout << "is matrix an identity matrix == " << matIden.isIdentity () << "\n";
	std::cout << "matIden"
	          << "\n";
	std::cout << "\n";
	std::cout << "vec2 constants:\n ";
	std::cout << "ZERO " << cml::vec2f::zero << "\n";
	std::cout << "ONE " << cml::vec2f::one << "\n";
	std::cout << "RIGHT " << cml::vec2f::right << "\n";
	std::cout << "LEFT " << cml::vec2f::left << "\n";
	std::cout << "UP " << cml::vec2f::up << "\n";
	std::cout << "DOWN " << cml::vec2f::down << "\n";

	std::cout << "\n";
	std::cout << "vec3 constants:\n";
	std::cout << "ZERO " << cml::vec3f::zero << "\n";
	std::cout << "ONE " << cml::vec3f::one << "\n";
	std::cout << "RIGHT " << cml::vec3f::right << "\n";
	std::cout << "LEFT " << cml::vec3f::left << "\n";
	std::cout << "UP " << cml::vec3f::up << "\n";
	std::cout << "DOWN " << cml::vec3f::down << "\n";
	std::cout << "FOWARD " << cml::vec3f::forward << "\n";
	std::cout << "BACK " << cml::vec3f::back << "\n";

	std::cout << "\n";
	std::cout << "vec4 constants:\n";
	std::cout << "ZERO " << cml::vec4f::zero << "\n";
	std::cout << "ONE " << cml::vec4f::one << "\n";
	std::cout << "RIGHT " << cml::vec4f::right << "\n";
	std::cout << "LEFT " << cml::vec4f::left << "\n";
	std::cout << "UP " << cml::vec4f::up << "\n";
	std::cout << "DOWN " << cml::vec4f::down << "\n";
	std::cout << "FOWARD " << cml::vec4f::forward << "\n";
	std::cout << "BACK " << cml::vec4f::back << "\n";
	std::cout << "W_POSITIVE " << cml::vec4f::w_positive << "\n";
	std::cout << "W_NEGATIVE " << cml::vec4f::w_negative << "\n";
}

void test_common ()
{
	std::cout << "\n";
	float half = 0.5f;
	float quarter = 0.25f;
	float ninety = 0.9f;

	cml::vec2f a2{ -2, 3 };
	cml::vec2f b2{ 2, -3 };
	cml::vec2 c2{ 0.25f, 0.75f };

	cml::vec3f a3{ 2, 3, 4 };
	cml::vec3f b3{ -2, 1, 3 };

	cml::vec4f a4{ 2, 3, 4, 1 };
	cml::vec4f b4{ -2, 1, 3, 2 };

	std::cout << "Dot product2 = " << dot (a2, b2) << "\n";
	std::cout << "Dot product3 = " << dot (a3, b3) << "\n";
	std::cout << "Dot product3 = " << dot (a4, b4) << "\n";

	std::cout << "Cross of " << cml::vec3f (3, -3, 1) << " and " << cml::vec3f (4, 9, 2)
	          << " == " << cml::cross (cml::vec3f (3, -3, 1), cml::vec3f (4, 9, 2)) << "\n";
	std::cout << "Should equal [-15, -2, 39]\n";

	std::cout << "Lerp " << cml::lerp (a2, b2, c2) << "\n";
	std::cout << "Lerp " << cml::lerp (a3, b3, half) << "\n";
	std::cout << "Lerp " << cml::lerp (a4, b4, ninety) << "\n";
}

int main ()
{
	test_vector ();
	test_matrix ();
	test_quaternion ();
	test_transform ();
	test_constants ();
	test_common ();


	// std::cout << "Press any key to continue..." << "\n";
	// std::getchar ();
}