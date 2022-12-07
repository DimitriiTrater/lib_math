#include "point3D.hpp"


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