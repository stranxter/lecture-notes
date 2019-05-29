#include "constfn.h"


Const::Const(double _c):c(_c){}

double Const::value (double x)
{
    return c;
}

Function* Const::clone()
{
    return new Const (*this);
}
