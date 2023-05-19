#include "circle.h"
#include "draw/sdlwrapper.h"

Circle::Circle(Point2D _center, double _r):center(_center), r(_r){}

double Circle::surface()
{
    return 3.14*r*r;
}

double Circle::perimeter()
{
    return 2*3.14*r;
}

void Circle::writeToStream(std::ostream& out)
{
    out << "Circle " << r << " " << center.x << " " << center.y;
}

void Circle::loadFromStream(std::istream &in)
{
    in >> r >> center.x >> center.y;
}

void Circle::draw()
{
    sdlw::drawFillCircle(center.x,center.y,r);
}

void Circle::translate(double x, double y)
{
    center.x += x;
    center.y += y;
}

Figure* Circle::clone()
{
    return new Circle(*this);
}

Point2D Circle::getCenter() const
{
    return center;
}

double Circle::getRadius() const
{
    return r;
}

void Circle::accept(Visitor *v)
{
    v->visitCircle(this);
}
