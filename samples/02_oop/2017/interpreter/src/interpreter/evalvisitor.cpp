#include "evalvisitor.h"
#include <cassert>

void EvalVisitor::visit (ConstExpr *ce)
{
  computedValue = ce->getDoubleVal();
}
void EvalVisitor::visit (BinExpr *be)
{

  EvalVisitor leftVisitor, rightVisitor;

  be->getLeft()->accept (&leftVisitor);
  be->getRight()->accept (&rightVisitor);

  switch (be->getOperator())
  {
    case '+' : computedValue =
                  leftVisitor.getComputedValue() +
                  rightVisitor.getComputedValue();
               break;
    case '-' : computedValue =
                  leftVisitor.getComputedValue() -
                  rightVisitor.getComputedValue();
               break;
    case '*' : computedValue =
                  leftVisitor.getComputedValue() *
                  rightVisitor.getComputedValue();
               break;

    default: assert (false);
  }

}
void EvalVisitor::visit (IfExpr *ie)
{
  EvalVisitor condVisitor, resultVisitor;
  ie->getCondition()->accept (&condVisitor);

  if (condVisitor.getComputedValue())
  {
    ie->getThenExpr()->accept (&resultVisitor);
  } else {
    ie->getElseExpr()->accept (&resultVisitor);
  }

  computedValue = resultVisitor.getComputedValue();
}
double EvalVisitor::getComputedValue ()
{
  return computedValue;
}
