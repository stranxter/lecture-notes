#include <iostream>
#include <assert.h>

#include "functions.h"
#include "constant.h"
#include "linear.h"
#include "cutfunction.h"

using FT = double (*) (double);

double constant (double x)
{
  return 0;
}

double id (double x)
{
  return x;
}

FT Gamma (FT f)
{
  return constant;
}

void printall (Function *functions[], size_t n, double x)
{
  for (size_t i = 0; i < n; i++)
    std::cout  << "f"
               << i
               << "("
               << x
               << ")="
               << (*functions[i])(x)
               << std::endl;
}


void testSimple ()
{
  Constant c (2);
  Linear l (1,2);

  assert (c.value(8) == 2);
  assert (l.value(1) == 3);
}

void testGamma ()
{

  assert (Gamma (id)(5)==0);


}

void testCutFunction ()
{
  Linear l (1,0);
  CutFunction cutl (&l);

  std::cout << l (5) << std::endl;

  assert (cutl.value(-1) == 0);
  assert (cutl.value(2) == 2);

  CutFunction cutcutl (&cutl);

  assert (cutcutl.value(-1) == 0);
  assert (cutcutl.value(2) == 2);

  Function *f[] = {&l,&cutl,&cutcutl};

  printall (f,3,-1);

}





int main ()
{
  testSimple ();
  testGamma ();
  testCutFunction ();

  return 0;
}
