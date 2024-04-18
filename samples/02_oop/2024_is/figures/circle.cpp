#include "circle.h"


Circle::Circle(const Point& _center, double _radius):center(_center),radius(_radius)
{

}

double Circle::area() const
{
    //return 3.14 * radius * radius;
    return 2;
}

double Circle::perimeter() const
{
    return 2 * 3.14 * radius;
}

