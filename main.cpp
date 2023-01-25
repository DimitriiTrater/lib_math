#include "Point2D/point2D.hpp"
#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include "Matrix/matrix.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
    ml::Matrix m(1, 1);
    m(0, 0) = 5;
    ml::Matrix m_t(m);
    
    std::cout << m_t(0, 0);
    return 0;
}