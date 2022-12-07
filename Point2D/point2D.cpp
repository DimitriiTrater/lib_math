#include "point2D.hpp"


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

double Point2D::getX()
{
    return this->x;
}

double Point2D::getY()
{
    return this->y;
}
