cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(CML VERSION 1 LANGUAGES CXX)

add_library(cml INTERFACE)

target_include_directories(cml INTERFACE "${PROJECT_SOURCE_DIR}/src")

add_executable(cml-tests test/test.cpp)

target_link_libraries(cml-tests cml)
target_include_directories(cml-tests PRIVATE "${PROJECT_SOURCE_DIR}/src")
