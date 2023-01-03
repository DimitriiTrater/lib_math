#include "point3D.hpp"

// Point3D source file
namespace ml {
Point3D::Point3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point3D Point3D::operator + (const Point3D& other)
{
    Point3D result(0, 0, 0);
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

Point3D Point3D::operator - (const Point3D& other)
{
    Point3D result(0, 0, 0);
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
}

double Point3D::getX()
{
    return this->x;
}

double Point3D::getY()
{
    return this->y;
}

double Point3D::getZ()
{
    return this->z;
}
}