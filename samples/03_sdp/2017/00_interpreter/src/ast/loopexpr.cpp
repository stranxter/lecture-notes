#include <iostream>
#include <assert.h>
#include <math.h>

#include "loopexpr.h"
#include "vars.h"
#include "constant.h"

using namespace std;


LoopExpr::LoopExpr (string _cv,
			      Expression *_frome, 
			      Expression *_toe,
			      Expression *_stepe,
			      Expression *_bodye):frome(_frome),toe(_toe),stepe(_stepe),bodye(_bodye),controlVar(_cv){};



Value* LoopExpr::execute ()
{

	Value *control = frome->execute();

	do { 
	
		SetExpression *set = new SetExpression (controlVar,new Constant (control));
		set->execute();

		bodye->execute();
		control = control->plus(stepe->execute());

	} while (!control->equals (toe->execute()));

	SetExpression *set = new SetExpression (controlVar,new Constant (control));
	set->execute();

	Value *result = bodye->execute();


	return result;
		 
}



void LoopExpr::print (ostream &out)
{
	out << getID () << "[label=\"LOOP:" << controlVar << "\"];" << endl;
	out << getID () << "->" << frome->getID() << ";" << endl;
	out << getID () << "->" << toe->getID() << ";" << endl;
	out << getID () << "->" << stepe->getID() << ";" << endl;
	out << getID () << "->" << bodye->getID() << ";" << endl;


	frome->print (out);
	toe->print (out);
	stepe->print (out);
	bodye->print (out);
}
