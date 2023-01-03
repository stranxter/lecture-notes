#include <iostream>

struct DynArray
{
    long *arr;
    size_t size;
};

DynArray sum (DynArray a1, DynArray a2)
{
    DynArray result;

    result.size = std::min(a1.size,a2.size);
    result.arr = new long[result.size];

    for (int i = 0; i < result.size; ++i)
    {
        result.arr[i] = a1.arr[i] + a2.arr[i];
    }

    return result;
}


DynArray inputArray() 
{
    DynArray result;
    std::cout << "Please enter array size: ";
    std::cin >> result.size;
    result.arr = new long[result.size];
    for (int i = 0; i < result.size; i++)
    {
        std:: cout << "a[" << i << "]=";
        std::cin >> result.arr[i];
    }
    return result; 
}

DynArray printArray(DynArray a)
{
    for (int i = 0; i < a.size; ++i)
    {
        std::cout << "a[" << i << "]=" << a.arr[i] << std::endl;
    }

    return a;
}

void releaseArray(DynArray a)
{
    delete a.arr;
}

int main()
{

    DynArray a, b;
    a = inputArray();
    b = inputArray();

    releaseArray(printArray(sum(a,b)));

}