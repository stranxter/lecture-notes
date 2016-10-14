#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include <iostream>
#include "expression.h"

using namespace std;

class DefineFunctionExpression : public Expression
{
private:
	string fnName;
	vector<string> formalParameters;
	Expression *body;


public:
	DefineFunctionExpression (string _fn);
	~DefineFunctionExpression ();

	void addFormalParameter (string paramName);
	void addBody (Expression*);

	void print (ostream &out);

	Value* execute ();

	friend class CallFunctionExpression;

};


class CallFunctionExpression : public Expression
{
private:
	string fnName;
	vector<Expression*> arguments;

public:

	CallFunctionExpression (string fnName);
	~CallFunctionExpression ();

	void addArgument (Expression *);

	void print (ostream &out);

	Value* execute ();



};

#endif
