#ifndef __PARSER_H
#define __PARSER_H

#include "expression.h"
#include "tokenizer.h"
#include <iostream>

class Parser
{

private:

  static Expression* parseExpression (Tokenizer&);
  static Expression* parseBinExpr (Tokenizer&);
  static Expression* parseIfExpr (Tokenizer&);
  static Expression* parseConst (Tokenizer&);


public:
  static Expression* parse (std::istream&);
};

#endif
