#include <iostream>


unsigned int fib(unsigned int n)
{
    unsigned a = 1, b = 1;
    
    for(int i = 0; i < n-1; i++)
    {
        unsigned int nextb = a + b;
        a = b;
        b = nextb;
    }

    return b;

}

void divisors(unsigned int n)
{

    if(n < 2)
        return;

    int p = 2;
    while (n % p > 0)
    {
        ++p;
    }

    std::cout << p << " ";
    divisors(n/p);

}

int main()
{
    std::cout << fib(5) << std::endl;
    divisors(56756567);

    std::cout << std::endl;
}