#ifndef __VARS_H
#define __VARS_H

#include <iostream>
#include <vector>
#include "expression.h"

using namespace std;

class VarExpression : public Expression
{
private:
	string varName;

public:
	VarExpression (string _vn);

	void print (ostream &out);

	Value* execute ();

};


class SetExpression : public Expression
{
private:
	string varName;
	Expression *newVal;
public:

	SetExpression (string var, Expression *nv);
	~SetExpression();

	void print (ostream &out);

	Value* execute ();


};



#endif
