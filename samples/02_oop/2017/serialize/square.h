#ifndef __SQUARE_H
#define __SQUARE_H

#include "figure.h"

class Square : public Figure
{
private:
  double x,y,a,tga;

public:

  Square (double _x, double _y, double _a, double _tga);

  double surface ();

  double perim ();

  void save (std::ostream &out);
  void load (std::istream &in);
  Figure* spawn ();

private:
  static int dummy;
  static int registerClass ();


};
#endif
