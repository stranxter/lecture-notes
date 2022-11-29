#include <iostream>

void printSeq(int n)
{
    
    std::cout << n << std::endl;
    if (n>0)
    {
        printSeq(n-1);
    }
    
}

void f(int a, int b)
{
    int z;
    printSeq(a);
    std::cout << a << std::endl;
}

int enterNumber(int min, int max)
{
    
    int n;
    do
    {    
        std::cout << "Please enter a number between " << min << " and " << max << ":";

        std::cin >> n;

    }
    while(n < min || n > max);

    return n;
}

int enterNumberRec(int min, int max)
{
    int n;
    std::cout << "Please enter a number between " << min << " and " << max << ":";
    std::cin >> n;    
    if(n >= min && n <= max)
    {
        return n;
    }
    return enterNumberRec(min,max);
}

int main()
{
    int m = 0;
    f(2, 3);

    std::cout << enterNumberRec(0,100);// / enterNumberRec(1,100);
}