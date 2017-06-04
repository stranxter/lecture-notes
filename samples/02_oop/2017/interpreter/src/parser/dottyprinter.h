#ifndef __DOTTYPRINT__
#define __DOTTYPRINT__

#include "../ast/ast.h"
#include "../ast/visitor.h"

class DottyPrinter : public Visitor
{
private:
  int dottyIdRoot;
  static int lastDottyId;
  std::ostream &output;
public:

  DottyPrinter (std::ostream&);

  void visit (ConstExpr*);
  void visit (BinExpr*);
  void visit (IfExpr*);

 void print (Expression*);

};


#endif
