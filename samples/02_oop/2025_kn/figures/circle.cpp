#include "circle.h"
#include "draw/sdlwrapper.h"

double Circle::perimeter()
{
    return 2 * 3.14 * r;
}

double Circle::surface()
{
    return 3.14 * r * r;
}

Circle::Circle(double _x, double _y, double _r):x(_x),y(_y),r(_r)
{

}

void Circle::draw()
{
    sdlw::drawFillCircle(x,y,r);
}


void Circle::toSVG(std::ostream &f)
{
    f << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << r << "\"/>\n";
}
