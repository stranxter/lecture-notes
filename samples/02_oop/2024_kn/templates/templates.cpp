#include <iostream>
#include <iomanip>

void decorateInt(int x)
{
    std::cout << x << "; ";
}

void decorateDouble(double x)
{
    std::cout << std::fixed << std::setprecision(2) << x << "; ";
}

void decorateString(const char *s)
{   
    std::cout << "\"" << s << "\"; ";
}

template <typename T>
using Decorator = void(*)(T);

template <typename T>
void printArray(T a[], size_t n, Decorator<T> decorate)
{
    for(size_t i = 0; i < n; ++i)
    {
        decorate(a[i]);
    }
    std::cout << std::endl;
}

struct S
{
    int a,b;
};

void decorateStucts(S s)
{
    std::cout << "{" << s.a << "," << s.b << "}";
}


template <typename T>
void map(T a[], size_t n, T(*f)(T))
{
    for(size_t i = 0; i < n; ++i)
    {
        a[i] = f(a[i]); //за случая на inc: a[i] = inc(a[i]); a[i] = a[i]+1
    }
}

template <typename T>
T inc(T x)
{
    return x+1;
}

template <typename T>
T m2(T x)
{
    return x*2;
}

int printEvens(int x)
{
    if(x % 2 == 0)
    {
        std::cout << x << " ";
    }
    return x;
}

int yoanOperation(int x)
{
    if(x % 3 == 0)
    {
        return x * 8;
    }
    return 0;
}

//std::cout << repeat(inc<int>,3,10) << std::endl;

int repeat(int(*f)(int),int k, int x)
{
    for(int i = 0; i < k; ++i)
    {
        x=f(x);
    }
    return x;
}

int sq(int x)
{
    return x*x;
}

int main()
{
    int a[] = {1,2,3};
    std::cout<<"original:";
    printArray(a,3,decorateInt);

    map(a,3,inc);
    std::cout<<"plus one:";
    printArray(a,3,decorateInt);

    std::cout<<"evens:";
    map(a,3,printEvens);

    map(a,3,m2);
    std::cout<<"multiplied:";
    printArray(a,3,decorateInt);

    map(a,3,yoanOperation);
    std::cout<<"Yoan:";
    printArray(a,3,decorateInt);

    double b[] = {1.0,2.0,3.0};
    printArray(b,3,decorateDouble);
    map(b,3,inc);

    const char* strings[] = {"Hello", "world,", "have", "a nice", "day"};
    printArray(strings,5,decorateString);

    S structs[] = {{1,2},{2,3},{3,1}};
    printArray(structs,3,decorateStucts);

    //f(f(f(f(f...(x))))), k
    //f = inc
    //k = 3
    //->x+3
    std::cout << repeat(inc<int>,3,10) << std::endl;

    //f = sq
    //k = 2
    //->x ^ 4
    std::cout << repeat(sq,2,10) << std::endl;
 
}