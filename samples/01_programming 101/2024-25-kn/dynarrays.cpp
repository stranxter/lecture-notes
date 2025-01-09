#include <iostream>

struct IntArray
{
    int *arr;
    unsigned size;
};

IntArray concat(IntArray a, IntArray b)
{

    //int result[a.size+b.size];
    int *result = new int[a.size+b.size];

    for(int i = 0; i < a.size; ++i)
    {
        result[i]=a.arr[i];
    }
    for(int i = 0; i < b.size; ++i)
    {
        result[a.size+i]=b.arr[i];
    }
    return {result,a.size+b.size};
}

IntArray sum(IntArray a, IntArray b)
{
    int *result = new int[std::min(a.size,b.size)];
    for(int i = 0; i < std::min(a.size,b.size); ++i)
    {
        result[i] = a.arr[i]+b.arr[i];
    }

    return {result,std::min(a.size,b.size)};
}

void printArray(IntArray a)
{
    for(int i = 0; i < a.size; ++i)
    {
        std::cout << a.arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a1[]={1,2,3}; //a1: int*
    int b1[]={4,5,6,7}; //b1: int*

    IntArray c = concat({a1,3},{b1,4}); 

    printArray(c);
    delete c.arr;

    c = sum({a1,3},{b1,4});
    printArray(c);
    delete c.arr;
}