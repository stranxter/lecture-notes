#ifndef __EVALVISITOR_H
#define __EVALVISITOR_H

#include "../ast/visitor.h"
#include "../ast/ast.h"

class EvalVisitor : public Visitor
{
private:
  double computedValue;
public:
  void visit (ConstExpr*);
  void visit (BinExpr*);
  void visit (IfExpr*);

  double getComputedValue ();
};


#endif
