#include <lib_math/point3D.hpp>
#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

namespace ml {
class Vector3D
{
private:
    double x = 0;
    double y = 0;
    double z = 0;

public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(Point3D A, Point3D B);

    
    void operator = (const Vector3D& other);
    bool operator == (const Vector3D& other);    
    bool operator != (const Vector3D& other);
    Vector3D operator + (const Vector3D& other);
    Vector3D operator - (const Vector3D& other);
    Vector3D& operator ++ ();
    Vector3D& operator ++ (int value);
    Vector3D& operator -- ();
    Vector3D& operator -- (int value);

    void setCoordinates(double x, double y, double z);

    void printCoordinates();

    double len();

};
}

#endif