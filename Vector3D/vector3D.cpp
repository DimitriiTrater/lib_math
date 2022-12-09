#include <iostream>
#include <cmath>
#include "vector3D.hpp"

// constructors



Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;

}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D(Point3D A, Point3D B)
{
    this->x = B.getX() - A.getX();
    this->y = B.getY() - A.getY();
    this->z = B.getZ() - A.getZ();

}



// operators
void Vector3D::operator = (const Vector3D& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

bool Vector3D::operator == (const Vector3D& other)
{
    return this->x == other.x && this->y == other.y && this->z == other.z;    
}

bool Vector3D::operator != (const Vector3D& other)
{
    return !(this->x == other.x && this->y == other.y && this->z == other.z); 
}

Vector3D Vector3D::operator + (const Vector3D& other)
{
    Vector3D result(0, 0, 0);

    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + other.z;
    return result;
    
}

Vector3D Vector3D::operator - (const Vector3D& other)
{
    Vector3D result(0, 0, 0);

    result.x = this->x - other.x;
    result.y = this->y - other.y;
    result.z = this->z - other.z;
    return result;
}


Vector3D & Vector3D::operator ++()
{
    this->x++;
    this->y++;
    this->z++;
    return *this;
}

Vector3D & Vector3D::operator ++(int value)
{
    Vector3D& temp(*this);

    this->x++;
    this->y++;
    this->z++;
    return temp;
}


Vector3D & Vector3D::operator --()
{
    this->x--;
    this->y--;
    this->z--;
    return *this;
}

Vector3D & Vector3D::operator --(int value)
{
    Vector3D& temp(*this);

    this->x--;
    this->y--;
    this->z--;
    return temp;
}

//methods

void Vector3D::setCoordinates(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3D::len()
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);     
}

void Vector3D::getCoordinates()
{
    std::cout << this->x << " " << this->y << " " << this->z << std::endl;
}