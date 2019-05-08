#include "rectangle.h"
#include "visitor.h"

Rect::Rect(int _x, int _y, int _w, int _h, const char *_s):Shape(_x,_y,_s),w(_w),h(_h)
{

}

void Rect::set_w(int _w)
{
    w=_w;
}
void Rect::set_h(int _h)
{
    h=_h;
}

int Rect::get_w() const
{
    return w;
}
int Rect::get_h() const
{
    return h;
}

void Rect::set_color(int _r, int _g, int _b)
{
    r=_r;
    g=_g;
    b=_b;
}

Shape *Rect::clone()
{
    return new Rect(*this);
}

int Rect::get_r () const
{
    return r;
}
int Rect::get_g () const
{
    return g;
}
int Rect::get_b () const
{
    return b;
}

void Rect::accept (Visitor *v)
{
    v->visitReactangle (this);
}