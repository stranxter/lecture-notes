#include "rect.h"
#include "visitor.h"

Rect::Rect (double _x,double _y,double _a,double _b)
      :x(_x),y(_y),a(_a),b(_b){}

double Rect::perim()
{
    return 2*(a+b);
}

double Rect::surface()
{
    return a*b;
}

int Rect::nsides()
{
    return 4;
}

void Rect::save(std::ostream &out)
{
    out << "rect " << x << " " << y << " " << a << " " << b << " ";
}

void Rect::load(std::istream &in)
{
    in >> x >> y >> a >> b;
}

Figure* Rect::copy()
{
    return new Rect(*this);
}

void Rect::accept(Visitor *v)
{
    v->process_rect(this);
}

double Rect::get_x()
{
    return x;
}
double Rect::get_y()
{
    return y;
}
double Rect::get_a()
{
    return a;
}
double Rect::get_b()
{
    return b;
}
