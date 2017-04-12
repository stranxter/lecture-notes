#include <iostream>

class Base
{
public:
  Base (int _dummy):x(0),y(1)
  {
    std::cout << "Base initialized with:" << _dummy << std::endl;
  }
  int y,x;
  virtual int returnX ()
  {
    return this->returnY();
  }

  virtual int returnY ()
  {
    return y;
  }

  void operator = (const Base&)
  {
    std::cout << "Base ASSIGNED!\n" << std::endl;
  }

  virtual ~Base ()
  {
    std::cout << "Base DESTROYED!\n";
  }

};

class Derived : public Base
{
public:
  int y,x;
  Base b;

  Derived ():Base(123),b(321),x(10),y(11){}

  int returnX ()
  {
    return x;
  }

  int returnY ()
  {

    return y;

  }

  void operator = (const Derived&)
  {
    std::cout << "Derived ASSIGNED!\n" << std::endl;
  }

  ~Derived ()
  {
    std::cout << "Derived DESTROYED!\n";
  }


};

class A
{
public:
  int type;
  int x;
  A():type(0),x(20000){}
};
class B
{
public:
  int type;
  int x;
  B():type(1),x(1000){}
};

void testVoid ()
{
  int* arr[] = {(int*)new A(),
                (int*)new B(),
                (int*)new A()};

  std::cout << "Testing int* \n";
  std::cout << ((Derived*)arr[1])->x << std::endl;

  if (((A*)arr[0])->type == 0)
  {
    std::cout << ((A*)arr[0])->x << std::endl;
  } else {
    std::cout << ((B*)arr[0])->x << std::endl;

  }

}
void testAssign ()
{
  Derived d1,d2;

  d1 = d2;
}

int main ()
{

  Base *d = new Derived();

  d->x = 8;

  std::cout << d->returnX () << std::endl;

  delete d;

  testAssign ();

  /*Base b1;
  Derived d1;

  b1 = d1;

  std::cout << (&b1)->returnX();
  */
  testVoid();

  return 0;
}
