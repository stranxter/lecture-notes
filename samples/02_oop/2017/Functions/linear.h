#ifndef __LINEAR_H
#define __LINEAR_H

#include "functions.h"

class Linear : public Function
{
private:
  double a;
  double b;

public:
  Linear (double,double);
  double value (double);

};

#endif
