#ifndef __PARSER_H
#define __PARSER_H

#include <string>

using namespace std;

#include "../ast/expression.h"
#include "../lex/tokenizer.h"

class Parser
{
public:
	
	static Expression* parse (Tokenizer& t);

private:

	static Expression* parseNumber (Tokenizer& t);
	static Expression* parseIf (Tokenizer& t);
	static Expression* parseBlock (Tokenizer& t);
	static Expression* parseAssign (Tokenizer& t);
	static Expression* parseVariable (Tokenizer& t);
	static Expression* parseArithExpr (Tokenizer& t);
	static Expression* parsePrintLn (Tokenizer& t);

};


#endif
