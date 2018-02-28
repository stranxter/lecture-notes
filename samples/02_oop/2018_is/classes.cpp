#include <iostream>
#include <cmath>

class Point
{
public:

  double x,y;

  double distanceFromOrigin ()
  {
    return sqrt (x*x + y*y);
  }

  void translate (double vx, double vy)
  {
    this->x += vx;
    /*this->*/y += vy;
  }
};
/*
double distanceFromOrigin (Point p)
{
  return sqrt (p.x*p.x + p.y*p.y);
}
*/

class Vector2D
{
public:
  double a,b;

  Vector2D plus (Vector2D other)
  {
    Vector2D r = {this->a + other.a,this->b + other.b};
    /*
    <=>
    Vector2D r;
    r.a = this->a + other.a;
    r.b = this->b + other.b;
    */

    return r;
  }

  Vector2D operator + (Vector2D other)
  {
    return this->plus (other);
  }

  void print ()
  {
    std::cout << "(" << a << "," << b << ")\n";
  }

  Vector2D operator * (double a)
  {
    Vector2D r = {this->a*a, b*a};
    return r;
  }

  double operator * (Vector2D other)
  {
    return a*other.a + b*other.b;
  }

  Vector2D operator *= (double a)
  {
    this->a *= a;
    b *= a;

    return *this;
  }

};

int main ()
{
  Point p1 = {0,0}; //p1.x = 0; p1.y = 0;
  Point p2 = {1,1};

  std::cout << "Dist orig p1 = " << p1.distanceFromOrigin () << std::endl;
  std::cout << "Dist orig p2 = " << p2.distanceFromOrigin () << std::endl;

  p1.translate (2,0);

  std::cout << "Dist orig p1 = " << p1.distanceFromOrigin () << std::endl;
  std::cout << "Dist orig p2 = " << p2.distanceFromOrigin () << std::endl;

  Vector2D v1 = {0,1};
  Vector2D v2 = {2,3};

  v1.print();
  v2.print();

  v1.plus (v2).print();
  /*
    Vector2D v3;
    v3 = v1.plus(v2);
    v3.print();
  */

  Vector2D v3 = v1 + v2;
  //Vector2D v3 = v1.operator + (v2);
  v3.print();

  v3 = v3 * 2;
  v3.print ();

  Vector2D v4 = v3 *= 2;
  v4.print ();

  std::cout << "v1*v2 = " << v1 * v2 << std::endl;

  Vector2D vectors[] = {v1,v2,v3};

  (vectors[2] + vectors[0] * (vectors[1] * v4)).print();

  return 0;
}
