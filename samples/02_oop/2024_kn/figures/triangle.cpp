#include "triangle.h"

#include <cmath>
#include "draw/sdlwrapper.h"

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

void Triangle::draw() const
{
    sdlw::drawLine(scale*p1.x,scale*p1.y,scale*p2.x,scale*p2.y);
    sdlw::drawLine(scale*p2.x,scale*p2.y,scale*p3.x,scale*p3.y);
    sdlw::drawLine(scale*p3.x,scale*p3.y,scale*p1.x,scale*p1.y);
}

void Triangle::saveToFile(std::ostream& os) const
{
    os << "Triangle " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << std::endl;
}

void Triangle::loadFromFile(std::istream& is)
{
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
}

Figure* Triangle::copy() const
{
    return new Triangle(*this);
}