#include "Point2D/point2D.hpp"
#include "Vector2D/vector2D.hpp"
#include "Vector3D/vector3D.hpp"
#include "Matrix/matrix.hpp"
#include <iostream>
#define k 4

int main(int argc, char* argv[])
{
    ml::Matrix m(k, k);
    int a = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {    
            m(i, j) = a;
            a++;
        }
    
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {    
            std::cout << m(i, j) << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}