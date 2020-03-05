#include <iostream>
#include <cstring>

void f (int x)
{
    std::cout << x << std::endl;
}

void h (int x)
{
    std::cout << x+1 << std::endl;
}

/*
    Намиране на екстремален елемент
*/

bool compareGt (int a, int b)
{
  return a > b;
}

template <class T>
bool compareLt (T a, T b)
{
  return a < b;
}

template <class T>
using Comparator = bool (*) (T,T);

template <class T>
int findExtremum 
   (T arr[], 
    int arrSize,
    Comparator<T> comp)
{
  int indexMax = 0;
  for (int i = 1; i < arrSize; i++)
    if (comp (arr[indexMax],arr[i]))
      indexMax = i;

  return indexMax;
}

/*
    проверка дали масивът 
    съдържа елемент с дадено (произволно)
    свойство
*/

template <class T>
using Pred = bool (*) (T);

template <class T>
bool haselem (T arr[], size_t size, Pred<T> property)
{
    for (size_t i = 0; i < size; i++)
    {
        if (property(arr[i]))
        {
            return true;
        }
    }
    return false;
}

template <class T>
size_t countelem (T arr[], size_t size, Pred<T> property)
{
    size_t counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (property(arr[i]))
        {
            ++counter;
        }
    }
    return counter;
}


bool iseven (int x)
{
    return x%2 == 0;
}

bool is6 (int x)
{
    return x == 6;
}

bool is7 (int x)
{
    return x == 7;
}

bool isKalin (const char* s)
{
    return strcmp (s,"Kalin") == 0;
}

int main ()
{
    void (*pFunction) (int);

    pFunction = f;
    pFunction (0);

    pFunction = h;
    pFunction (0);

    int a[] = {1,3,56,7,8,57345,23,2,423,346,75};
    std::cout << findExtremum<int> (a,10,compareLt) << std::endl;
    std::cout << findExtremum (a,10,compareGt) << std::endl;

    double d[] = {1,2,3,4,5};
    std::cout << findExtremum<double> (d,5,compareLt) << std::endl;

    std::cout << haselem (a,10,iseven) << std::endl;
    std::cout << haselem (a,10,is6) << std::endl;

    const char* profs[] = {"Kalin", "Atanas", "Petyr", 
                     "Trifon", "Nora", "Dimityr"};

    std::cout << haselem (profs,6,isKalin) << std::endl;
    std::cout << countelem (profs,6,isKalin) << std::endl;
    

    return 0;
}