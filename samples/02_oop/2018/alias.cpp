#include <iostream>

void f (int &x)
{
  std::cout << x << "\n";
  x = 10;
  std::cout << x << "\n";
}

int* inc (int z)
{
  ++z;
  return &z;
}

int& getFirst (int a[], int n)
{
  return a[0];
}

int another (int x, int y)
{
  return x + y;
}

int main ()
{
  int y = 0;
  f (y);
  std::cout << y << "\n";

  std::cout << "--------------\n";

  int *p = inc (y);
  std::cout << "*p=" << *p << std::endl;

  std::cout << another (10,19) << std::endl;

  std::cout << "*p=" << *p << std::endl;

  int test[]={1,2,3};
  std::cout << getFirst (test,3) << std::endl;

}
