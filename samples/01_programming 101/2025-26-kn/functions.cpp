#include <iostream>


void ps(int n)
{

    std::cout << n << " ";
    if(n > 0)
    {
        ps(n-1);
    }
    std::cout << n << " ";
    
}

void printdigits(int x)
{

    char digits[100] = {0};
    int currentdigit = 0;

    while(x > 9)
    {
        digits[currentdigit] = x % 10 + '0';
        x /= 10;
        ++currentdigit;
    }
    
    digits[currentdigit] = x + '0';

    while (currentdigit >= 0)
    {
        std::cout << digits[currentdigit];
        --currentdigit;
    }

    std::cout << "\n";
}

void printdigitsrec(int x)
{
    if(x < 10)
    {
        std::cout << x << " ";
        return;
    }

    printdigitsrec(x / 10);
    std::cout << x % 10 << " ";
}

int enternumber(int from, int to)
{
    int result;
    std::cout << "Please enter a number between " << from << " and " << to << ":";
    std::cin >> result;

    while(result < from || result > to)
    {
        std::cout << "Please enter a number between " << from << " and " << to << ":";
        std::cin >> result;
    }

    return result;
}

int enternumberrec(int from, int to)
{
    int result;
    std::cout << "Please enter a number between " << from << " and " << to << ":";
    std::cin >> result;
    
    if(result >= from && result <= to)
    {
        return result;
    }

    return enternumberrec(from,to);
}

int fib(int n)
{
    if(n < 2)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int sumdig(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return sumdig(n/10) + n%10;
}

bool hasdigit(int x, int k)
{

/*
    if(x == k)
    {
        return true;
    }

    if(x < 10)
    {
        return false;
    }
*/
    //return hasdigit(x/10,k) || x%10 == k;
    
    return x%10 == k || (x > 0 && hasdigit(x/10,k));
}

int sumrange(int from, int to)
{//sorry, Herr Gauss
    if(from>to)
    {
        return 0;
    }

    return sumrange(from+1,to) + from;
}

int main()
{
    //ps(4);
    //printdigits(1234);
    //printdigitsrec(1234);

    //std::cout << enternumber(2,100) / enternumber(2,100) << std::endl;

    //std::cout << fib(5) << std::endl;

    std::cout << hasdigit(123456,8) << std::endl;

    return 0;
}