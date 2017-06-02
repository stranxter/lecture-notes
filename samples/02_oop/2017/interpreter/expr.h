#ifndef __CONST_H
#define __CONST_H

#include "expression.h"

class ConstExpr : public Expression
{
private:
  double val;
public:
  virtual double value () = 0;

};

#endif
