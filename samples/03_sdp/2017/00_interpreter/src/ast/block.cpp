#include <iostream>
#include <assert.h>
#include <math.h>

#include "block.h"

using namespace std;

BlockExpression::BlockExpression (){}

BlockExpression::~BlockExpression ()
{
	for (int i = 0; i < expressions.size(); i++)
		delete expressions[i];
}

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

	for (int i = 0; i < expressions.size() - 1; i++)
	{
		res = expressions[i]->execute();
		delete res;
	}
	return expressions.back()->execute();
}  

