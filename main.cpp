#include "Point2D/point2D.hpp"
#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include "Matrix/matrix.hpp"
#include <iostream>

void foo(ml::Matrix m_inf)
{
    m_inf(5,5) = 145;
}

int main(int argc, char* argv[])
{
    ml::Matrix m(10, 10);
    foo(m);
    
    //m(5, 8) = 156;
    //std::cout << m(1, 1);
    return 0;
}