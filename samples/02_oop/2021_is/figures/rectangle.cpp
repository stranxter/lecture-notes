#include "rectangle.h"    
    
Rectangle::Rectangle(double _a, double _b):
     a(_a),b(_b),Figure("Rectangle")
{}

double Rectangle::surface()
{
    return a*b;
}

void Rectangle::saveToFile(std::ostream &out)
{
    out << "rect " << a << " " << b << " ";
}

void Rectangle::loadFromFile (std::istream &in)
{
    in >> a >> b;
}

Rectangle::Rectangle():Figure("Rectangle"){};