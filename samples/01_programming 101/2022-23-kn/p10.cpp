#include <iostream>


void f(int &p)
{
    p=10;
    std::cout << p << std::endl;
}


int main()
{
    int x = 0;
    f(x);
    std::cout << x << std::endl;
}