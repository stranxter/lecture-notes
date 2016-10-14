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

Expression* Parser::parseLoop (Tokenizer& t)
{
	Token token = t.getToken();//remove "loop"
	
	string varName = t.getToken().val_str;

	//read "from"
	assert (t.getToken().type == Token::KW_FROM);
	Expression *from_expr = Parser::parse(t);

	//read "to"
	assert (t.getToken().type == Token::KW_TO);
	Expression *to_expr = Parser::parse(t);

	//read "step"
	assert (t.getToken().type == Token::KW_STEP);
	Expression *step_expr = Parser::parse(t);

	//read "do"
	assert (t.getToken().type == Token::KW_DO);
	Expression *do_expr = Parser::parse(t);

	return new LoopExpr (varName,from_expr,to_expr,step_expr,do_expr);

}

Expression* Parser::parseDefineFunction (Tokenizer& t)
{
	Token token = t.getToken();//remove "define"
	
	//read function name
	string fnName = t.getToken().val_str;

	DefineFunctionExpression *define = new DefineFunctionExpression(fnName);

	//read parameters
	string param;
	while (t.peekToken().type != Token::KW_DO)
	{
		param = t.getToken().val_str;
		define->addFormalParameter (param);
	}

	//read "do"
	assert (t.getToken().type == Token::KW_DO);

	//read body
	Expression *body = Parser::parse (t);

	define->addBody (body);

	return define;
}


Expression* Parser::parseCallFunction (Tokenizer& t)
{
	Token token = t.getToken();//remove "call"
	
	//read function name
	string fnName = t.getToken().val_str;

	CallFunctionExpression *call = new CallFunctionExpression(fnName);

	//read arguments
	Expression* argument;
	while (t.peekToken().type != Token::KW_DOT)
	{
		argument = Parser::parse (t);
		call->addArgument (argument);
	}

	//read "."
	assert (t.getToken().type == Token::KW_DOT);

	return call;
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

		case Token::KW_LOOP: return Parser::parseLoop (t);
	
		case Token::KW_DEFINE: return Parser::parseDefineFunction (t);

		case Token::KW_CALL: return Parser::parseCallFunction (t);

		case Token::UNKNOWN: return Parser::parseVariable (t);
	
		case Token::ARITH_OPER: return Parser::parseArithExpr (t);

		case Token::KW_PRINTLINE: return Parser::parsePrintLn (t);
	}

	assert (false);
	return NULL;
}


