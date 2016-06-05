#include <iostream>
#include <assert.h>
#include <math.h>

#include "expression.h"

using namespace std;

Expression::Expression () {myID = maxID++;}

int Expression::getID () {return myID;}

void Expression::printTree (Expression *e, ostream &out)
{
	out << "digraph G{" << endl;
	e->print (out);
	out << "}" << endl;
}

int Expression::maxID = 0;