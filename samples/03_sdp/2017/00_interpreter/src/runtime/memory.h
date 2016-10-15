#ifndef __RUNTIME_H
#define __RUNTIME_H

#include <iostream>
#include <vector>
#include <map>
#include "../ast/expression.h"


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
