#include <iostream>
#include <assert.h>


template <typename F>
double sumSurf (F* figures[], int n)
{
  double sum = 0;

  for (int i = 0; i < n; i++)
    sum += figures[i]->surface();

  return sum;
}


class Figure
{
public:
  virtual double surface ()
  {
    assert (false);
    return -1;
  }
};

class Circle : public Figure
{
private:
  double x,y,r;
public:
  Circle (double _x, double _y, double _r):x(_x),y(_y),r(_r){}
  double surface ()
  {
    return 3.14*r*r;
  }

  double perim ()
  {
    return 2 * 3.14 * r;
  }

};

class Square : public Figure
{
private:
  double x,y,a,tga;

public:

  Square (double _x, double _y, double _a, double _tga):x(_x),y(_y),a(_a),tga(_tga){}

  double surface ()
  {
    return a*a;
  }

  double perim ()
  {
    return 4*a;
  }

};

void testSurface ()
{
  Square* squares[] = {new Square (0,0,1,0),
                       new Square (0,0,2,0),
                       new Square (0,0,3,0)};

assert (squares[1]->surface() == 4);

std::cout << "Surface test passed!\n";

}


void testSumSurface ()
{
  Square* squares[] = {new Square (0,0,1,0),
                       new Square (0,0,2,0),
                       new Square (0,0,3,0)};

assert (sumSurf(squares,3) == 14);

std::cout << "SumSurface test passed!\n";

}

void testPolymorphicSum ()
{
  Figure* squares[] = {new Square (0,0,1,0),
                       new Circle (0,0,1),
                       new Square (0,0,3,0)};


std::cout << sumSurf(squares,3) << std::endl;

std::cout << "PolymorphicSum test passed!\n";

}

int main ()
{

  testSurface ();
  testSumSurface ();
  testPolymorphicSum ();

  Figure f;
  //f.surface ();

  Circle c (0,0,1);
  //c.surface();

  Figure *pFigure = new Figure ();

  pFigure->surface();

  pFigure = new Circle (0,0,1);

  pFigure->surface();




}
