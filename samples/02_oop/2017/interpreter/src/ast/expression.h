#ifndef __EXPR_H
#define __EXPR_H

class Visitor;

class Expression
{
public:
  virtual void accept (Visitor*)=0;

};

#endif
