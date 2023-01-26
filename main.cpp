#include <lib_math/lib_math.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << ml::calc("2+2");
    std::cout << ml::calc("222222+222");
    return 0;
}