#include <iostream>
#include <iomanip>
#include <functional>

template <typename T>
using BinOp = T(*)(T,T);

//агрегиране на елементите на масив чрез двуместна операция
//(събиране, умножеснир и др.)
template <typename T>
T reduce(T arr[], unsigned size, BinOp<T> op, T null_val)
{
    T result = null_val;
    for (int i = 0; i < size; ++i)
    {
        result = op(result,arr[i]);
    }

    return result;
}


int plus(int x, int y)
{
    return x+y;
}

int mult(int x, int y)
{
    return x*y;
}

BinOp<int> choice (char op)
{
    switch (op)
    {
        case '+':return plus;
        case '*':return [](int x, int y)->int{return x*y;};
        
        default: return plus;
    }
}

using Op = int(*)(int);


void map(int arr[], unsigned size, std::function<int(int)> op)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = op(arr[i]);
    }
}

int print(int x)
{
    std::cout << x << " ";
    return x;

}
class increaser
{
    public:

    increaser(int _toadd){toadd = _toadd;}

    int operator()(int x)
    {
        return x+toadd;    
    }

    private:
    int toadd;
};

int inc(int x)
{
    return x+1;
}

std::function<int(int)> repeated(std::function<int(int)> f, unsigned k)
{
    return [f,k](int x)->int
    {
        for(int i = 0; i < k; ++i)
        {
            x = f(x);
        }

        return x;
    };

}

std::function<int(int)> incf(int toadd)
{
    return [toadd](int x)->int{return x+toadd;};
}

template<typename T>

std::function<T(T)> maxf(std::function<T(T)>f, 
                         std::function<T(T)>g)
{
    return [f,g](T x)->T {return std::max(f(x),g(x)); };
}

std::function<double(double)> operator*(std::function<double(double)>f, 
                                        std::function<double(double)>g)
{
    return [f,g](double x)->double {return g(f(x));};
}

std::function<double(double)> derive(std::function<double(double)> f, double d=0.001)
{
    return [f,d](double x)->double{return (f(x+d)-f(x))/d;};
}

int main()
{

    std::function<double(double)> d1 = derive([](double x)->double{return x*x;});
    std::function<double(double)> d2 = derive([](double x)->double{return x*x*x;});

    std::cout << d1(1) << " " << d2(1) << std::endl;

    std::cout << ([](double x)->double{return x*x;} * [](double x)->double{return x*x*x;})(10) 
              << std::endl;


    std::function<int(int)> f1,f2;
    f1 = incf(10);
    f2 = incf(20);
    std::cout << f1(100) << " " << f2(100) << std::endl;


    std::cout << repeated(inc,100)(0) << std::endl;

    int a[] = {1,412,3562,47,8,76234,1245,124,235,36,4};

    increaser i7(7), i10(10);

    std::cout << i10(10);

    map(a,11,repeated(inc,100));   
    map(a,11,i7);   
    map(a,11,i10);

    map(a,11,[](int x)->int{return x*10;});

    std::function<int(int)> f;

    f = inc;
    f = i7;
    f = [](int x)->int{return x*10;};

    f(10);

    std::cout << choice('+')(1,2) << std::endl;
    //::cout << pow(5)(2) << std::endl;

    double da[] = {1.0,2.0,3.5,4.7,5};

    map(a,11,print);
    std::cout << std::endl;
    map(a,11,[](int x)->int{std::cout << x << " "; return x;});
    std::cout << std::endl;

    std::cout << reduce<int>(a,11,[](int x, int y)->int{return x+y;},0) << std::endl;
    std::cout << reduce<int>(a,11,[](int x, int y)->int{return x*y;},1) << std::endl;
    std::cout << reduce<int>(a,11,[](int x, int y)->int{return std::min(x,y);},a[0]) << std::endl;

    std::cout << reduce<double>(da,11,[](double x, double y)->double{return x+y;},0.0) << std::endl;


/*

    int(*p)(int,int);

    p = plus;

    std::cout << p(2,3) << std::endl;

    p = mult;

    std::cout << p(2,3) << std::endl;

    std::cout << std::hex << ((long*)plus)[0] << std::endl;
*/

}


