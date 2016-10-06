#include <iostream>

using namespace std;

#include "ast/ast.h"
#include "lex/tokenizer.h"
#include "parser/parser.h"

int main ()
{


	Tokenizer  tokenizer (cin);

	Expression *program = Parser::parse (tokenizer);

	program->execute();

	Expression::printTree (program,cerr);


}