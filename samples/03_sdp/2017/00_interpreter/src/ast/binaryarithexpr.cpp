#include <iostream>
#include <assert.h>
#include <math.h>

#include "binaryarithexpr.h"
#include "doublevalue.h"

using namespace std;


BinaryArithmOper::BinaryArithmOper 
	      (Expression *_e1, 
	       Expression *_e2,
	       char _op):e1(_e1),e2(_e2),op(_op){}

Value* BinaryArithmOper::BinaryArithmOper::execute ()
{
	//return e1->execute() -> plus (e2->execute());

	Value *valueOfe1 = e1->execute();
	Value *valueOfe2 = e2->execute();

	switch (op)
	{
		case '+': return valueOfe1->plus (valueOfe2); 
		case '^': return valueOfe1->power (valueOfe2);
		case '-': return valueOfe1->minus (valueOfe2);


	}

	assert (false);
	return new DoubleValue (0);
}

void BinaryArithmOper::print (ostream &out)
{
	out << getID () << "[label=\"" << op << "\"];" << endl;
	out << getID () << "->" << e1->getID() << ";" << endl;
	out << getID () << "->" << e2->getID() << "[style=\"dashed\"];" << endl;

	e1->print (out);
	e2->print (out);
}
