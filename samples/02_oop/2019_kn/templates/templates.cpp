#include <iostream>
#include <iomanip>

template <typename T>
void printArray (T arr[], int arrSize) 
{
    std::cout << "{";
    for (int i = 0; i < arrSize-1; i++)
    {
       std::cout << arr[i] << ",";
    }
    
    if (arrSize > 0)
    {
        std::cout << arr[arrSize -1];
    }

    std::cout << "}"; 
}

template <typename T>
T sumElements (T a[], size_t n)
{
    T result = 0;
    for (size_t i = 0; i < n; i++)
    {
        result += a[i];
    }
    return result;
}

template <typename T>
bool compareGt (T a, T b) 
{
    //sjkchsdcdhs
    return a > b;
}

template <typename T>
bool compareLt (T a, T b) 
{
    //ckdsncsdkcndsocn
    return a < b;
}

template <typename T>
size_t findExtremum (T arr[],
                     size_t arrSize,
                     bool (*pComparator)(T,T)) 
{
    size_t indexMax = 0;
    for (size_t i = 1; i < arrSize; i++)
    {
        if (pComparator (arr[indexMax],arr[i])) 
        {
          indexMax = i;
        }
    }
    return indexMax; 
}

template <typename ElemType, typename ResultType>
ResultType fold  (ElemType a[], 
                  size_t n, 
                  ResultType nul_val, 
                  ResultType (*operation) (ResultType,ElemType))
{
    ResultType result = nul_val;
    for (size_t i = 0; i < n; i++)
    {
        result = operation (result, a[i]);
    }
    return result;
}

template <typename T>
void map (T a[], size_t n, T (*f) (T))
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] = f(a[i]);
    }
}

int inc (int x)
{
    return x+1;
}

int mult2 (int x)
{
    return x*2;
}

template <typename T>
T* filter (T arr[], size_t n, bool (*pred) (T), size_t& newSize)
{
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (pred(arr[i]))
        {
            count++;
        }
    }
    T *result = new T[count];
    count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (pred(arr[i]))
        {   
            result[count] = arr[i];
            count++;
        }
    }
    newSize = count;
    return result;
}


template <typename ElemType, typename ResultType>
ResultType plus (ResultType current, ElemType newElement)
{
    return current + newElement;
}

template <typename ElemType, typename ResultType>
ResultType mult (ResultType current, ElemType newElement)
{
    return current * newElement;
}

template <typename ElemType, typename ResultType>
ResultType sumones (ResultType current, ElemType newElement)
{
    if (newElement % 2 == 0)
        return current + 1;
    
    return current;

    //return current + (newElement % 2 != 0);
}

template <typename ElemType>
bool checkAtLeastOneEven (bool current, ElemType newElement)
{
    return current || (newElement % 2 == 0);
}

bool check500 (int i)
{
    return i >= 500;
}


int main ()
{

   bool (*pointerToComparator) (int,int);

    //pointerToComparator

    std::cout << compareGt (1,2);

    //std::cout << (long*)compareGt << std::endl;
    //std::cout << (long*)compareLt << std::endl;

    pointerToComparator = compareLt;

    std::cout << pointerToComparator (2,1) << std::endl;

    int arr [] = {25,3563,473845,733,7,457,567,63,5};

    std::cout << arr[findExtremum (arr,9,compareGt)] 
              << std::endl
              << arr[findExtremum (arr,9,compareLt)]
              << std::endl; 

    double darr [] = {42342.4,234234.5757,535.2423,545.435,346.34};
    std::cout << darr[findExtremum (darr,5,compareGt)] 
              << std::endl
              << std::setprecision (3)
              << darr[findExtremum (darr,5,compareLt)]
              << std::endl; 

    std::cout << "Sum of all ints = "
              << fold (arr,9,0,plus)
              << std::endl
              << "Product of all ints = "
              << fold (arr,9,1,mult)
              << std::endl
              << "Count ints = "
              << fold (arr,9,0,sumones)
              << std::endl
              << "Find even = "
              << fold (arr,9,false,checkAtLeastOneEven<int>)
              << std::endl;


    printArray(arr,9);
    std::cout << std::endl;
    map (arr,9,inc);
    printArray(arr,9);
    map (arr,9,mult2);
    std::cout << std::endl;
    printArray(arr,9);

    std::cout << std::endl;
    size_t newSize = 0;
    int *newarr = filter (arr,9,check500,newSize);
    printArray (newarr,newSize);
    delete newarr;

    return 0;
}


