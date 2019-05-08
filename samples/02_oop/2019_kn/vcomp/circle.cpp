#include "circle.h"
#include "visitor.h"

Circle::Circle(int _x, int _y, int _r, const char *_s):Shape(_x,_y,_s),r(_r)
{

}

void Circle::accept(Visitor *v)
{
    v->visitCircle (this);
}

void Circle::set_r(int _r)
{
    r=_r;
}

int Circle::get_r() const
{
    return r;
}

Shape* Circle::clone ()
{
    return new Circle (*this);
}

