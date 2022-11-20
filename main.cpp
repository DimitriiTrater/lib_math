#include <SFML/Graphics.hpp>
#include "vector_geom.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    vector_geom vec(3, 4, 6);
    vector_geom v1(3, 4, 5);
    vector_geom v2 = vec - v1;

    v2.getCoordinates();
    return 0;
}