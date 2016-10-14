#include <iostream>
#include <assert.h>
#include <map>
#include <string>
#include <math.h>

using namespace std;

#include "doublevalue.h"

DoubleValue::DoubleValue (double _v):v(_v){}
void DoubleValue::print (ostream &out) 
{
	out << v;
}

Value *DoubleValue::plus (Value *other) 
{
	assert (other->getType() == DOUBLE_VALUE);
	return new DoubleValue (v + ((DoubleValue*)other)->v);
} 

Value *DoubleValue::minus (Value *other) 
{
	assert (other->getType() == DOUBLE_VALUE);
	return new DoubleValue (v - ((DoubleValue*)other)->v);
} 

Value *DoubleValue::power (Value *other) 
{
	assert (other->getType() == DOUBLE_VALUE);
	return new DoubleValue (pow (v,((DoubleValue*)other)->v));
} 

int DoubleValue::getType () 
{
	return DOUBLE_VALUE;
}

bool DoubleValue::toNativeBool () 
{
	return v != 0;
}

bool DoubleValue::equals (Value* other) 
{
	//this->v

	return other->getType() == DOUBLE_VALUE && 
		   v == ((DoubleValue*)other)->v;

}


