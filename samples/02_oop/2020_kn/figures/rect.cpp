#include "rect.h"

Rect::Rect (double _x,double _y,double _a,double _b)
      :a(_a),b(_b),x(_x),y(_y){}

double Rect::perim()
{
    return 2*(a+b);
}

double Rect::surface()
{
    return a*b;
}

int Rect::nsides()
{
    return 4;
}

void Rect::save(std::ostream &out)
{
    out << "rect " << x << " " << y << " " << a << " " << b << " ";
}

void Rect::load(std::istream &in)
{
    in >> x >> y >> a >> b;
}
