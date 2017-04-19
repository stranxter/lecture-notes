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

void Square::load (std::istream &in)
{
  in >> x >> y >> a >> tga;
}


int Square::dummy = Square::registerClass();
int Square::registerClass ()
{
  Square::addFigureType ("square",new Square (0,0,0,0));
  return -1;
}

Figure* Square::spawn ()
{
  return new Square (0,0,0,0);  
}
