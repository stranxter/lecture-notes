#include <iostream>


using Comparator = bool (*)(int,int);

bool compareGt (int a, int b) {
  return a > b;
}

bool compareLt (int a, int b) {
  return a < b;
}

bool more9s (int a, int b) {
  int ninesa = 0, ninesb = 0;

  while (a > 0)
  {
    ninesa += (a%10 == 9);
    a /= 10;
  }

  while (b > 0)
  {
    ninesb += (b%10 == 9);
    b /= 10;
  }

  return ninesa > ninesb;
}


int findExtremum (int arr[], int n, Comparator comp)
{
  int max = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (comp(arr[i],max))
    {
      max = arr[i];
    }
  }
  return max;
}

int main ()
{

  int a[] = {67,8967,69,8,7,9,89924,3,7,5};

  std::cout << findExtremum (a,10,[](int a, int b){return a > b;}) << std::endl;
  std::cout << findExtremum (a,10,compareLt) << std::endl;
  std::cout << findExtremum (a,10,more9s) << std::endl;

/*  Comparator pComparator = compareLt;

  std::cout << pComparator (1,2) << std::endl;
  std::cout << (long)(compareGt) << std::endl;
  std::cout << (long)(compareLt) << std::endl;

  std::cout << "Please enter address:";

  long tmp;

  std::cin >> tmp;
  pComparator = (Comparator)tmp;

  std::cout << pComparator (1,2) << std::endl;
*/
}
