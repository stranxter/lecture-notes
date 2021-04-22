#include <cmath>

#include "circle.h"

Circle::Circle(double _r):Figure("Circle"),r(_r)
{}

double Circle::surface()
{
    return M_PI*r*r;
}

void Circle::saveToFile(std::ostream &out)
{
    out << "circle " << r << " ";
}

void Circle::loadFromFile (std::istream &in)
{
    in >> r;
}

Circle::Circle():Figure("Circle"){}