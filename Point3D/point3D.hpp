#ifndef POINT_3D_HPP
#define POINT_3D_HPP

class Point3D
{
private:
    double x = 0;
    double y = 0;
    double z = 0;

public:
    Point3D();
    Point3D(double x, double y, double z);

    Point3D Point3D::operator + (const Point3D& other);
    Point3D Point3D::operator - (const Point3D& other);


    double getX();
    double getY();
    double getZ();

};

#endif

