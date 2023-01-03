#include <iostream>
#include <cmath>
#include "vector2D.hpp"

namespace ml {
// constructors
Vector2D::Vector2D()
{
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(Point2D A, Point2D B)
{
    this->x = B.getX() - A.getX();
    this->y = B.getY() - A.getY();
}


// operators
void Vector2D::operator = (const Vector2D& other)
{
    this->x = other.x;
    this->y = other.y;
}

bool Vector2D::operator == (const Vector2D& other)
{
    return this->x == other.x && this->y == other.y;
}

bool Vector2D::operator != (const Vector2D& other)
{
    return !(this->x == other.x && this->y == other.y);
}

Vector2D Vector2D::operator + (const Vector2D& other)
{
    Vector2D result(0, 0);
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

Vector2D Vector2D::operator + (double value)
{
    Vector2D result(0, 0);
    result.x = this->x + value;;
    result.y = this->y + value;
    return result;
}

Vector2D Vector2D::operator - (const Vector2D& other)
{
    Vector2D result(0, 0);
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
}

Vector2D Vector2D::operator - (double value)
{
    Vector2D result(0, 0);
    result.x = this->x - value;
    result.y = this->y - value;
    return result;
}


Vector2D & Vector2D::operator ++()
{
    this->x++;
    this->y++;
    return *this;
}

Vector2D & Vector2D::operator ++(int value)
{
    Vector2D& temp(*this);

    this->x++;
    this->y++;
    return temp;
}


Vector2D & Vector2D::operator --()
{
    this->x--;
    this->y--;
    return *this;
}

Vector2D & Vector2D::operator --(int value)
{
    Vector2D& temp(*this);

    this->x--;
    this->y--;
    return temp;
}

//methods
void Vector2D::setCoordinates(double x, double y)
{
    this->x = x;
    this->y = y;
}


double Vector2D::len()
{
    return sqrt(this->x * this->x + this->y * this->y);
}

void Vector2D::printCoordinates()
{
    std::cout << this->x << " " << this->y << std::endl;
}

}