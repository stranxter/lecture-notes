#include "linear.h"

Linear::Linear (double _a,double _b):a(_a),b(_b){}

double Linear::value (double x)
{
  return a*x + b;
}
