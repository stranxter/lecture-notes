#include <iostream>
#include <assert.h>
#include <map>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#include "functions.h"
#include "constant.h"
#include "doublevalue.h"
#include "vars.h"

map<string,DefineFunctionExpression*> AllFunctions;

DefineFunctionExpression::DefineFunctionExpression (string _fn):fnName(_fn){}

void DefineFunctionExpression::print (ostream &out)
{
	out << getID () << "[label=\"DEFINE:" << fnName << "\"];" << endl;
	out << getID () << "->" << body->getID() << ";" << endl;

	body->print (out);
	
}

Value* DefineFunctionExpression::execute ()
{
	AllFunctions[fnName] = this;
	return new DoubleValue (0);
}

void DefineFunctionExpression::addFormalParameter (string paramName)
{
	formalParameters.push_back (paramName);
}
void DefineFunctionExpression::addBody (Expression* b)
{
 body = b;
}


CallFunctionExpression::CallFunctionExpression (string _fn): fnName(_fn){}

void CallFunctionExpression::print (ostream &out)
{
	out << getID () << "[label=\"call:" << fnName << "\"];" << endl;

	//TODO!

}

void CallFunctionExpression::addArgument (Expression *arg)
{
	arguments.push_back (arg);
}

Value* CallFunctionExpression::execute ()
{

	ProgramMemory::pushNewStackFrame();

	DefineFunctionExpression *def = AllFunctions[fnName];


	assert (def->formalParameters.size() == arguments.size());

	for (int i = 0; i < def->formalParameters.size(); i++)
	{
		SetExpression *set 
		   = new SetExpression (def->formalParameters[i],
		   	                    arguments[i]);
		set->execute();
	}


	Value *res = def->body->execute();

	ProgramMemory::popStackFrame();

	return res;

}


