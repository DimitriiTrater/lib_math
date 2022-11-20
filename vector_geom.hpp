#ifndef VECTOR_GEOM
#define VECTOR_GEOM

class vector_geom
{
private:
    double x;
    double y;
    double z;
    int on_space;

public:
    vector_geom();
    vector_geom(double x, double y);
    vector_geom(double x, double y, double z);
    
    void operator = (const vector_geom& other);
    bool operator == (const vector_geom& other);    
    bool operator != (const vector_geom& other);
    vector_geom operator + ();

    void setCoordinates(double x, double y);
    void setCoordinates(double x, double y, double z);

    void getCoordinates();

    double len();


};


#endif