#include "binexpr.h"
#include <cassert>

BinExpr::BinExpr (Expression *_left,
                  char _op,
                  Expression *_right):left(_left),op(_op),right(_right){}

double BinExpr::value ()
{
  switch (op)
  {
    case '+' : return left->value() + right->value();
    case '-' : return left->value() - right->value();
    case '*' : return left->value() * right->value();
  }

  assert (false);
  return 0;

}
