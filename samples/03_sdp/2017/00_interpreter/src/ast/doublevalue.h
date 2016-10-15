#ifndef __DOUBLEVALUE_H
#define __DOUBLEVALUE_H

#include <iostream>
#include "value.h"

class DoubleValue : public Value{

private:
	double v;
public:
	DoubleValue (double _v);
	virtual void print (ostream &out);

    Value* plus (Value *other);
    Value* minus (Value *other);

    Value* power (Value *other);

    int getType ();

	virtual bool toNativeBool ();
	virtual Value* clone ();

	bool equals (Value*);


};

#endif