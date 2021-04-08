#include <iostream>
#include <cassert>
#include <functional>

int sum (int a, int b)
{
    return a+b;
}

int avg (int a, int b)
{
    return (a+b)/2;
}

int f (int x, char z)
{
    return x;
}

template <typename T>
using Comparator = bool (*) (T, T);


template <typename T>
int findExtremalElement (T a[], 
                         int size, 
                         std::function<bool(T,T)> compare)
{
    int index = 0;
    for (int current = 1; current < size; ++current)
    {
        if (compare(a[current],a[index]))
        {
            index = current;
        }
    }

    return index;
}

bool compareGt(int x, int y)
{
    return x > y;
}

bool compareLt(int x, int y)
{
    return x < y;
}

Comparator<int> fromOperator(char symbol)
{
    switch (symbol)
    {
        case '<': return compareLt;
        case '>': return compareGt;
        
        default: return compareLt;

    }
}

bool compareLargestLastDigit(int x, int y)
{
    return x % 10 > y % 10;
}

class Increase
{
    public:
    
    Increase(int i):incWith(i){}

    int operator() (int x) {return x + incWith;}
    int f          (int x) {return x + incWith;}

    private:
    int incWith;
};

int cube(int x)
{
    return x*x*x;
}

using doublefn = std::function<double(double)>;
doublefn operator * (doublefn f, doublefn g)
{
    return [f,g](double x)->double{return f(g(x));};
}

/*
    std::function<double(double)> q1 = quadr(5,0,0),
                                  q2 = quadr(7,0,1),
                                  q3 = quadr(1,2,3);

    q1(3);
*/
std::function<double(double)> quadr(double a, double b, double c)
{
    return [a,b,c](double x)->double{return a*x*x + b*x + c;};
}


int main()
{


   
    int a[] = {245,35,3623,434,649,75,2345,2,563};

    std::cout << findExtremalElement<int>(a,8,[](int x, int y)->bool{return x > y;}) << std::endl;
    std::cout << findExtremalElement<int>(a,8,compareLt) << std::endl;
    std::cout << findExtremalElement<int>(a,8,compareLargestLastDigit) << std::endl;



    fromOperator('<')(1,2);


    int (*pfn)(int,int);

    pfn = sum;
    sum(1,2);
    pfn(1,2);

    std::cout << ([](int x, int y)->bool{return x > y;}) (1,2) << std::endl;

    Increase inc1(1), inc2(2), inc5(5);


    std::cout << inc1(5) << std::endl;
    std::cout << inc1.operator()(5) << std::endl;
    std::cout << inc2(5) << std::endl;
    std::cout << inc5(5) << std::endl;

    std::function<int(int)> f;

    f = inc5;
    f = [](int x)->int{return x*2;};
    f = cube;


    std::function<double(double)> q1 = quadr(5,0,0),
                                  q2 = quadr(7,0,1),
                                  q3 = quadr(1,2,3);

    std::cout << q1(5) << std::endl;
    std::cout << q2(5) << std::endl;
    std::cout << q3(5) << std::endl;


    std::cout << (inc1*inc2)(5) << std::endl;




    //doctest::Context().run();
}


