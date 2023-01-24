# DimitriiTrater

cmake_minimum_required(VERSION 3.23)

project(math_lib VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(APE_EXE StaticTest)


include(CTest)
enable_testing()


add_library(
    _math   STATIC
        
    Point2D/point2D.cpp       Point2D/point2D.hpp
    Point3D/point3D.cpp       Point3D/point3D.hpp

    Vector2D/vector2D.cpp     Vector2D/vector2D.hpp
    Vector3D/vector3D.cpp     Vector3D/vector3D.hpp

    calc/calc.cpp             calc/calc.hpp
)

add_executable(
    ${APE_EXE} main.cpp
)

target_link_libraries(${APE_EXE} _math)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



