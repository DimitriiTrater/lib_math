#include <lib_math/point2D.hpp>

//Pint2D source file

namespace ml {
Point2D::Point2D()
{
    this->x = 0;
    this->y = 0;
}

Point2D::Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}


Point2D Point2D::operator + (const Point2D& other)
{
    Point2D result(0, 0);
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

Point2D Point2D::operator - (const Point2D& other)
{
    Point2D result(0, 0);
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    return result;
}



double Point2D::getX()
{
    return this->x;
}

double Point2D::getY()
{
    return this->y;
}
}