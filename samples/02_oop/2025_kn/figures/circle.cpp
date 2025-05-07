#include "circle.h"
#include "draw/sdlwrapper.h"

Circle::Circle():c({0,0}),r(0){}

double Circle::perimeter()
{
    return 2 * 3.14 * r;
}

double Circle::surface()
{
    return 3.14 * r * r;
}

Circle::Circle(Point _c, double _r, Color _clr):Figure(_clr),c(_c),r(_r)
{

}

Figure* Circle::clone()
{
    return new Circle(*this);
}


void Circle::draw()
{
    predraw();
    sdlw::drawFillCircle(c.x,c.y,r);
}


void Circle::toSVG(std::ostream &f)
{
    f << "<circle cx=\"" << c.x << "\" cy=\"" << c.y << "\" r=\"" << r << "\"/>\n";
}

void Circle::serialize(std::ostream &out)
{
    out << "circle " << c << " " << r;
}

void Circle::deserialize(std::istream &in)
{
    in >> c >> r;
}
