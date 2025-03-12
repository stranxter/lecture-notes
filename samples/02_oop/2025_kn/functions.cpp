#include <iostream>
#include <functional>

struct Kalin
{
    int operator()()
    {return 1;}
    double operator()(double x,double y)
    {
        return x+x*y;
    }
};



std::function<double(double,double)> apply(char c)
{
    Kalin k;
    switch(c)
    {
        case '+' : return [](double x, double y)->double{return x+y;};
        case '-' : return [](double x, double y)->double{return x-y;};
        case '*' : return [](double x, double y)->double{return x*y;};
        case '/' : return [](double x, double y)->double{return x/y;};
        case '$' : return k;
        default: return nullptr;
    }
}

std::function<double(double)> makePower(unsigned n)
{
    return [n](double x)->double
      {
        double result = 1;
        for(int i = 0; i < n; ++i)
        {
            result *= x;
        }
        return result;
      };
}

class Power
{
    public:
    Power(unsigned n)
    {
        p=n;
    }
    double operator()(double x)
    {
        double result = 1;
        for(int i = 0; i < p; ++i)
        {
            result *= x;
        }
        return result;        
    }

    private:
    unsigned p;

};

class CallCounter
{
    public:
    CallCounter(){count  = 0;}

    unsigned operator()()
    {
        return count++;
    }

    private:
    unsigned count;
};

int main()
{

    Kalin kalin;
    std::cout << kalin() << std::endl;

    CallCounter c1,c2;

    std::cout << c1() << std::endl;
    std::cout << c1() << std::endl;
    std::cout << c1() << std::endl;
    std::cout << c1() << std::endl;
    std::cout << c1() << std::endl;

    std::cout << c2() << std::endl;
    std::cout << c2() << std::endl;

    std::cout << ([](double x, double y)->double{return x+y;}) (1,2) << std::endl;


    std::cout << "Dear user, please enter an operation:";
    char c;
    std::cin >> c;

    std::cout << "Result = " << apply(c)(21,2) << std::endl;


    std::function<double(double)> sq,cube,p4,p6;
    sq = makePower(2);
    cube = makePower(3);
    p4 = makePower(4);
    p6 = makePower(6);

    std::cout << cube(4) << std::endl;

    std::cout << makePower(8)(3) << std::endl;

    Power _sq(2),
          _cube(3);

    std::cout << _cube(4) << std::endl;




}