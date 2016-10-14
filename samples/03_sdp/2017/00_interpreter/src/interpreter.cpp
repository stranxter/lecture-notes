#include <iostream>

using namespace std;

#include "ast/ast.h"
#include "lex/tokenizer.h"
#include "parser/parser.h"
#include "ast/vars.h"

int main ()
{


	ProgramMemory::InitProgramMemory();

	Tokenizer  tokenizer (cin);

	Expression *program = Parser::parse (tokenizer);

	program->execute();

	Expression::printTree (program,cerr);


}