#include <iostream>

int id(int x)
{
    return x;
}

int inc(int x)
{
    return x+1;
}

int sq(int x)
{
    return x*x;
}

using FArray = int (*[])(int);

int sumall(FArray a, size_t nFunctions, int x)
{
    int sum = 0;
    for(size_t i = 0; i < nFunctions; ++i)
    {
        sum += a[i](x);
    }
    return sum;
}

int main()
{

    int (*pf) (int);

    pf = id;
    std::cout << pf(0) << std::endl;

    int (*a[])(int) = {id,inc,sq};

    std::cout << a[1](0) << std::endl;

}