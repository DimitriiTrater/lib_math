#include <SFML/Graphics.hpp>
#include "vector_geom.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    vector_geom vec(3, 4);
    vector_geom v1(3, 4, 5);
    v1 = vec;

    v1.getCoordinates();
    return 0;
}