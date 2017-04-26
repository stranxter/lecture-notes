#ifndef __CUTFN_H
#define __CUTFN_H

#include "functions.h"

class CutFunction : public Function
{
private:
  Function *f;
public:
  CutFunction (Function*);
  double value (double);

};


#endif
