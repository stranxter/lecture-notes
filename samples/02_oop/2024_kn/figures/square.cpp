#include "square.h"

#include <cmath>
#include "draw/sdlwrapper.h"


Square::Square(Point _p1, Point _p2):p1(_p1),p2(_p2)
{
}

double Square::side() const
{
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y))/2);
}

double Square::area() const
{
    return side()*side();
}
double Square::perimeter() const
{
    return 4*side();
}

void Square::draw() const
{
    sdlw::drawLine(scale*p1.x,scale*p1.y,scale*p2.x,scale*p1.y);
    sdlw::drawLine(scale*p2.x,scale*p1.y,scale*p2.x,scale*p2.y);
    sdlw::drawLine(scale*p2.x,scale*p2.y,scale*p1.x,scale*p2.y);
    sdlw::drawLine(scale*p1.x,scale*p2.y,scale*p1.x,scale*p1.y);
}

void Square::saveToFile(std::ostream& os) const
{
    os << "Square " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
}

void Square::loadFromFile(std::istream& is)
{
    is >> p1.x >> p1.y >> p2.x >> p2.y;
}   

Figure* Square::copy() const
{
    return new Square(*this);
}