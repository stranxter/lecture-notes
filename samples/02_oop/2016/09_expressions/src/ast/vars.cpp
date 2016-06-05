#include <iostream>
#include <assert.h>
#include <map>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#include "vars.h"

map<string,Value*> AllValues;


VarExpression::VarExpression (string _vn):varName(_vn){}

void VarExpression::print (ostream &out)
{
	out << getID () << "[label=\"" << varName << "\",shape=box];" << endl;
	
}

Value* VarExpression::execute ()
{
	return AllValues[varName];
}



SetExpression::SetExpression (string var, Expression *nv): varName(var), newVal (nv){}

void SetExpression::print (ostream &out)
{
	out << getID () << "[label=\"" << varName << ":=\"];" << endl;
	out << getID () << "->" << newVal->getID() << endl;

	newVal->print (out);

}

Value* SetExpression::execute ()
{
	AllValues[varName] = newVal->execute();
	return AllValues[varName];
}


