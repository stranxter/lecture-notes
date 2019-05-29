#ifndef __CONSTFN_H
#define __CONSTFN_H

#include "function.h"

class Const : public Function
{
public:
    Const (double _c);
    double value (double x);
    Function* clone();
private:
    double c;
};

#endif