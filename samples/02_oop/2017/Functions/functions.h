#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

class Function
{
public:
  virtual double value (double) = 0;
  double operator () (double);

};

#endif
