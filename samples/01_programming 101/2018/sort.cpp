#include <iostream>


void printArray (int a[], size_t size)
{
  std::cout << "{";
  for (int i = 0; i < size-1; i++)
  {
    std::cout << a[i] << ",";
  }
  std::cout << a[size-1] << "}\n";
}



void insertSorted (int a[], size_t size, int x)
/*
  size: брой на елементите, текущо в масива
  разчитаме на това, че размерът на масива е поне size+1
*/
{
  // 10 20 30   +25
  // *  *  ^

  size_t targetIndex = 0;

  while (a[targetIndex] < x && targetIndex < size)
  {
    targetIndex++;
  }

  // 10 20  30  40 41  50  60 70 80 90      |+45  |+91
  // *  *   *   *  *   ^

  for (size_t i = size; i > targetIndex; i--)
  {
    a[i] = a[i-1];
  }

  a[targetIndex] = x;

}

void sssort (int a[], size_t size)
{
  int tmp;

  for (size_t nextToSort = 0; nextToSort < size; nextToSort++)
  {
    /* Търсим най-малки елемент в остатъка от масива*/
    int bestCandidate = nextToSort;
    for (size_t candidate = nextToSort+1; candidate < size; candidate++)
    {
      if (a[bestCandidate] > a[candidate])
      {
        bestCandidate = candidate;
      }
    }
    //----------------------------------------------
    //bestCandidate = елемент, който трябва да заеме мястото на nextToSort
    tmp = a[nextToSort];
    a[nextToSort] = a[bestCandidate];
    a[bestCandidate] = tmp;
  }
}


void merge (int a[], size_t sizea, int b[], size_t sizeb, int c[])
/*
Приемаме, че размерът на c е поне sizea + sizeb
sizea и sizeb са наредени в нарастващ ред
*/
{
  size_t indexa = 0, indexb = 0;

  while (indexa < sizea || indexb < sizeb)
  {
    if (indexb == sizeb || a[indexa] < b[indexb])
    {
      c[indexa+indexb] = a[indexa];
      indexa++;
    } else {
      c[indexa+indexb] = b[indexb];
      indexb++;
    }
  }

}
 void testMerge ()
 {
   int a[] = {1,5,7,9};
   int b[] = {2,6,10,20,30,40};
   int c[10] = {0};

   merge(a,4,b,6,c);
   printArray (c,10);

 }

void testSSSort ()
{
  int a[] = {343425,6,4,3,7,867,22423,678,345435,0};

  sssort (a,10);
  printArray (a,10);
}


int main ()
{
  /*
  int a[10] = {0};
  int x;

  for (int i = 0; i < 10; i++)
  {
    std::cout << "Please enter " << i << "-th number=";
    std::cin >> x;
    insertSorted (a,i,x);
  }

  printArray (a,10);
  */

  testSSSort ();

  testMerge ();


}
