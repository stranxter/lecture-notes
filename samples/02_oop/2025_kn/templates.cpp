#include <iostream>
#include <utility>

template <typename T>
using Operator = T(*)(T);

template <typename T>
using Combinator = T(*)(T,T);

template <typename T>
T fold(const T a[], unsigned n, T null_val, Combinator<T> op)
{
    T accum = null_val;
    for(int i = 0;i < n; ++i)
    {
        accum = op(a[i],accum);
    }
    return accum;
}

template <typename T>
T id(T x)
{
    return x;
}

template <typename T>
T sq(T x)
{
    return x*x;
}

template <typename T>
T cube(T x)
{
    return x*x*x;
}

template <typename T>
T p1(T x)
{
    return x+1;
}

template <typename T>
using Comparator = bool(*)(T,T);

template <typename T>
unsigned findExtr(const T a[], unsigned n, Comparator<T> pComp)
{
    unsigned extr = 0;
    for(int i = 1; i < n; ++i)
    {
        if(pComp(a[i],a[extr]))
        {
            extr = i;
        }    
    }
    return extr;
}

template <typename T>
bool compLt(T x, T y)
{
    return x < y;
}

template <typename T>
bool compGt(T x, T y)
{
    return x > y;
}

int count2(int x)
{
    int c = 0;
    while (x > 0)
    {
        c += (x % 10 == 2);
        x /= 10;
    }
    return c;
}

bool compNumberOf2s(int x, int y)
{
    return (count2(x) > count2(y));
}

void sort(int a[], unsigned n, Comparator<int> pComp)
{
    for(int i = 0; i < n-1; ++i)
    {
        unsigned extrRight = findExtr<int>(a+i,n-i,pComp);
        std::swap(a[i],a[i+extrRight]);
    }
}

template <typename T>
void printArray(const T a[], unsigned n)
{
    std::cout << "{";
    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void map(T a[], unsigned n, Operator<T> op)
{
    for(int i=0; i < n; ++i)
    {
        a[i] = op(a[i]);
    }
}

template <typename In, typename Out>
void map(In in[], Out out[], unsigned n, Out(*op)(In))
{
    for(int i=0; i < n; ++i)
    {
        out[i] = op(in[i]);
    }
}

bool even(int x)
{
    return x % 2 == 0;
}

template<typename T>
T plus(T x, T y)
{
    return x+y;
}

template<typename T>
T mult(T x, T y)
{
    return x*y;
}

int main()
{
    int ia[] = {1,2,3,2,1,12313,221,8878,2,22226252};
    double da[] = {1,2,3};
    char ca[] = {'1','2','3'};

    std::cout << fold(ia,5,0,plus) << std::endl;
    std::cout << fold(ia,5,1,mult) << std::endl;

    /*
    std::cout << sum(ia,3,sq) << std::endl;
    std::cout << sum(ia,3,cube) << std::endl;

    std::cout << sum(da,3,id) << std::endl;
    std::cout << sum(da,3,sq) << std::endl;
    std::cout << sum(da,3,cube) << std::endl;
    */


    std::cout << findExtr(ia,5,compLt) << std::endl;
    std::cout << findExtr(ia,5,compGt) << std::endl;
    
    std::cout << findExtr(ia,10,compNumberOf2s) << std::endl;


    std::cout << findExtr(ia,10,compLt) << std::endl;
    std::cout << findExtr(ia,10,compGt) << std::endl;


    printArray(ia,10);
    sort(ia,10,compLt);
    printArray(ia,10);
    sort(ia,10,compGt);
    printArray(ia,10);
    sort(ia,10,compNumberOf2s);
    printArray(ia,10);

    map(ia,10,p1);
    printArray(ia,10);

    bool tests[10] = {false};
    map(ia,tests,10,even);
    printArray(tests,10);

}



