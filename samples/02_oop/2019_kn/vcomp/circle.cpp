#include "sdlwrapper.h"
#include "circle.h"

Circle::Circle(int _x, int _y, int _r, const char *_s):Shape(_x,_y,_s),r(_r)
{

}

void Circle::draw()
{
    drawFile (x,y,r*2,r*2,"images/circle.png");
}

void Circle::set_r(int _r)
{
    r=_r;
}

int Circle::get_r()
{
    return r;
}

Shape* Circle::clone ()
{
    return new Circle (*this);
}

void Circle::serialize(std::ostream &out)
{
    out << "Circle "
        << x
        << " "
        << y
        << " "
        << r
        << " "
        << strlen(text)
        << " "
        << text
        << "\n";
}
