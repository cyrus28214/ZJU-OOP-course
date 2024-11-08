#include <iostream>
#include "Point.h"

void Point::init(int ix, int iy)
{
//    this->px = ix;
    px = ix;
    py = iy;
}

void Point::print()
{
//    std::cout << this << std::endl;   
    std::cout << "point at (" << px << ", " << py << ")" << std::endl;
}

void Point::move(int dx, int dy)
{
    px += dx;
    py += dy;
}
