#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

#include "figure.h"
#include "square.h"
#include "circle.h"

template <typename F>
double sumSurf (F* figures[], int n)
{
  double sum = 0;

  for (int i = 0; i < n; i++)
    sum += figures[i]->surface();

  return sum;
}


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


void testSerialize ()
{

  std::ofstream outfile ("data.txt");

  std::vector<Figure*> figures;

  figures.push_back (new Square (0,0,1,0));
  figures.push_back (new Circle (0,0,1));
  figures.push_back (new Square (0,0,3,0));

  outfile << figures;



}

void testDeserialize ()
{
  std::ifstream input ("data.txt");

  std::vector<Figure*> figures;

  input >> figures;

  std::cout << figures;
}

int main ()
{

  testSurface ();
  testSumSurface ();
  testPolymorphicSum ();

  testSerialize();
  testDeserialize();

  //Figure f;
  ///f.surface ();

  //Circle c (0,0,1);
  //c.surface();

  //Figure *pFigure = new Figure ();

  //pFigure->surface();

  //pFigure = new Circle (0,0,1);

  //pFigure->surface();




}
