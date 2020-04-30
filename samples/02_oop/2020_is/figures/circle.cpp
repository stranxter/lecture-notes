#include "circle.h"


Circle::Circle (double _x, double _y, double _r):x(_x),y(_y),r(_r){}

double Circle::perim()
{
    return 2*3.14*r;        
}

double Circle::surface()
{
    return 3.14*r*r;
}

void Circle::save(std::ostream &out)
{
    out << "circle: "<< x << " " << y << " " << r << " "; 
}

void Circle::load(std::istream& in)
{
    in >> x >> y >> r;
}

Figure *Circle::copy()
{
    return new Circle(*this);
}

