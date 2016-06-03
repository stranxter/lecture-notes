#include <iostream>
#include <assert.h>
#include <map>
#include <string>
#include <math.h>
#include <vector>

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
	virtual Value *power (Value *other) 
	{
		assert (false);
		return NULL;
	};

	virtual bool toNativeBool ()
	{
		assert (false);
		return false;
	}

	virtual int getType () = 0;

};


class Expression
{
private:
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

    Value *power (Value *other)
    {
    	assert (other->getType() == DOUBLE_VALUE);
    	return new DoubleValue (pow (v,((DoubleValue*)other)->v));
    } 

    int getType ()
    {
    	return DOUBLE_VALUE;
    }

	virtual bool toNativeBool ()
	{
		return v != 0;
	}


};


class BinaryArithmOper : public Expression
//5+6
{
private:
	Expression *e1; Expression *e2;
	char op;
public:
	BinaryArithmOper 
	      (Expression *_e1, 
	       Expression *_e2,
	       char _op):e1(_e1),e2(_e2),op(_op){}
	Value* execute ()
	{
		//return e1->execute() -> plus (e2->execute());

		Value *valueOfe1 = e1->execute();
		Value *valueOfe2 = e2->execute();

		switch (op)
		{
			case '+': return valueOfe1->plus (valueOfe2); 
			case '^': return valueOfe1->power (valueOfe2);


		}

		assert (false);
		return new DoubleValue (0);
	}

	void print (ostream &out)
	{
		out << getID () << "[label=\"" << op << "\"];" << endl;
		out << getID () << "->" << e1->getID() << ";" << endl;
		out << getID () << "->" << e2->getID() << "[style=\"dashed\"];" << endl;

		e1->print (out);
		e2->print (out);
	}
};


class IfExpr : public Expression
{
private:
	Expression *conde, *thene, *elsee;
public:
	IfExpr (Expression *_c, 
		    Expression *_t,
		    Expression *_e): conde(_c), thene (_t), elsee (_e){};


	Value* execute ()
	{
		if (conde->execute()->toNativeBool())
			return thene->execute();
		return elsee->execute();
	}

	void print (ostream &out)
	{
		out << getID () << "[label=\"IF\"];" << endl;
		out << getID () << "->" << conde->getID() << "[style=dashed];" << endl;
		out << getID () << "->" << thene->getID() << ";" << endl;
		out << getID () << "->" << elsee->getID() << ";" << endl;

		out << thene->getID () << "[shape=\"box\"];" << endl;


		conde->print (out);
		thene->print (out);
		elsee->print (out);
	}
};

map<string,Value*> AllValues;


class VarExpression : public Expression
{
private:
	string varName;

public:
	VarExpression (string _vn):varName(_vn){}

	void print (ostream &out)
	{
		out << getID () << "[label=\"" << varName << "\",shape=box];" << endl;
		
	}

	Value* execute ()
	{
		return AllValues[varName];
	}

};


class SetExpression : public Expression
{
private:
	string varName;
	Expression *newVal;
public:

	SetExpression (string var, Expression *nv): varName(var), newVal (nv){}

	void print (ostream &out)
	{
		out << getID () << "[label=\"" << varName << ":=\"];" << endl;
		out << getID () << "->" << newVal->getID() << endl;

		newVal->print (out);

	}

	Value* execute ()
	{
		AllValues[varName] = newVal->execute();
		return AllValues[varName];
	}


};

class BlockExpression : public Expression
{
private:
  vector<Expression*> expressions;
public:
  BlockExpression (){}

  void addExpression (Expression *e)
  {
  	expressions.push_back (e);
  }

	void print (ostream &out)
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

	Value* execute ()
	{
		Value *res;

		for (int i = 0; i < expressions.size(); i++)
			res = expressions[i]->execute();

		return res;
	}  

};


int main ()
{


	IfExpr  
	  *ie1 = new IfExpr 
	    (new BinaryArithmOper (new Constant (new DoubleValue (-2)),
	    				       new Constant (new DoubleValue (2)),
	    				       '+'),
	     new Constant (new DoubleValue (3)),
	     new Constant (new DoubleValue (4)));

	SetExpression *se = new SetExpression ("myFirstVar",ie1);


	BinaryArithmOper *varSample =
	 new BinaryArithmOper (new Constant (new DoubleValue (1)),
			               new VarExpression ("myFirstVar"),
			               '+');

	BlockExpression *be = new BlockExpression ();
	be->addExpression (se);
	be->addExpression (varSample);


	Expression::printTree (be, cerr);

	be->execute()->print (cout);

	cout << endl;


}