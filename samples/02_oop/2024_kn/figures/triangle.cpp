#include "triangle.h"

#include <cmath>

Triangle::Triangle(Point _p1, Point _p2, Point _p3):p1(_p1),p2(_p2),p3(_p3)
{
}

double Triangle::area() const
{
    double a = side_a(),
           b = side_b(),
           c = side_c(),
           p = (a+b+c)/2;

           return sqrt(p*(p-a)*(p-b)*(p-c));

}

double Triangle::perimeter() const
{
    return side_a() + side_b() + side_c();
}

double Triangle::side_a() const
{
    return sqrt((p2.x-p3.x)*(p2.x-p3.x) + (p2.y-p3.y)*(p2.y-p3.y));
}

double Triangle::side_b() const
{
    return sqrt((p1.x-p3.x)*(p1.x-p3.x) + (p1.y-p3.y)*(p1.y-p3.y));
}

double Triangle::side_c() const
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}