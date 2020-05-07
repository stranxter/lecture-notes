
#include "rect.h"
#include "visitor.h"


Rectangle::Rectangle (double _x, double _y, double _a, double _b):x(_x),y(_y),a(_a),b(_b){}

double Rectangle::perim()
{
    return 2*a+2*b;
}

double Rectangle::surface()
{
    return a*b;
}

int Rectangle::nsides()
{
    return 4;
}

void Rectangle::save(std::ostream &out)
{
    out << "rect: " << x << " " << y << " " << a << " " << b << " "; 
}

void Rectangle::load(std::istream& in)
{
    in >> x >> y >> a >> b;
}

Figure *Rectangle::copy()
{
    return new Rectangle(*this);
}

double Rectangle::get_x()
{
    return x;
}
double Rectangle::get_y()
{
    return y;
}
double Rectangle::get_a()
{
    return a;
}
double Rectangle::get_b()
{
    return b;
}

void Rectangle::accept(Visitor *v)
{
    v->processRectangle(this);
}
