#include <cmath>

#include "circle.h"
#include "draw/sdlwrapper.h"

Circle::Circle(double _x, double _y, double _r):Figure("Circle"),r(_r),x(_x), y(_y)
{}

double Circle::surface()
{
    return M_PI*r*r;
}

void Circle::saveToFile(std::ostream &out)
{
    out << "circle " << x << " " << y << " " << r << " ";
}

void Circle::loadFromFile (std::istream &in)
{
    in >> x >> y >> r;
}

Circle::Circle():Figure("Circle"){}

void Circle::draw()
{
    sdlw::drawFillCircle(x-r/2,y-r/2,r);
}

Figure* Circle::clone()
{
    return new Circle(*this);
}