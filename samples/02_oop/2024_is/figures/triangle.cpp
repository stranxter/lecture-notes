#include "triangle.h"

#include "draw/sdlwrapper.h"
#include <cmath>

Triangle::Triangle(const Point& _p1, const Point& _p2, const Point& _p3):p1(_p1),p2(_p2),p3(_p3)
{
    
}

double Triangle::sidea() const
{
    return distance(p1,p2);
}

double Triangle::sideb() const
{
    return distance(p1,p3);
}

double Triangle::sidec() const
{
    return distance(p3,p2);
}

double Triangle::area() const
{
    
    double p = (sidea() + sideb() + sidec())/2;    
    return sqrt(p*(p-sidea())*(p-sideb())*(p-sidec()));
    
}

double Triangle::perimeter() const
{
    return sidea() + sideb() + sidec();
}  

void Triangle::draw() const
{
    sdlw::drawLine(p1.x*scale, p1.y*scale, p2.x*scale, p2.y*scale);
    sdlw::drawLine(p2.x*scale, p2.y*scale, p3.x*scale, p3.y*scale);
    sdlw::drawLine(p3.x*scale, p3.y*scale, p1.x*scale, p1.y*scale);
}

void Triangle::save(std::ostream& out) const
{
    out << "Triangle " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << std::endl;
}

void Triangle::load(std::istream& in)
{
    in >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
}
