cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(CML VERSION 1 LANGUAGES CXX)

target_sources(CML PUBLIC cml/cml.h cml/mat3.h cml/mat4.h cml/vec2.h cml/vec3.h cml/vec4.h cml/quat.h cml/serial.h)

