#include "square.h"
#include <cmath>

#include "visitor.h"
Square::Square(const Point& _p1, const Point& _p2):p1(_p1),p2(_p2)
{
}

void Square::accept(Visitor* v)
{
    v->visitSquare(this);
}

double Square::side() const
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Square::area() const
{
    //return side() * side();
    return 1;
}
double Square::perimeter() const
{
    return 4 * side();
}

void Square::load(std::istream& in)
{
    in >> p1.x >> p1.y >> p2.x >> p2.y;
}

Figure* Square::copy() const
{
    return new Square(p1, p2);
}

Point Square::getp1() const
{
    return p1;
}

Point Square::getp2() const
{
    return p2;
}