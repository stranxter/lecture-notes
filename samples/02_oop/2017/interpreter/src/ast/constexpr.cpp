#include "ast.h"
#include "visitor.h"

ConstExpr::ConstExpr (double _val):val(_val)
{

}

void ConstExpr::accept (Visitor *visitor)
{
  visitor->visit(this);
}
double ConstExpr::getDoubleVal ()
{
  return val;
}
