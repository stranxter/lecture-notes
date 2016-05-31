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

	//брои колко инстанции от Expression 
	//са направени
	static int maxID;
	//поредният номер на тази инстанция
	int myID;

public:
	Expression () 
	{myID = maxID++;}

	int getID (){return myID;}

	virtual Value* execute () = 0;
	virtual void print (ostream &) = 0;

	static void printTree (Expression *e, ostream &out)
	{
		out << "digraph G{" << endl;
		e->print (out);
		out << "}" << endl;
	}

};

int Expression::maxID = 0;


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

	void print (ostream &out)
	{
		out << getID() << "[label=\"const:";
	    myValue->print(out);
	    out << "\"];" << endl;
	}
};

class DoubleValue : public Value{

private:
	double v;
public:
	DoubleValue (double _v):v(_v){}
	virtual void print (ostream &out) 
	{
		out << v;
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

	void print (ostream &out)
	{
		out << getID () << "[label=\"+\"];" << endl;
		out << getID () << "->" << e1->getID() << ";" << endl;
		out << getID () << "->" << e2->getID() << ";" << endl;

		e1->print (out);
		e2->print (out);

	}


};

int main ()
{

	DoubleValue v5 (5), v6 (6);
	Constant c1 (&v5), c2 (&v6);
	PlusOperator p1 (&c1,&c2);


	c1.execute ()->print(cout);
	p1.execute ()->print (cout);

	Expression::printTree (&p1, cerr);

}