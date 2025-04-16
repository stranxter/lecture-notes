
#include"rectangle.h"
#include "draw/sdlwrapper.h"
    
Rect::Rect(double _x, double _y, double _w, double _h):x(_x),y(_y),w(_w),h(_h){}

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
    sdlw::drawLine(x-w/2,y-h/2,x+w/2,y-h/2);
    sdlw::drawLine(x+w/2,y-h/2,x+w/2,y+h/2);
    sdlw::drawLine(x+w/2,y+h/2,x-w/2,y+h/2);
    sdlw::drawLine(x-w/2,y+h/2,x-w/2,y-h/2);
}
    
void Rect::toSVG(std::ostream &f)
{
    f << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w << "\" height=\"" << h << "\"/>\n";
}
