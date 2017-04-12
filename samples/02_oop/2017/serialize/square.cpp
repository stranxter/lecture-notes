#include "square.h"

Square::Square (double _x, double _y, double _a, double _tga)
               :x(_x),y(_y),a(_a),tga(_tga)
{

}

double Square::surface ()
{
  return a*a;
}

double Square::perim ()
{
  return 4*a;
}

void Square::save (std::ostream &out)
{
  out << "square " << x << " " << y << " " << a << " " << tga << " ";
}
