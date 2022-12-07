#ifndef POINT_2D_HPP
#define POINT_2D_HPP

class Point2D
{
private:
    double x = 0;
    double y = 0;

public:
    Point2D();
    Point2D(double x, double y);

    Point2D operator + (const Point2D& other);
    Point2D operator - (const Point2D& other);
    
    
    double getX();
    double getY();
};

#endif

