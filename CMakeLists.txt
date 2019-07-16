cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(CML VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    target_compile_options(CML PRIVATE "/std:c++17")
	target_compile_options(CML PRIVATE "/permissive-")
endif(MSVC)

add_library(cml INTERFACE)

target_include_directories(cml INTERFACE "${PROJECT_SOURCE_DIR}/src")

add_executable(cml-tests test/test.cpp test/test2.cpp)

target_link_libraries(cml-tests cml)
target_include_directories(cml-tests PRIVATE "${PROJECT_SOURCE_DIR}/src")
