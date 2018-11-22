#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

bool bSearch (int arr[], size_t size, int x)
{
  size_t left = 0,
         right = size;

  while (right-left > 1 &&
         arr[(left+right)/2] != x)
  {
    if (arr[(left+right)/2] < x)
    {
        left = (left+right)/2;
    }else{
        right = (left+right)/2;
    }
  }

  return arr[(left+right)/2] == x;

}

bool find (int a[], size_t size, int x)
{
  size_t c = 0;
  while (c < size && a[c] != x)
  {
    c++;
  }
  return c < size;
}

void timedFind ()
{

  const size_t arrsize = 300000;
  const size_t repetitions = 500000;
  int prefixSize = 1000;

  int a[arrsize];
  for (size_t c = 0; c < arrsize; c++)
  {
    a[c] = c;
  }

  srand (time(NULL));
  int x;

  for (prefixSize = 1000; prefixSize < 300000; prefixSize *= 1.2)
  {

      clock_t start = std::clock();
      for (int r = 0; r < repetitions; r++)
      {
         x = rand();
         //find (a, prefixSize, x);
         bSearch (a,prefixSize,x);
      }
      clock_t end = std::clock();
      long ms = (double)(end-start)/(CLOCKS_PER_SEC/1000);
      std::cout << "Time passed = "
                << ms
                << " ms. for "
                << prefixSize
                << " elements."
                << std::endl;
  }
  //std::cout << "Find " << x << "=" << << std::endl;


}

void testBSearch ()
{
  int a[] = {1, 3, 8};

  assert (bSearch(a,1,1) == true);
  assert (bSearch(a,1,2) == false);

  assert (bSearch(a,2,1) == true);
  assert (bSearch(a,2,3) == true);
  assert (bSearch(a,1,10) == false);

  assert (bSearch(a,3,1) == true);
  assert (bSearch(a,3,3) == true);
  assert (bSearch(a,3,8) == true);
  assert (bSearch(a,3,10) == false);

}

int main ()
{
  //bool find (int a[], size_t size, int x)
  //timedFind();

  //testBSearch();
  timedFind ();

}
