#include <iostream>
#include <cmath>

#include "errors.hpp"
#include "vector_geom.hpp"
// constructors
vector_geom::vector_geom(double x, double y)
{
    this->x = x;
    this->y = y;
    this->on_space = 2;
}

vector_geom::vector_geom(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->on_space = 3;
}

vector_geom::vector_geom()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;

}


// operators
void vector_geom::operator = (const vector_geom& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->on_space = other.on_space;
}

bool vector_geom::operator == (const vector_geom& other)
{
    if (this->on_space == 3 && other.on_space == 3) {
        
        return this->x == other.x && this->y == other.y && this->z == other.z;
    
    } else if (this->on_space == 2 && other.on_space == 2) {
        
        return this->x == other.x && this->y == other.y;
    
    } else {

        return errPlane();
    
    }
}

bool vector_geom::operator != (const vector_geom& other)
{
    if (this->on_space == 3 && other.on_space == 3) {

        return !(this->x == other.x && this->y == other.y && this->z == other.z); 
    
    } else if (this->on_space == 2 && other.on_space == 2) {
        
        return !(this->x == other.x && this->y == other.y);
    
    } else {
        
        return errPlane();
    
    }
}

vector_geom vector_geom::operator + (const vector_geom& other)
{
    vector_geom result(0, 0, 0);
    if (this->on_space == 3 && other.on_space == 3) {
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        result.z = this->z + other.z;
        return result;
    }

    if (this->on_space == 2 && other.on_space == 2) {
        vector_geom result(0, 0);
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }
    errPlane();
    return result;
}

vector_geom vector_geom::operator - (const vector_geom& other)
{
    vector_geom result(0, 0, 0);
    if (this->on_space == 3 && other.on_space == 3) {
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        result.z = this->z - other.z;
        return result;
    }

    if (this->on_space == 2 && other.on_space == 2) {
        vector_geom result(0, 0);
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        return result;
    }
    errPlane();
    return result;
}

//methods
void vector_geom::setCoordinates(double x, double y)
{
    this->x = x;
    this->y = y;
    this->on_space = false;
}

void vector_geom::setCoordinates(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->on_space = true;
}

double vector_geom::len()
{
    if (this->on_space)
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);     
    return sqrt(this->x * this->x + this->y * this->y);
}

void vector_geom::getCoordinates()
{
    if (this->on_space == 3) { 
        std::cout << this->x << " " << this->y << " " << this->z << std::endl;
        return;
    }

    if (this->on_space == 2) {
        std::cout << this->x << " " << this->y << std::endl;
        return;
    }

    errPlane();
}