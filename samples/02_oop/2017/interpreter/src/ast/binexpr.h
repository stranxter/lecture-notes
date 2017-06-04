#ifndef __BINEXPR__H
#define __BINEXPR__H

#include "expression.h"

class BinExpr : public Expression
{
private:
  char op;
  Expression *left;
  Expression *right;
public:
  BinExpr (Expression *_left, char _op, Expression *_right);

  void accept (Visitor*);

  Expression* getLeft();
  Expression* getRight();
  char getOperator();
};

#endif
