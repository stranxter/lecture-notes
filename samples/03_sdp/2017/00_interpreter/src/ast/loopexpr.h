#ifndef __LOOPEXPR_H
#define __LOOPEXPR_H

#include <iostream>
#include "expression.h"

using namespace std;


class LoopExpr : public Expression
{
private:

	string controlVar;
	Expression *frome, *toe, *stepe;
	Expression *bodye;

	void setControlVariableTo(Value* value);
	Value* makeStep(Value* currentControlValue);
	void executeBodyAndDeleteGarbage();

public:
	LoopExpr (string _cv,
		      Expression *_frome, 
		      Expression *_toe,
		      Expression *_stepe,
		      Expression *_bodye);

	~LoopExpr();


	Value* execute ();

	void print (ostream &out);
};

#endif