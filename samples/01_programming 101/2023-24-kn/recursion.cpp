#include <iostream>


//0, 2, 6, 12, 20, ..
//a[i+1] = a[i] + 2(i+1)

int get_and_print_first_n(int n)
{
    if(n == 0)
    {
        return 0;
    }

    int previous_member = get_and_print_first_n(n-1);
    std::cout << previous_member + 2*n << " ";
    return previous_member + 2*n;
}

int fib(int n)
{
    //1 1 2 3 5 8 13 ...
    int a,b,count;
    a = 1;
    b = 1;
    count = 1;

    int prev_a;
    while (count < n)
    {
        prev_a = a;
        a = b;
        b = prev_a + b;
        ++count;
    }

    return a;    
}

void print_divisors(int n)
{
    if(n <= 1)
    {
        return;
    }

    int divisor = 2;
    while (n % divisor != 0)
    {
        ++divisor;
    }

    std::cout << divisor << " ";
    print_divisors(n / divisor);    

}

int main()
{
    get_and_print_first_n(10);
    std::cout << std::endl;
    print_divisors(351509);
}