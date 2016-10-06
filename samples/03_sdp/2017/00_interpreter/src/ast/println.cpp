#include <iostream>
#include <assert.h>
#include <math.h>

#include "println.h"

using namespace std;

PrintLnExpression::PrintLnExpression (){}

void PrintLnExpression::addExpression (Expression *e)
{
	expressions.push_back (e);
}

void PrintLnExpression::print (ostream &out)
{
	out << getID () << "[label=\"PRINTLN\"];" << endl;
	
	for (int i = 0; i < expressions.size(); i++)
	{
       out << getID () 
           << "->" 
           << expressions[i]->getID() << endl;

       expressions[i]->print(out);

    }

}

Value* PrintLnExpression::execute ()
{
	Value *res;

	for (int i = 0; i < expressions.size(); i++)
	{
		res = expressions[i]->execute();

		res->print (cout);
		cout << " ";

	}

    cout << endl;
	return res;

}  

