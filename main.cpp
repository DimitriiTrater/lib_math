#include "Point2D/point2D.hpp"
#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    // Vector3D vector3d;
    // Vector2D vector2d;
    // Vector2D res;
    // res = vector2d + 55;
    // vector3d++;
    // res.getCoordinates();
    // vector2d.getCoordinates();
    // vector3d.getCoordinates();
    Point2D A(5, 5);
    Point2D B(6, 6);
    Vector2D AB(A, B);
    AB++;
    AB.getCoordinates();
    return 0;
}