#include "constexpr.h"

double ConstExpr::value ()
{
  return val;
}

ConstExpr::ConstExpr (double _val):val(_val)
{

}
