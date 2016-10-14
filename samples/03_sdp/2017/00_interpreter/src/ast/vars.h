#ifndef __VARS_H
#define __VARS_H

#include <iostream>
#include <vector>
#include <map>
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

class ProgramMemory
{
	public:
	static vector<map<string,Value*> > AllValuesStack;

	static void InitProgramMemory();
	static void pushNewStackFrame();
	static void popStackFrame();
	static void DeleteProgramMemory();
};


#endif
