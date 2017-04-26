#ifndef __CONSTANT_H
#define __CONSTANT_H

#include "functions.h"

class Constant : public Function
{
private:
  double c;

public:
  Constant (double _c);
  double value (double);

};

#endif
