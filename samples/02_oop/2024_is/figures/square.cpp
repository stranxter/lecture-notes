#include "square.h"
#include <cmath>

Square::Square(const Point& _p1, const Point& _p2):p1(_p1),p2(_p2)
{
}

double Square::side() const
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Square::area() const
{
    //return side() * side();
    return 1;
}
double Square::perimeter() const
{
    return 4 * side();
}


