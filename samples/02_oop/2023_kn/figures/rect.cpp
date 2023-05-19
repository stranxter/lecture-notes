#include "rect.h"
#include <cmath>
#include "draw/sdlwrapper.h"

Rect::Rect(Point2D _a, double _w, double _h):a(_a),w(_w),h(_h){}

double Rect::surface()
{
    return w*h;
}

double Rect::perimeter()
{
    return 2*(w+h);
}

void Rect::writeToStream(std::ostream& out)
{
    out << "Rect " << a.x << " " << a.y << " " << w << " " << h;
}

void Rect::loadFromStream(std::istream &in)
{
    in >> a.x >> a.y >> w >> h;
}

void Rect::draw()
{
    sdlw::drawFillRect(a.x,a.y,w,h);
}

void Rect::translate(double x, double y)
{
    a.x += x;
    a.y += y;
}

Figure* Rect::clone()
{
    return new Rect(*this);
}

Point2D Rect::getVertex() const
{
    return a;
}
double Rect::getW() const
{
    return w;
}
double Rect::getH() const
{
    return h;
}

void Rect::accept(Visitor *v)
{
    v->visitRect(this);
}