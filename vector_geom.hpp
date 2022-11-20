#ifndef VECTOR_GEOM
#define VECTOR_GEOM

class vector_geom
{
private:
    double x = 0;
    double y = 0;
    double z = 0;
    int on_space = 0;

public:
    vector_geom();
    vector_geom(double x, double y);
    vector_geom(double x, double y, double z);
    
    void operator = (const vector_geom& other);
    bool operator == (const vector_geom& other);    
    bool operator != (const vector_geom& other);
    vector_geom operator + (const vector_geom& other);
    vector_geom operator - (const vector_geom& other);


    void setCoordinates(double x, double y);
    void setCoordinates(double x, double y, double z);

    void getCoordinates();

    double len();


};


#endif