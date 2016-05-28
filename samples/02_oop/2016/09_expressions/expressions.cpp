#include <iostream>
#include <assert.h>

using namespace std;

#define DOUBLE_VALUE 0

class Value
{
public:
	virtual void print (ostream &out) = 0;
	virtual Value *plus (Value *other) 
	{
		assert (false);
		return NULL;
	};
	virtual int getType () = 0;

};

class Expression
{
public:

	virtual Value* execute () = 0;

};

class Constant : public Expression
{

private:
	Value *myValue;
public:

	Constant (Value *v):myValue (v){}

	Value* execute ()
	{
		return myValue;
	}
};

class DoubleValue : public Value{

private:
	double v;
public:
	DoubleValue (double _v):v(_v){}
	virtual void print (ostream &out) 
	{
		out << "I am a double value: " 
		    << v 
		    << endl;
	}

    Value *plus (Value *other)
    {
    	assert (other->getType() == DOUBLE_VALUE);
    	return new DoubleValue (v + ((DoubleValue*)other)->v);
    } 

    int getType ()
    {
    	return DOUBLE_VALUE;
    }




};


class PlusOperator : public Expression
//5+6
{
private:
	Expression *e1; Expression *e2;
public:
	PlusOperator (Expression *_e1, Expression *_e2):e1(_e1),e2(_e2){}
	Value* execute ()
	{
		//return e1->execute() -> plus (e2->execute());

		Value *valueOfe1 = e1->execute();
		Value *valueOfe2 = e2->execute();

		return valueOfe1->plus (valueOfe2);
	}


};

int main ()
{

	DoubleValue v5 (5), v6 (6);
	Constant c1 (&v5), c2 (&v6);
	PlusOperator p1 (&c1,&c2);


	c1.execute ()->print(cout);
	p1.execute ()->print (cout);

}