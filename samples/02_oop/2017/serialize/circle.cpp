#include "circle.h"

Circle::Circle (double _x, double _y, double _r):x(_x),y(_y),r(_r)
{

}

double Circle::surface ()
{
  return 3.14*r*r;
}

double Circle::perim ()
{
  return 2 * 3.14 * r;
}

void Circle::save (std::ostream &out)
{
  out << "circle " << x << " " << y << " " << r << " ";
}
