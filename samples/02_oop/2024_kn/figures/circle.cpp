#include "circle.h"
#include <cmath>

#include "draw/sdlwrapper.h"


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

void Circle::draw() const
{
    sdlw::drawFillCircle(scale*center.x,scale*center.y,scale*r);
}

void Circle::saveToFile(std::ostream& os) const
{
    os << "Circle " << center.x << " " << center.y << " " << r << std::endl;
}

void Circle::loadFromFile(std::istream& in)
{
    in >> center.x >> center.y >> r;
}

Figure* Circle::copy() const
{
    return new Circle(*this);
}


