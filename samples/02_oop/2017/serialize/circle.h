#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
private:
  double x,y,r;
public:
  Circle (double _x, double _y, double _r);
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
