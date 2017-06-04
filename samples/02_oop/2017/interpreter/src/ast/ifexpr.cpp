#include "ifexpr.h"

IfExpr::IfExpr (Expression *_cond,
                Expression *_then,
                Expression *_else):condExpr(_cond),thenExpr(_then),elseExpr(_else){}

double IfExpr::value ()
{
  if (condExpr->value())
  {
    return thenExpr->value();
  }

  return elseExpr->value();
}
