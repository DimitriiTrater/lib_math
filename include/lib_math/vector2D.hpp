#include <lib_math/point2D.hpp>
#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP


// 2D Vector header file

namespace ml {
class Vector2D
{
private:
    double x = 0;
    double y = 0;

public:
    Vector2D();
    Vector2D(double x, double y);
    Vector2D(Point2D A, Point2D B);
    
    void operator = (const Vector2D& other);
    bool operator == (const Vector2D& other);    
    bool operator != (const Vector2D& other);

    Vector2D operator + (const Vector2D& other);
    Vector2D operator + (double value);
    
    Vector2D operator - (const Vector2D& other);
    Vector2D operator - (double value);
    
    // Vector2D operator * (const Vector2D& other);
    // Vector2D operator * (double value);
    

    Vector2D& operator ++ ();
    Vector2D& operator ++ (int value);
    
    Vector2D& operator -- ();
    Vector2D& operator -- (int value);



    void setCoordinates(double x, double y);

    void printCoordinates();

    double len();


};
}

#endif