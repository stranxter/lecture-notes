#include <iostream>
#include <assert.h>
#include <math.h>

#include "block.h"

using namespace std;

BlockExpression::BlockExpression (){}

void BlockExpression::addExpression (Expression *e)
{
	expressions.push_back (e);
}

void BlockExpression::print (ostream &out)
{
	out << getID () << "[label=\"BLOCK\"];" << endl;
	
	for (int i = 0; i < expressions.size(); i++)
	{
       out << getID () 
           << "->" 
           << expressions[i]->getID() << endl;

       expressions[i]->print(out);

    }

}

Value* BlockExpression::execute ()
{
	Value *res;

	for (int i = 0; i < expressions.size(); i++)
		res = expressions[i]->execute();

	return res;
}  

