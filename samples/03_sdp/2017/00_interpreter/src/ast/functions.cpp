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

	//Стойностите на фактическите параметри се 
	//изчисляват преди да се създаде новата стекова рамка,
	//тък като съответните изрази, задаващи фактическите параметри,
	//може да ползват променливи и следователно имат нужна от
	//"тяхната си" стекова рамка, а не от новата.
	//Пример: call fn i .
	//Това "i" е в стековата рамка, в която се изчислява 
	//call, а не в тази на изпълнението на fn
	//Така изчислените стойности се записват в константи
	vector<Constant*> argumentValues;
	for (int i = 0; i < arguments.size(); i++)
		argumentValues.push_back(new Constant (arguments[i]->execute()));

	//създаваме нова стекова рамка за изпълнението на функцията
	ProgramMemory::pushNewStackFrame();

	DefineFunctionExpression *def = AllFunctions[fnName];
	assert (def->formalParameters.size() == argumentValues.size());

	//в новата стекова рамка присвояваме на 
	//формалните параметри стойностите на фактическите
	//параметри
	for (int i = 0; i < def->formalParameters.size(); i++)
	{
		SetExpression *set 
		   = new SetExpression (def->formalParameters[i],
		   	                    argumentValues[i]);
		set->execute();
	}

	//изчисляваме тялото на функцията
	Value *res = def->body->execute();

	//унищожаваме стековата рамка
	ProgramMemory::popStackFrame();

	return res;

}


