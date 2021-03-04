#include <iostream>

template <typename T>
struct Array
{
    T *buf;
    size_t size;
};

template <typename T>
Array<T> inputArray()
{
    size_t n;
    std::cout << "Please enter array size:";
    std::cin >> n;

    Array<T> arr;
    arr.buf = new T[n];
    arr.size = n;

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "a[" << i << "]=";
        std::cin >> arr.buf[i];
    }

    return arr;
}

template <typename T>
size_t findIndexMax (Array<T> arr) 
{
    size_t indexMax = 1;
    for (size_t i = 1; i < arr.size; ++i)
    {
        if (arr.buf[indexMax] < arr.buf[i])
        {
            indexMax = i;
        }
    }
    return indexMax; 
}

template <typename T>
Array<T> sumArrays(Array<T> a, Array<T> b)
{
    Array<T> result;
    result.buf = new T[a.size];

    for (size_t i = 0; i < a.size; ++i)
    {
        result.buf[i] = a.buf[i] + b.buf[i];
    }

    return result;
}

int main()
{
    int a[] = {1,2,3};
    int b[] = {1,2,3};

    Array<int> ia;
    Array<double> da;
    
    ia = inputArray<int>();
    std::cout << findIndexMax(ia) << std::endl;

    da = inputArray<double>();
    std::cout << findIndexMax(da) << std::endl;

    delete []ia.buf;
    delete []da.buf;


}