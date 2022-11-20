#include <iostream>

bool errPlane()
{
    std::cerr                                       << "\n"
              << "--------------------------------" << "\n" 
              << "| ERROR: Not in the same plane |" << "\n"
              << "--------------------------------" << "\n"
              << std::endl;
    return false;
}