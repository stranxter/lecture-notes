#include <iostream>
#include <assert.h>
#include <math.h>

#include "constant.h"

Constant::Constant (Value *v):myValue (v){}

Value* Constant::execute ()
{
	return myValue;
}

void Constant::print (ostream &out)
{
	out << getID() << "[label=\"const:";
    myValue->print(out);
    out << "\"];" << endl;
}
