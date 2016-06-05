#ifndef __CONSTANT_H
#define __CONSTANT_H

#include <iostream>

#include "expression.h"

using namespace std;

class Constant : public Expression
{

private:
	Value *myValue;
public:

	Constant (Value *v);

	Value* execute ();

	void print (ostream &out);
};

#endif

