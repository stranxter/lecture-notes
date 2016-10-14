#include <iostream>
#include <assert.h>
#include <math.h>

#include "ifexpr.h"

using namespace std;


IfExpr::IfExpr (Expression *_c, 
	    Expression *_t,
	    Expression *_e): conde(_c), thene (_t), elsee (_e){};

IfExpr::~IfExpr()
{
	delete conde;
	delete thene;
	delete elsee;
}


Value* IfExpr::execute ()
{
	Value* conditionResult = conde->execute();
	Value* result;
	if (conditionResult->toNativeBool())
	{
		result = thene->execute();
	}
	else
	{
		result = elsee->execute();
	}
	delete conditionResult;
	return result;
}

void IfExpr::print (ostream &out)
{
	out << getID () << "[label=\"IF\"];" << endl;
	out << getID () << "->" << conde->getID() << "[style=dashed];" << endl;
	out << getID () << "->" << thene->getID() << ";" << endl;
	out << getID () << "->" << elsee->getID() << ";" << endl;

	out << thene->getID () << "[shape=\"box\"];" << endl;


	conde->print (out);
	thene->print (out);
	elsee->print (out);
}
