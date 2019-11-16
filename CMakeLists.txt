cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(CML VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(cml INTERFACE)

if(MSVC)
    target_compile_options(cml INTERFACE "/std:c++17")
	target_compile_options(cml INTERFACE "/permissive-")
endif(MSVC)

target_include_directories(cml INTERFACE "${PROJECT_SOURCE_DIR}/src")

if(CML_ENABLE_TESTING)

add_executable(cml-tests test/test.cpp test/test2.cpp)

target_link_libraries(cml-tests cml)
target_include_directories(cml-tests PRIVATE "${PROJECT_SOURCE_DIR}/src")

endif(CML_ENABLE_TESTING)