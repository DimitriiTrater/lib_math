# DimitriiTrater

cmake_minimum_required(VERSION 3.23)

project(math_lib VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

add_executable(
    math_lib           main.cpp
    vector2D.cpp     vector2D.hpp
    vector3D.cpp     vector3D.hpp
    errors.cpp          errors.hpp
)