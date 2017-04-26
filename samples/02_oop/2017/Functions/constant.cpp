#include "constant.h"

Constant::Constant (double _c):c(_c){}

double Constant::value (double x)
{
  return c;
}
