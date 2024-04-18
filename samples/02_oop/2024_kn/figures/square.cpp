#include "square.h"

#include <cmath>


Square::Square(Point _p1, Point _p2, Point _p3):p1(_p1),p2(_p2),p3(_p3)
{
}

double Square::area() const
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
double Square::perimeter() const
{
    return 4*sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

