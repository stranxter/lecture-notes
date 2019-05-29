#ifndef __CUT_H
#define __CUT_H

#include "function.h"

class Cut : public Function
{
    public:
    Cut (Function *_originalFunction);
    Cut (const Cut&);

    double value (double x);
    Function *clone();

    ~Cut();

private:
    Function *originalFunction;
};

#endif