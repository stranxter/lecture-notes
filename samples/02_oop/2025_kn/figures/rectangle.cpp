
#include"rectangle.h"
#include "draw/sdlwrapper.h"


Rect::Rect():c({0,0}),w(0),h(0){}

Rect::Rect(Point _c, double _w, double _h):c(_c),w(_w),h(_h){}

double Rect::surface()
{
    return w*h;
}

double Rect::perimeter()
{
    return 2*w+2*h;
}

void Rect::draw()
{
    sdlw::drawLine(c.x-w/2,c.y-h/2,c.x+w/2,c.y-h/2);
    sdlw::drawLine(c.x+w/2,c.y-h/2,c.x+w/2,c.y+h/2);
    sdlw::drawLine(c.x+w/2,c.y+h/2,c.x-w/2,c.y+h/2);
    sdlw::drawLine(c.x-w/2,c.y+h/2,c.x-w/2,c.y-h/2);
}
    
void Rect::toSVG(std::ostream &f)
{
    f << "<rect x=\"" << c.x << "\" y=\"" << c.y << "\" width=\"" << w << "\" height=\"" << h << "\"/>\n";
}

void Rect::serialize(std::ostream &out)
{
    out << "rect " << c << " " << w << " " << h << " ";
}

void Rect::deserialize(std::istream &in)
{
    in >> c >> w >> h;
}
