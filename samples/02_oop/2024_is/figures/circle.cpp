#include "circle.h"
#include "visitor.h"

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

Point Circle::getCenter() const
{
    return center;
}

void Circle::accept(Visitor* v)
{
    v->visitCircle(this);
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::load(std::istream& in)
{
    in >> center.x >> center.y >> radius;
}


Figure* Circle::copy() const
{
    return new Circle(center, radius);
}