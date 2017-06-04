#include "ast.h"
#include "visitor.h"

IfExpr::IfExpr (Expression *_cond,
                Expression *_then,
                Expression *_else):condExpr(_cond),thenExpr(_then),elseExpr(_else){}

void IfExpr::accept (Visitor *visitor)
{
  visitor->visit (this);
}

Expression* IfExpr::getCondition()
{
  return condExpr;
}
Expression* IfExpr::getThenExpr()
{
  return thenExpr;
}
Expression* IfExpr::getElseExpr()
{
  return elseExpr;
}
