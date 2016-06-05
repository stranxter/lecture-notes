#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <iostream>
#include "value.h"

using namespace std;

class Expression
{
private:
	//брои колко инстанции от Expression 
	//са направени
	static int maxID;
	//поредният номер на тази инстанция
	int myID;

public:
	Expression (); 

	int getID ();

	virtual Value* execute () = 0;
	virtual void print (ostream &) = 0;

	static void printTree (Expression *e, ostream &out);

};


#endif
