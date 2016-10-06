#include <iostream>
#include <assert.h>


using namespace std;

#include "parser.h"
#include "../ast/ast.h"


Expression* Parser::parseNumber (Tokenizer& t)
{
		
		Token token = t.getToken ();
		return new Constant 
		   (new DoubleValue (token.val_double));
}

Expression* Parser::parseIf (Tokenizer& t)
{
		Token token = t.getToken();//remove "if"
		
		Expression *cond = Parser::parse (t);
		assert (t.getToken().type == Token::KW_THEN);

		Expression *thenExpr = Parser::parse (t);
		assert (t.getToken().type == Token::KW_ELSE);

		Expression *elseExpr = Parser::parse (t);

		return new IfExpr (cond,thenExpr,elseExpr);
}

Expression* Parser::parseBlock (Tokenizer& t)
{

		Token token = t.getToken(); //remove "start"

		BlockExpression *result = new BlockExpression();

		while (t.peekToken().type != Token::KW_END)
		{
			Expression *e = Parser::parse(t);
			result->addExpression(e);

		}

		t.getToken(); //remove "end"

		return result;

}

Expression* Parser::parsePrintLn (Tokenizer& t)
{

		Token token = t.getToken(); //remove "printline"

		PrintLnExpression *result = new PrintLnExpression();

		while (t.peekToken().type != Token::KW_END)
		{
			Expression *e = Parser::parse(t);
			result->addExpression(e);

		}

		t.getToken(); //remove "end"

		return result;

}


Expression* Parser::parseAssign (Tokenizer& t)
{ //<Assignment> ::= assign <Variable> <Expression>
	
	Token token = t.getToken(); //rmeove "assign"

	Token vname = t.getToken();
	assert (vname.type == Token::UNKNOWN);

	Expression *e = Parser::parse (t);

	return new SetExpression (vname.val_str,e);

}

Expression* Parser::parseVariable (Tokenizer& t)
{//<Varible> ::= {a..z}+

	Token token = t.getToken();//remove variable name from input	
	return new VarExpression (token.val_str);

}

Expression* Parser::parseArithExpr (Tokenizer& t)
{//<ArithExpr> ::= <ArithOper> 
 //           <Expression> <Expression>

	Token token = t.getToken();//oper
	
	Expression *e1 = Parser::parse (t);
	Expression *e2 = Parser::parse (t);

	return new BinaryArithmOper (e1,e2,token.val_str[0]);

}

Expression* Parser::parse (Tokenizer& t)
{

	Token token = t.peekToken();

	switch (token.type)
	{
		case Token::NUMBER: return Parser::parseNumber (t);
	
		case Token::KW_IF: return Parser::parseIf (t);
	
		case Token::KW_START: return Parser::parseBlock (t);
	
		case Token::KW_ASSIGN: return Parser::parseAssign (t);
	
		case Token::UNKNOWN: return Parser::parseVariable (t);
	
		case Token::ARITH_OPER: return Parser::parseArithExpr (t);

		case Token::KW_PRINTLINE: return Parser::parsePrintLn (t);
	}

	assert (false);
	return NULL;
}
