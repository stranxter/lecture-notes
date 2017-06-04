#include "ast.h"
#include "visitor.h"

#include <cassert>

BinExpr::BinExpr (Expression *_left,
                  char _op,
                  Expression *_right):left(_left),op(_op),right(_right){}

void BinExpr::accept (Visitor *visitor)
{
  visitor->visit(this);
}
Expression* BinExpr::getLeft()
{
  return left;
}
Expression* BinExpr::getRight()
{
  return right;
}
char BinExpr::getOperator()
{
  return op;
}
