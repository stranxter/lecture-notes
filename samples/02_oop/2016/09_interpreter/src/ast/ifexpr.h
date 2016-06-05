#ifndef __IFEXPR_H
#define __IFEXPR_H

#include <iostream>
#include "expression.h"

using namespace std;


class IfExpr : public Expression
{
private:
	Expression *conde, *thene, *elsee;
public:
	IfExpr (Expression *_c, 
		    Expression *_t,
		    Expression *_e);


	Value* execute ();

	void print (ostream &out);
};

#endif