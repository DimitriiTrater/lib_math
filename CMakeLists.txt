# DimitriiTrater

cmake_minimum_required(VERSION 3.23)

project(math_lib VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

add_executable(
    math_lib                  main.cpp

    errors.cpp                errors.hpp
    
    Vector2D/vector2D.cpp     Vector2D/vector2D.hpp
    Vector3D/vector3D.cpp     Vector3D/vector3D.hpp

    Point2D/point2D.cpp       Point2D/point2D.hpp
)