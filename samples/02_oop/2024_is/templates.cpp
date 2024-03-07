#include <iostream>

template <typename T>
void swap(T& x, T& y)
{
    T tmp = y;
    y = x;
    x = tmp;
}

template <typename T>
T sum(T a[], int size)
{
    T s = 0;
    for(int i = 0; i < size; ++i)
    {
        s += a[i];
    }
    return s;
}

template <typename T>
T prod(T a[], int size)
{
    T s = 1;
    for(int i = 0; i < size; ++i)
    {
        s *= a[i];
    }
    return s;
}


bool conj(bool a[], int size)
{
    bool s = false;
    for(int i = 0; i < size; ++i)
    {
        s = s && a[i];
    }
    return s;
}

bool disj(bool a[], int size)
{
    bool s = true;
    for(int i = 0; i < size; ++i)
    {
        s = s || a[i];
    }
    return s;
}

template <typename T>
T plus(T x, T y)
{
    return x+y;
}

int mult(int x, int y)
{
    return x*y;
}

template <typename T>
using BinaryFunction = T(*)(T,T);

template <typename T>
T reduce(T a[], int size, T init, BinaryFunction<T> op)
//T reduce(T a[], int size, T init, T(*op)(T,T))
{
    T result = init;
    for(int i = 0; i < size; ++i)
    {
        result = op(result,a[i]);    
    }   
    return result;
}


void f(int x)
{
    std::cout << "I AM AN INT!\n";
}

int f(double x)
{
    std::cout << "I AM A DOUBLE!\n";
    return 0;
}

double specialPlus45(double currentSum, double newElement)
{
    
    if(newElement > 4.5)
    {
      currentSum += newElement;
    }

    return currentSum;
}


int main()
{

    int a[] = {1,2,3,4,5};

    std::cout << reduce(a,5,0,plus) << std::endl;
    std::cout << reduce(a,5,1,mult) << std::endl;


    double d[] = {1.5,2,3,4.7,5};
    std::cout << reduce(d,5,0.0,plus) << std::endl;

    //сумата на тези елементи от масива, които са по-големи от 4.5
    std::cout << reduce(d,5,0.0,specialPlus45) << std::endl;



/*
    f(0);
    f(0.5);

    int x = 0, y = 1;
    swap(x,y);
    std::cout << x << ";" << y << std::endl;

    double xd = 0, yd = 1.5;
    swap(xd,yd);
    std::cout << xd << ";" << yd << std::endl;

    int arri[] = {1,2,3,4,5};
    std::cout << sum(arri,5) << std::endl;

    char arrc[] = {'A',' '};
    std::cout << sum(arrc,2) << std::endl;
*/
}