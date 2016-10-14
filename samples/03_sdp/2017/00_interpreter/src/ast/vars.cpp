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
	//изтриваме всички стойности от последната стекова рамка и я махаме
	for(auto &entry : AllValuesStack.back())
	{
		delete entry.second;
	}
	AllValuesStack.pop_back();	
}

void ProgramMemory::DeleteProgramMemory()
{
	popStackFrame();
}

vector<map<string,Value*> > ProgramMemory::AllValuesStack;


VarExpression::VarExpression (string _vn):varName(_vn){}

void VarExpression::print (ostream &out)
{
	out << getID () << "[label=\"" << varName << "\",shape=box];" << endl;
	
}

Value* VarExpression::execute ()
{
	return ProgramMemory::AllValuesStack.back()[varName]->clone();
}



SetExpression::SetExpression (string var, Expression *nv): varName(var), newVal (nv){}

SetExpression::~SetExpression()
{
	delete newVal;
}

void SetExpression::print (ostream &out)
{
	out << getID () << "[label=\"" << varName << ":=\"];" << endl;
	out << getID () << "->" << newVal->getID() << endl;

	newVal->print (out);

}

Value* SetExpression::execute ()
{
	Value* value = newVal->execute();
	//ако променливата вече съществува, т.е. я презаписваме, трием старата стойност
	if(ProgramMemory::AllValuesStack.back().find(varName) != ProgramMemory::AllValuesStack.back().end())
	{
		delete ProgramMemory::AllValuesStack.back()[varName];
	}
	ProgramMemory::AllValuesStack.back()[varName] = value->clone();
	return value;
}


