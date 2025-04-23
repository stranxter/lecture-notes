#include "triangle.h"
#include <cmath>

#include "draw/sdlwrapper.h"


Triangle::Triangle():p1({0,0}),p2({0,0}),p3({0,0}){}

Triangle::Triangle(Point _p1, Point _p2, Point _p3):p1(_p1),p2(_p2),p3(_p3){}

double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double Triangle::surface()
{
    double a=dist(p1,p2), b=dist(p1,p3), c=dist(p2,p3), p=(a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
    
}
double Triangle::perimeter()
{
    double a=dist(p1,p2), b=dist(p1,p3), c=dist(p2,p3);
    return a+b+c;    
}

void Triangle::draw()
{
    sdlw::drawLine(p1.x,p1.y,p2.x,p2.y);
    sdlw::drawLine(p2.x,p2.y,p3.x,p3.y);
    sdlw::drawLine(p1.x,p1.y,p3.x,p3.y);
}

void Triangle::toSVG(std::ostream &f)
{
  //  f << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w << "\" height=\"" << h << "\"/>\n";
}

void Triangle::serialize(std::ostream &out)
{
    out << "tri " << p1 << " " << p2 << " " << p3;
}

void Triangle::deserialize(std::istream &in)
{
    in >> p1 >> p2 >> p3;
}
