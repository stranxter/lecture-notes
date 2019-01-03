
#include <iostream>

const size_t maxPower = 50;

struct Poly
{
  double coefs[maxPower];
  size_t power;
};

Poly sum (Poly a, Poly b)
{
  Poly result;

  result.power = std::max (a.power, b.power);
  /*
    Тъй като някои степени  може да се съкратят,
    в тази променлива ще намерим най-вискоката степен
    с ненулев коефициент в новия полияном
  */
  size_t newPower = 0;
  for (size_t p = 0; p <= result.power; p++)
  {
    result.coefs [p] = a.coefs[p] + b.coefs[p];
    if (result.coefs[p] != 0)
    {
      newPower = p;
    }
  }
  result.power = newPower;

  return result;
}

Poly readPoly ()
{
  Poly result;
  std::cout << "Please enter power=";
  std::cin >> result.power;
  for (size_t p = 0; p <= result.power; p++)
  {
    std::cout << "a[" << p << "]=";
    std::cin >> result.coefs[p];
  }
  return result;
}

void printPoly (Poly poly)
{
  for (size_t p = 0; p <= poly.power; p++)
  {
    std::cout << "a[" << p << "]=" << poly.coefs[p] << std::endl;
  }
}

double val (Poly poly, double x)
{
  double result = 0;

  for (int p = poly.power; p >= 0; p--)
  {
    result = result*x + poly.coefs[p];
  }

  return result;
}

int main ()
{
  Poly p1 = readPoly();
       //p2 = readPoly();

  //printPoly (sum(p1,p2));

  double x;
  std::cout << "Please x=";
  std::cin >> x;
  std::cout << "Poly(" << x << ")=" << val (p1,x);


}
