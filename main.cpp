#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    Vector3D vector3d;
    Vector2D vector2d;
    vector2d++;
    vector3d++;
    vector2d.getCoordinates();
    vector3d.getCoordinates();
    return 0;
}