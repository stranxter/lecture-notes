#include <iostream>
#include <assert.h>
#include <math.h>

#include "constant.h"

Constant::Constant (Value *v):myValue (v){}

Constant::~Constant()
{
	delete myValue;
}

Value* Constant::execute ()
{
	//връщаме клонирана стойност, защото се очаква, който получи указателя да изтрие обекта
	return myValue->clone();
}

void Constant::print (ostream &out)
{
	out << getID() << "[label=\"const:";
    myValue->print(out);
    out << "\"];" << endl;
}
