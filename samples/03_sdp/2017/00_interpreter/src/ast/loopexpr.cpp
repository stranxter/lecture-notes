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

LoopExpr::~LoopExpr()
{
	delete frome;
	delete toe;
	delete stepe;
	delete bodye;
}

Value* LoopExpr::execute()
{
	Value* garbage;

	Value *control = frome->execute();
	Value* to = toe->execute();

	while(!control->equals(to))
	{
		setControlVariableTo(control);
		executeBodyAndDeleteGarbage();

		garbage = control;
		control = makeStep(control);
		delete garbage;
	}

	setControlVariableTo(control);
	delete control;
	delete to;
	return bodye->execute();

}

void LoopExpr::setControlVariableTo(Value* value)
{
	SetExpression *set = new SetExpression(controlVar, new Constant(value->clone()));
	Value* garbage = set->execute();
	delete garbage;
	delete set;	
}

void LoopExpr::executeBodyAndDeleteGarbage()
{
	Value* garbage = bodye->execute();
	delete garbage;
}

Value* LoopExpr::makeStep(Value* currentControlValue)
{
	Value* stepValue = stepe->execute();
	Value* newControlValue = currentControlValue->plus(stepValue);
	delete stepValue;
	return newControlValue;
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
