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

    double getX();
    double getY();
    double getZ();

};

#endif

