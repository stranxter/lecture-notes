#include "figure.h"

std::ostream& operator << (std::ostream &out,const Point &p)
{
    out << p.x << " " << p.y;
    return out;
}

std::istream& operator >> (std::istream &in,Point &p)
{
    in >> p.x >> p.y;
    return in;
}