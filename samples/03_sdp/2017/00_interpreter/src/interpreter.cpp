#include <iostream>

using namespace std;

#include "ast/ast.h"
#include "lex/tokenizer.h"
#include "parser/parser.h"
#include "ast/vars.h"
#include "runtime/memory.h"

int main ()
{


	ProgramMemory::InitProgramMemory();

	Tokenizer  tokenizer (cin);

	Expression *program = Parser::parse (tokenizer);

	Value* programResult = program->execute();

	ProgramMemory::DeleteProgramMemory();

	Expression::printTree (program,cerr);

	delete programResult;
	delete program;
}