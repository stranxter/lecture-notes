#include "square.h"

Square::Square (double _a):a(_a){}

double Square::perim()
{
    return 4*a;
}

double Square::surface()
{
    return a*a;
}

int Square::nsides()
{
    return 4;
}

void Square::save(std::ostream &out)
{
    out << "sq " << a << " ";
}

void Square::load(std::istream &in)
{
    in >> a;
}
