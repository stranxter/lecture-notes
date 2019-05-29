#ifndef __LINEARFN_H
#define __LINEARFN_H

#include "function.h"

class Linear : public Function
{
public:
    Linear(double _a, double _b);
    double value(double x);
    Function *clone();

private:
    double a,b;
};

#endif