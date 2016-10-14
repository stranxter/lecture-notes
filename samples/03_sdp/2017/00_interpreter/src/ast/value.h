#ifndef __VALUE_H
#define __VALUE_H

#define DOUBLE_VALUE 0

#include <iostream>
using namespace std;

class Value
{
public:
	virtual void print (ostream &out) = 0;
	
	/*  Ако някой извика функция на Value, която връща като резултат Value*,
		също както при Expression::execute, той става собственик на обекта и
		е длъжен да го изтрие.
	*/	
	virtual Value* plus (Value *other);
	virtual Value* minus (Value *other);
	virtual Value* power (Value *other);
	//нова функция за клониране
	virtual Value* clone () = 0;
	
	virtual bool equals (Value*) = 0;


	virtual bool toNativeBool ();


	virtual int getType () = 0;

};



#endif