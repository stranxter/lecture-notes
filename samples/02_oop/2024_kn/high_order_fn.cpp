#include <iostream>
#include <cstring>
#include <functional>
#include <cassert>

std::function<double(double)> function_maker_sq(double a, double b, double c)
{
    //NEW FUNCITON x -> a*x*x + b*x + c;
    return [a,b,c](double x)->double{return a*x*x + b*x + c;};
}

const double delta = 0.00001;

//std::function<double(double)> derived(doube(*f)(double))
std::function<double(double)> derived(std::function<double(double)> f)
{
    return [f](double x)->double{return (f(x+delta)-f(x))/delta;};
}

double id(double x)
{
    return x;
}
double sq(double x)
{
    return x*x;
}
double something(double x)
{
    return x*x + 4*x;
}

template <typename T>
void map(T a[], int n, T(*f)(T))
{
    for(int i = 0; i < n; ++i)
    {
        a[i] = f(a[i]);
    }
}

int p1(int x)
{
    return x+1;
}

struct CallCounter
{
    int count;
    CallCounter()
    {
        count = 0;
    }
    //int call()
    int operator()()
    {
        ++count;
        return count;
    }
};

struct Increaser
{
    double a;
    Increaser(double _a)
    {
        a = _a;
    }
    double operator()(double x)
    {
        return x+a;
    }
};

std::function<double(double)> make_increaser(double a)
{
    return [a](double x)->double{return x+a;};
}

std::function<double(double)> compose(std::function<double(double)>f,
                                      std::function<double(double)>g)
{
    return [f,g](double x)->double{return f(g(x));};
}

using dfn = std::function<double(double)>;

template <typename T>
std::function<T(T)> repeat(std::function<T(T)> f, unsigned int k)
{
   return [f,k](T x)->T
   {
        //f,k -> f(f(f(..k(x))))
        for(int i = 0; i < k; ++i)
        {
           x=f(x); 
        }
        return x;
   }; 
}

//fnPower(f,k)(x) -> f(x)*f(x)*....*f(x)
//                    |----------k-------|

dfn fnPower(dfn f,unsigned int k)
{
    return [f,k](double x)->double
    {
        double prod = 1;
        for(int i = 0; i < k; ++i)
        {
            prod *= f(x);
        }
        return prod;
    };
}

template <typename T>
struct Pair
{
    T key; T value;
};

template<typename T>
std::function<T(T)> make_function(Pair<T> pairs[], int n)
{
    return [pairs,n](T x)->T
    {
        for(int i = 0; i < n; ++i)
        {
            if(x==pairs[i].key)
            {
                return pairs[i].value;
            }
        }
        assert(false);
        return T();
    };
}

int main()
{

    Pair<int> pairs[] = {{0,1},{2,4},{6,34},{12,44},{20,3},{3,10},{23,23},{1,0}};

    
    std::function<int(int)> myFn = make_function(pairs,8);

    std::cout << myFn(12) << std::endl;
    std::cout << myFn(20) << std::endl;


    int a[] = {1,2,3,4,5};
    map<int>(a,5,[](int x)->int{return x+1;});

    char myName[] = "Kalin"; //Lbmjo
    map<char>(myName,strlen(myName),[](char x)->char
     {if (x>='A' && x <='Z') 
        return x-('A'-'a'); 
      return x;
     });
    std::cout << myName << std::endl;


    std::cout << p1(0) << std::endl;
    std::cout << [](int x)->int{return x+1;}(0) << std::endl;


    std::function<double(double)> f1 = function_maker_sq(0,1,1), 
                                  f2 = function_maker_sq(1,0,1), 
                                  f3 = function_maker_sq (1,1,1);

    std::cout << f1(2) << std::endl;
    std::cout << f2(2) << std::endl;
    std::cout << f3(2) << std::endl;



    std::cout << id(1) << std::endl;
    std::cout << sq(1) << std::endl;
    std::cout << something(1) << std::endl; //x^2+4x


    std::cout << derived(id)(1) << std::endl;
    std::cout << derived(sq)(1) << std::endl;
    std::cout << derived(something)(1) << std::endl; //x^2+4x

    CallCounter c1,c2;

    c1();c1();c1();c1();
    c2();c2();

    std::cout << c1() << std::endl;
    std::cout << c2() << std::endl;

    Increaser i1(2), i2(5);

    std::cout << i1(0) << std::endl;
    std::cout << i2(0) << std::endl;

    std::function<double(double)> _i1 = make_increaser(2),
                                  _i2 = make_increaser(5);

    std::cout << _i1(10) << std::endl;
    std::cout << _i1(3) << std::endl;
    std::cout << _i1(4) << std::endl;
    std::cout << _i1(1) << std::endl;
    std::cout << _i1(7) << std::endl;
    std::cout << _i2(0) << std::endl;

    std::cout << "d=" << derived(i2)(100) << std::endl;

    std::cout << compose(sq,id)(10) << std::endl;
    std::cout << compose(derived(sq),id)(10) << std::endl;


    std::cout << repeat<double>(id,2000)(10) << std::endl;
    std::cout << repeat<double>(sq,2)(2) << std::endl;


    std::cout << derived(derived(sq))(200) << std::endl;
    std::cout << repeat<dfn>(derived,2)(sq)(200) << std::endl;

    std::cout << fnPower(sq,2)(2) << std::endl;



}