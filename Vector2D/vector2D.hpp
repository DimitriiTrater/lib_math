#ifndef VECTOR_2D
#define VECTOR_2D

// 2D Vector header file

class Vector2D
{
private:
    double x = 0;
    double y = 0;

public:
    Vector2D();
    Vector2D(double x, double y);
    
    void operator = (const Vector2D& other);
    bool operator == (const Vector2D& other);    
    bool operator != (const Vector2D& other);
    Vector2D operator + (const Vector2D& other);
    Vector2D operator - (const Vector2D& other);
    Vector2D& operator ++ ();
    Vector2D& operator ++ (int value);
    Vector2D& operator -- ();
    Vector2D& operator -- (int value);



    void setCoordinates(double x, double y);

    void getCoordinates();

    double len();


};


#endif