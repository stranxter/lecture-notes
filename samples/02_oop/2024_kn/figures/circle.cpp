#include "circle.h"
#include <cmath>


Circle::Circle(Point _center,double _r):center(_center),r(_r)
{
}

double Circle::area() const
{
    return 3.14159*r*r;
}

double Circle::perimeter() const
{
    return 2*3.14159*r;
}


