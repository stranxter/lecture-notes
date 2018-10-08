#include "dynarray.cpp"
#include "dllist.cpp"
#include <cassert>

void fnWithArg (DynArray<int> arg)
{
  arg[3] = 100;
}

int testDynArray ()
{

  DynArray<int> a(10);

  a[3] = 1;
  assert(a[3]==1);

  //std::cout << a[11];
  a[11] = 2;
  assert(a[11]==2);

  assert (a.getSize () >= 12);

  fnWithArg (a);
  assert (a[3] == 1);

  DynArray<int> b;
  b = a;

  assert (b[3] == 1);
  b[3] = 100;
  assert (b[3] == 100);
  assert (a[3] == 1);


  return 0;

}

int testDDList ()
{

  DLList<int> l1;


  //test push && pop

  l1. push(0);
  l1. push(1);
  l1. push(2);

  assert (l1.top() == 2);
  l1.pop();
  assert (l1.top() == 1);
  l1.pop();
  assert (l1.top() == 0);

  //test copy

  l1. push(1);
  l1. push(2);

  DLList<int> l2 (l1);
  assert (l2.top() == 2);
  l2.pop();
  assert (l2.top() == 1);
  l2.pop();
  assert (l2.top() == 0);

  assert (l1.top() == 2);
  l1.pop();
  assert (l1.top() == 1);
  l1.pop();
  assert (l1.top() == 0);

  //test assignmrnt
  l1. push(0);
  l1. push(1);
  l1. push(2);

  l2 = l1;

  assert (l2.top() == 2);
  l2.pop();
  assert (l2.top() == 1);
  l2.pop();
  assert (l2.top() == 0);

  assert (l1.top() == 2);
  l1.pop();
  assert (l1.top() == 1);
  l1.pop();
  assert (l1.top() == 0);

  return 0;
}

int main ()
{
  testDynArray();
  testDDList();
}
