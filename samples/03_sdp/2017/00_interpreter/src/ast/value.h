#ifndef __VALUE_H
#define __VALUE_H

#define DOUBLE_VALUE 0

#include <iostream>
using namespace std;

class Value
{
public:
	virtual void print (ostream &out) = 0;
	
	virtual Value* plus (Value *other);
	virtual Value* minus (Value *other);
	virtual Value* power (Value *other);
	
	virtual bool equals (Value*) = 0;

	virtual bool toNativeBool ();


	virtual int getType () = 0;

};



#endif