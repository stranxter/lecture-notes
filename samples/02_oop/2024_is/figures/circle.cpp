#include "circle.h"

#include "draw/sdlwrapper.h"

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

void Circle::draw(Point origin = {0,0}) const
{
    sdlw::drawFillCircle(center.x*scale+origin.x*scale, center.y*scale+origin.y*scale, radius*scale);
}

void Circle::save(std::ostream& out) const
{
    out << "Circle " << center.x << " " << center.y << " " << radius << std::endl;
}

void Circle::load(std::istream& in)
{
    in >> center.x >> center.y >> radius;
}


Figure* Circle::copy() const
{
    return new Circle(center, radius);
}