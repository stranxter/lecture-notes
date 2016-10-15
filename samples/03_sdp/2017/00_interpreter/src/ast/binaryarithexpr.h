#ifndef __BINARREXPR_H
#define __BINARREXPR_H

#include <iostream>
#include "value.h"
#include "expression.h"

using namespace std;

class BinaryArithmOper : public Expression
//5+6
{
private:
	Expression *e1; Expression *e2;
	char op;
public:
	BinaryArithmOper 
	      (Expression *_e1, 
	       Expression *_e2,
	       char _op);
	~BinaryArithmOper();
	Value* execute ();
	void print (ostream &out);
};

#endif
