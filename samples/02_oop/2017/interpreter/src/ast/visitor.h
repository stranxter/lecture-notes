#ifndef __VISITOR_H
#define __VISITOR_H

#include "ast.h"

class Visitor
{
public:
  virtual void visit (ConstExpr*);
  virtual void visit (BinExpr*);
  virtual void visit (IfExpr*);
};


#endif
