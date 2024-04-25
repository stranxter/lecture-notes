#include "square.h"
#include <cmath>

#include "draw/sdlwrapper.h"

Square::Square(const Point& _p1, const Point& _p2):p1(_p1),p2(_p2)
{
}

double Square::side() const
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Square::area() const
{
    //return side() * side();
    return 1;
}
double Square::perimeter() const
{
    return 4 * side();
}
void Square::draw() const
{
    sdlw::drawLine(p1.x*scale, p1.y*scale, p2.x*scale, p1.y*scale);
    sdlw::drawLine(p2.x*scale, p1.y*scale, p2.x*scale, p2.y*scale);
    sdlw::drawLine(p2.x*scale, p2.y*scale, p1.x*scale, p2.y*scale);
    sdlw::drawLine(p1.x*scale, p2.y*scale, p1.x*scale, p1.y*scale);
}

void Square::save(std::ostream& out) const
{
    out << "Square " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << std::endl;
}

void Square::load(std::istream& in)
{
    in >> p1.x >> p1.y >> p2.x >> p2.y;
}

