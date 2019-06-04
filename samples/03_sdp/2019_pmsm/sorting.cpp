#include <iostream>

const size_t max_size = 1000;


template <typename T>
void printArray (T a[], size_t n)
{
    std::cout << "{";
    for (size_t i = 0; i < n-1; i++)
    {
        std::cout << a[i];
        std::cout << ",";
    }
    if (n > 0)
    {
        std::cout << a[n-1];
    }
    std::cout << "}\n";
}

template <typename T>
void insertion_sort(T arr[], size_t n, T x)
{
    size_t insertAt = 0;
    
    while (insertAt < n && 
           x >= arr[insertAt])
    {
        ++insertAt;
    }

    for (size_t i = n; i > insertAt; i--)
    {
        arr[i] = arr[i-1];
    } 

    arr[insertAt] = x;
    
}

template <typename T>
void ssort(T arr[], size_t n)
{
    size_t nextElement = 1;

    while (nextElement < n)
    {
        int save = arr[nextElement];
        insertion_sort (arr, nextElement, save);
        ++nextElement;
    }
}

template <typename T>
size_t find(T arr[], size_t n, T x)
{
    size_t left = 0, right = n;

    while (left<right-1)
    {
        if (arr[(left+right)/2] > x)
        {
            right = (left+right)/2;
        } else if (arr[(left+right)/2] < x)
        {
            left = (left+right)/2;  //!!!
        } else 
        {
            return (left+right)/2;
        }
    }

    if (arr[(left + right) / 2] == x)
    {
        return (left + right) / 2;
    }

    return n;
}

    int main()
{
    int arr[max_size];

    size_t nElements;

    std::cout << "Въведете брой елементи:";
    std::cin >> nElements;

    if (nElements > max_size)
    {
        std::cout << "Твърде голям брой елементи!";
        nElements = max_size;
    }

    int element;

    for (size_t i = 0; i < nElements; i++)
    {
        std::cout << "Моля въведете " << i << "-ти елемент:";
        std::cin >> element;
        //insertion_sort(arr, i, element);
        arr[i] = element;
        std::cout << "\n";
    }

    printArray (arr,nElements);
    ssort (arr,nElements);
    printArray(arr, nElements);

    std::cout << find(arr, nElements, 87) << std::endl;
    std::cout << find(arr, nElements, 6556) << std::endl;
    std::cout << find(arr, nElements, 9) << std::endl;
    std::cout << find(arr, nElements, 57) << std::endl;
}