#ifndef __BLOCK_H
#define __BLOCK_H

#include <iostream>
#include <vector>

#include "expression.h"

using namespace std;

class BlockExpression : public Expression
{
private:
  vector<Expression*> expressions;
public:
  BlockExpression ();

  void addExpression (Expression *e);

  void print (ostream &out);

  Value* execute ();

};

#endif