#include "rectangle.h"  
#include "draw/sdlwrapper.h"  
    
Rectangle::Rectangle(double _x, double _y, double _a, double _b):
     Figure("Rectangle"),x(_x),y(_y),a(_a),b(_b)
{}

double Rectangle::surface()
{
    return a*b;
}

void Rectangle::saveToFile(std::ostream &out)
{
    out << "rect " << x << " " << y << " " << a << " " << b << " ";
}

void Rectangle::loadFromFile (std::istream &in)
{
    in >> x >> y >> a >> b;
}

Rectangle::Rectangle():Figure("Rectangle"){};

void Rectangle::draw()
{
    sdlw::drawFillRect(x,y,a,b);
}

Figure* Rectangle::clone()
{
    return new Rectangle(*this);
}