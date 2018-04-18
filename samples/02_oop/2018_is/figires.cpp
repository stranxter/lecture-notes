#include <cassert>
#include <iostream>

class Figure {
  public:
  char label [15];
  virtual double surface () = 0;
};

class Rectangle : public Figure {
public:
  Rectangle (double _a, double _b): a(_a), b(_b){}
  double a,b;
  double surface ()
  {
    return a*b;
  }
};

class Square : public Figure {
public:
  Square (double _a): a(_a){}
  double a;
  double surface ()
  {
    return a*a;
  }
};

double sumSurfaces (Figure *figures[],size_t n)
{
  double sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    sum += figures[i]->surface();
  }
  return sum;
}

int main ()
{

  Rectangle r (2,3);
  Square c (10);

  Figure *f = &r;
  std::cout << f->surface () << std::endl;

  f = &c;
  std::cout << f->surface ()<< std::endl;;

  Figure *figures[] = {new Square (2),
                       new Rectangle (2,3),
                       new Square (4),
                       new Square (5)};

  std::cout << sumSurfaces (figures, 4);

}
