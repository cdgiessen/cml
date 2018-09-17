# cml

## Charles Math Library

Library with common math functions associated with graphics.

Supports Vectors of 2, 3, and 4 components, Matrices of 3x3 and 4x4 with translation, scaling and rotation functions, Quaternions, and common graphics functions like Othrographics and Perspective matrxi calculaion.

Written for the Game Engine Design course.
Named after myself for lack of better inspiration.

Simple example usage
```cpp

cml::vec3f v1; 
cml::vec3f v2(1.0f, 1.0f, 1.0f);

cml::vec3f v3 = v1 + v2; //operator overloads implemented

cml::vec3f vec1 = cml::VEC3_FORWARD; //common directions provided

cml::mat4<float> matA; //can use any user type

matA.setScaleFactor(5); 
matA.setToTranslation(cml::vec3<float>(1, 2, 3));

matA.det() //calculates and returns the determinant

cml::mat4<float> matB = matA * v1; //matrix vector multiplication overload

std::cout << matB << "\n"; //includes ostream overloads for easy printing.

cml::quatf quatA = cml::quatf::fromEulerAngles(30,0,180);
cml::quatf::rotate(v1, cml::QUAT_X_90)

```
