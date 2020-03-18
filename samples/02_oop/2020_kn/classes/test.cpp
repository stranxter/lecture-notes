#include <iostream>


class A
{
    public:
    A (int _x):x(_x)
    {
        std::cout << "Init (" << x << ")!\n";        
    }
    A (const A &a)
    {   
        x = a.x;
        std::cout << "Copy (" << x << ")!\n";
    }
    
    ~A ()
    {
        std::cout << "Destruct (" << x << ")!\n";        
    }

    int x;
};

A f()
{
    A res(1);
    return res;
}

int main ()
{
    A a(0);
    a = f ();

    return 0;
}