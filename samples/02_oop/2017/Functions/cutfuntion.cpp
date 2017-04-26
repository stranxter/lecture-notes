#include "cutfunction.h"

CutFunction::CutFunction (Function *_f):f(_f){}

double CutFunction::value (double x)
{
  double y = f->value (x);
  if (y >= 0)
    return y;
  return 0;
}
