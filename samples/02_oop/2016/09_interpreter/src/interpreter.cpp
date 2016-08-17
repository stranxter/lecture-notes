#include <iostream>

using namespace std;

#include "ast/ast.h"
#include "lex/tokenizer.h"
#include "parser/parser.h"

int main ()
{


	Tokenizer  tokenizer (cin);

	Expression *program = Parser::parse (tokenizer);

	cout << "Program value=";
	program->execute()->print(cout);
	cout << endl;

	Expression::printTree (program,cerr);


}