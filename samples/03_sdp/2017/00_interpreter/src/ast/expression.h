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

	//виртуален деструктор, защото винаги трием през Expression*
	virtual ~Expression () {}; 

	int getID ();

	/*  Установяваме норма - ако някой получи указател от извикването на execute,
		то той става собственик на обекта, към който сочи указателя и следователно
		е длъжен да го изтрие след като го използва.

		Освен това, всеки клас, който приема през конструктора си указатели към обекти,
		става техен собственик и е длъжен да ги изтрие.
	*/
	virtual Value* execute () = 0;

	virtual void print (ostream &) = 0;

	static void printTree (Expression *e, ostream &out);

};


#endif
