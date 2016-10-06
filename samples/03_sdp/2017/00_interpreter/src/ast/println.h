#ifndef __PRINTLN_H
#define __PRINTLN_H

#include <iostream>
#include <vector>

#include "expression.h"

using namespace std;

class PrintLnExpression : public Expression
{
private:
  vector<Expression*> expressions;
public:
  PrintLnExpression ();

  void addExpression (Expression *e);

  void print (ostream &out);

  Value* execute ();

};

#endif