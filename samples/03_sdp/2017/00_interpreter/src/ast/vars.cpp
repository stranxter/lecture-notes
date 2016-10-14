#include <iostream>
#include <assert.h>
#include <string>
#include <math.h>


using namespace std;

#include "vars.h"


void ProgramMemory::InitProgramMemory()
{
	map<string,Value*> empty;
	AllValuesStack.push_back(empty);
}


void ProgramMemory::pushNewStackFrame()
{
	map<string,Value*> empty;
	AllValuesStack.push_back(empty);

}
void ProgramMemory::popStackFrame()
{
	AllValuesStack.pop_back();	
}


vector<map<string,Value*> > ProgramMemory::AllValuesStack;


VarExpression::VarExpression (string _vn):varName(_vn){}

void VarExpression::print (ostream &out)
{
	out << getID () << "[label=\"" << varName << "\",shape=box];" << endl;
	
}

Value* VarExpression::execute ()
{
	
	//cout << "READING VAR: " << varName << " STACK SIZE " << ProgramMemory::AllValuesStack.size() <<endl;

	Value* val = ProgramMemory::AllValuesStack.back()[varName];

	/*cout << "===DONE READING VAR: " << varName << " STACK SIZE " << ProgramMemory::AllValuesStack.size() <<endl;
	val->print (cout);
	cout << "\n===\n";*/


	return val;

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

	/*cout << "WRITING VAR: " << varName << " STACK SIZE " << ProgramMemory::AllValuesStack.size() <<endl;*/

	ProgramMemory::AllValuesStack.back()[varName] = newVal->execute();
	Value* val = ProgramMemory::AllValuesStack.back()[varName];

	/*cout << "===DONE WRITING VAR: " << varName << " STACK SIZE " << ProgramMemory::AllValuesStack.size() <<endl;
	val->print (cout);
	cout << "\n===\n";	*/

	return val;
}


