#include "Point2D/point2D.hpp"
#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include "Matrix/matrix.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    ml::Matrix m(10, 10);
    m(5, 8) = 156;
    std::cout << m(1, 1);
    return 0;
}