#include <iostream>


void f (long *x)
{
  (*x)++;
}

void g (long x)
{
  x++;
}

void h (const long x[])
{
  //x[0]++;
  long *pi = (long*)x;
  pi[0]++;
}

int main ()
{

  long a = 1, b = 2;

  std::cout << (long)&a << std::endl << (long)&b << std::endl;

  long *pi = &a;

  std::cout << (long)pi << std::endl << (long)&pi << std::endl;

  pi = (long*)7;

  std::cout << (long)pi << std::endl;

  pi = &a;

  *pi = 7;
  std::cout << a << std::endl;

  pi = &b;

  *pi = 70;
  std::cout << a << std::endl;
  std::cout << b << std::endl;

  f (&b);
  std::cout << b << std::endl;

  long arr[]={1,2,3,4};

  std::cout << arr[0] << std::endl;
  g (arr[0]);
  std::cout << arr[0] << std::endl;
  h (arr);
  std::cout << arr[0] << std::endl;


  return 0;
}
