#include <iostream>

void print_divs (unsigned long n)
{
  if (n <= 1)
  {
    std::cout << std::endl;
    return;
  }

  unsigned long i = 2;
  while (i <= n && n % i != 0)
  {
    i++;
  }

  std::cout << i;

  while (n % i == 0)
  {
    n /= i;
  }

  if (n/i > 1)
  {
      std::cout << "+";
  }

  print_divs(n);

}


unsigned long sum_divs (unsigned long n)
{
  if (n <= 1)
  {
    return 0;
  }

  unsigned long i = 2;
  while (i <= n && n % i != 0)
  {
    i++;
  }

  while (n % i == 0)
  {
    n /= i;
  }

  return i+sum_divs(n);

}

/*
  Пренарежда елементите на arr така, че
  елементие, по-малки или равни на числото pivot
  предхождат елемвнтие, по-големи от числото pivot

    \l/  \r/
  [4,13,1,2,10,10] : 5 -->
  [4,1,2,13,10,10]

  Функцията връща броя на елементите, които са
  по-малки или равни pivot
*/
size_t split (long arr[], size_t size, long pivot)
{
    long left = 0, right = size-1;

    while (left <= right)
    {
      while (arr[left] <= pivot && left < size)
      {
          left++;
      }
      while (arr[right] > pivot && right >= 0)
      {
          right--;
      }
      if (left < right)
      {
        std::swap (arr[left],arr[right]);
      }
    }
    return left;
}

void printarray (long a[], size_t n)
{
  std::cout << "[";
  for (size_t i = 0; i < n; i++)
  {
    std::cout << a[i];
    if (i < n-1)
    {
      std::cout << ",";
    }
  }
  std::cout << "]\n";
}

void qsort (long a[], size_t n)
{
  if (n <= 1)
  {
    return;
  }

  //[13,4]
  size_t nsmaller = split (a+1,n-1,a[0]);
  std::cout << "ns=" << nsmaller << std::endl;

  std::swap (a[0],a[nsmaller]);

  qsort (a,nsmaller);
  qsort (a+nsmaller+1,n-nsmaller-1);
}

int main ()
{

  std::cout << sum_divs (65535) << "=";
  print_divs (65535);

  long a[] = {4,13,1,170,3,99,2,10,10,5,0};

  size_t nsmaller = split (a,11,5);
  printarray (a,11);
  std::cout << nsmaller << std::endl;

  nsmaller = split (a,11,1000);
  printarray (a,11);
  std::cout << nsmaller << std::endl;

  nsmaller = split (a,11,-1);
  printarray (a,11);
  std::cout << nsmaller << std::endl;

  std::cout << "a, sorted:\n";
  qsort (a,11);
  printarray (a,11);

  long b[] = {13,4};
  //nsmaller = split (b+1,2,13);
  //printarray (b,3);
  //std::cout << nsmaller << std::endl;

  qsort (b,2);
  printarray (b,2);

}
