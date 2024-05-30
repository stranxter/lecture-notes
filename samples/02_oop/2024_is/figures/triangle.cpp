#include "triangle.h"

#include <cmath>
#include "visitor.h"

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

Point Triangle::getp1() const
{
    return p1;
}

void Triangle::accept(Visitor* v)
{
    v->visitTriangle(this);
}

Point Triangle::getp2() const
{
    return p2;
}

Point Triangle::getp3() const
{
    return p3;
}   

void Triangle::load(std::istream& in)
{
    in >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
}

Figure* Triangle::copy() const
{
    return new Triangle(p1, p2, p3);
}
