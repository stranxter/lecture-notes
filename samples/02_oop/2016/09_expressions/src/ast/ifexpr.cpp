#include <iostream>
#include <assert.h>
#include <math.h>

#include "ifexpr.h"

using namespace std;


IfExpr::IfExpr (Expression *_c, 
	    Expression *_t,
	    Expression *_e): conde(_c), thene (_t), elsee (_e){};


Value* IfExpr::execute ()
{
	if (conde->execute()->toNativeBool())
		return thene->execute();
	return elsee->execute();
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
