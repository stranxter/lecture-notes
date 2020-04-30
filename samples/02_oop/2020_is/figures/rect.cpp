
#include "rect.h"

Rectangle::Rectangle (double _a, double _b):a(_a),b(_b){}

double Rectangle::perim()
{
    return 2*a+2*b;
}

double Rectangle::surface()
{
    return a*b;
}

int Rectangle::nsides()
{
    return 4;
}

void Rectangle::save(std::ostream &out)
{
    out << "rect: " << a << " " << b << " "; 
}

void Rectangle::load(std::istream& in)
{
    in >> a >> b;
}

Figure *Rectangle::copy()
{
    return new Rectangle(*this);
}
