#ifndef __IFEXPR__
#define __IFEXPR__

#include "expression.h"

class IfExpr : public Expression
{
private:
  Expression *condExpr;
  Expression *thenExpr;
  Expression *elseExpr;
public:
  IfExpr (Expression *_cond, Expression *_then, Expression *_else);

  void accept (Visitor*);

  Expression* getCondition();
  Expression* getThenExpr();
  Expression* getElseExpr();

};

#endif
