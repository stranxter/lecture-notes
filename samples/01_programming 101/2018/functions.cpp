#include <iostream>
#include <cmath>


void printSeq (unsigned int N)
{
  if (N > 0)
  {
    printSeq (N-1);
  }
  std::cout << " " << N;
}

int enterNumber (int a, int b)
{
  std::cout << "Please enter a number between "
            << a
            << " and "
            << b
            << ":"
            << std::endl;

  int n;
  std::cin >> n;
  while (n < a || n > b)
  {
    std::cout << "Wrong input! Try again:";
    std::cin >> n;
  }
  return n;
}

int enterNumberRec (int a, int b)
{
  std::cout << "Please enter a number between "
            << a
            << " and "
            << b
            << ":"
            << std::endl;
  int n;
  std::cin >> n;

  if (n >= a && n <= b)
  {
    return n;
  }

  return enterNumberRec (a,b);

}


void printDigits (unsigned int x)
{

  while (x > 10)
  {
    std::cout << x % 10 << " ";
    x /= 10;
  }

  std::cout << x;
}

void printDigitsRec (unsigned int x)
{
  if (x < 10)
  {
    std::cout << x << " ";
    return;
  }
  printDigitsRec (x / 10);
  std::cout << x % 10 << " ";
}

bool findDigit (int x, int k)
{
  if (x % 10 == k)
  {
    return true;
  }
  if (x < 10)
  {
    return false;
  }
  return findDigit (x/10);
}

int main ()
{
  printSeq (10);
  std::cout << std::endl;

  //std::cout << sqrt (enterNumberRec (0, INT_MAX));

  printDigits (123);
  std::cout << std::endl;

  printDigitsRec (123);
  std::cout << std::endl;

}
