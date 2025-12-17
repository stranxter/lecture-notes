#include<vector>
#include<iostream>

struct s{int a;};

template <typename T>
T sum(std::vector<T> v)
{
    T sum = 0;
    for(T x : v)
    {
        sum += x;
    }
    return sum;
}


class A
{
    public:
    int x;
    int y;
    virtual int f(){return 0;}
};

class B : public A
{
    public:
    int z;
    int w;
    int f(){return 1;}
};

class C : public A
{
    public:
    int u;
    int q;
    int f(){return 10;}
};


void printA(A* a)
{
    std::cout << a->f() << std::endl;
}


template <typename T>
struct optional
{
    T value;
    bool real;
};

int main()
{

    B b; C c;
    printA(&b);
    printA(&c);

    return 0;

    std::vector<int> vi = {1,2,3};
    std::vector<double> vd = {1.0,2.0,3.0};
    std::vector<s> vs;

    std::cout << sum(vi) << std::endl;
    std::cout << sum(vd) << std::endl;

    std::cout << 7 << std::endl;
    std::cout << 7.123 << std::endl;
}