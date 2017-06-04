#include <cassert>
#include "visitor.h"

void Visitor::visit (ConstExpr*)
{
  assert (false);
}
void Visitor::visit (BinExpr*)
{
  assert (false);
}
void Visitor::visit (IfExpr*)
{
  assert (false);
}
