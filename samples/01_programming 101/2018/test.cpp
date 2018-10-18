#include <iostream>
#include <cmath>

using namespace std;

double triangleSurface (double a, double b, double c)
{
  double p = (a+b+c)/2;
  double surface = sqrt (p*(p-a)*(p-b)*(p-c));

  cout << "The surface is " << surface << endl;

  return surface;
}

void printBiggerNumber (int a, int b)
{
  if (a > b)
  {
    cout << "a" << endl;
  } else {
    cout << "b" << endl;
  }

  //return 0;
}

double enterValidTriangleSide ()
{
  double side = -1;

  for (;side <= 0;)
  {
    cout << "Please, enter side=";
    cin >> side;
  }

  return side;
}


int main ()
{


  double s1 = triangleSurface (enterValidTriangleSide(),
                               enterValidTriangleSide(),
                               enterValidTriangleSide());

  cout << "Howdy! Surface = " << s1 << endl;



  return 0;
}
