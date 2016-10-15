#include <iostream>
#include <assert.h>
#include <string>
#include <math.h>


using namespace std;

#include "memory.h"
#include "../ast/vars.h"


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
