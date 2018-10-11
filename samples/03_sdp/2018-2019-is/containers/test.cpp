#include "dynarray.cpp"
#include "dllist.cpp"
#include <cassert>
#include <iostream>
#include <ctime>
#include <fstream>



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

  assert (l1.size() == 3);
  assert (l1.top() == 2);
  l1.pop();
  assert (l1.size() == 2);
  assert (l1.top() == 1);
  l1.pop();
  assert (l1.size() == 1);
  assert (l1.top() == 0);

  //test copy

  l1. push(1);
  l1. push(2);

  DLList<int> l2 (l1);
  assert (l2.size() == 3);
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

  //test assignment
  l1. push(0);
  l1. push(1);
  l1. push(2);

  l2 = l1;
  assert (l2.size() == 4);

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

void testTraversal()
{
  DLList<int> l1;

  l1. push(0);
  l1. push(1);
  l1. push(2);

  for (size_t i =0; i < l1.size(); i++)
  {
      std::cout << "l[" << i << "]=" << l1[i] << std::endl;
  }

}

const size_t testTraials = 5;

void timeTestIteration (size_t nelements, std::ostream &out)
{
  DLList<int> l;
  size_t i;

  for (i = 0; i < nelements; i++)
  {
    l.push (i);
  }
//time1
clock_t start = std::clock();

for (size_t trial = 0; trial < testTraials; trial++)
{
    for (i = 0; i < nelements; i++)
    {
      l[i]++;
    }
}

clock_t end = std::clock();

long ms = (double)(end-start)/(CLOCKS_PER_SEC/1000);
out << ms << std::endl;
//time2
//time2 - time1
}

void collectTimeData (std::ostream &out)
{
  for (uint i  = 1000; i < 10000; i += 1000)
  {

    std::cout << "Testing with " << i << " elements.";
    out << i << ", ";
    timeTestIteration(i,out);
    std::cout << std::endl;
  }

}

int main ()
{
  testDynArray();
  testDDList();
  testTraversal ();

  std::ofstream csvfile ("times.csv");
  collectTimeData (csvfile);
  std::cout << "Results saved to times.csv." << std::endl;
}
