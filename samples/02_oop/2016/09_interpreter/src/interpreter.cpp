#include <iostream>

using namespace std;

#include "ast/ast.h"
#include "lex/tokenizer.h"

int main ()
{

	IfExpr  
	  *ie1 = new IfExpr 
	    (new BinaryArithmOper (new Constant (new DoubleValue (-2)),
	    				       new Constant (new DoubleValue (2)),
	    				       '+'),
	     new Constant (new DoubleValue (3)),
	     new Constant (new DoubleValue (4)));

	SetExpression *se = new SetExpression ("myFirstVar",ie1);


	BinaryArithmOper *varSample =
	 new BinaryArithmOper (new Constant (new DoubleValue (1)),
			               new VarExpression ("myFirstVar"),
			               '+');

	BlockExpression *be = new BlockExpression ();
	be->addExpression (se);
	be->addExpression (varSample);


	Expression::printTree (be, cerr);

	be->execute()->print (cout);

	cout << endl;



	Tokenizer  tokenizer (cin);

	while (tokenizer.moreTokens())
	{
		Token t = tokenizer.getToken ();

		cout << t.type << ":" << t.val_str << endl;
	}



}