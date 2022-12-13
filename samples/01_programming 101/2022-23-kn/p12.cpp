#include <iostream>


void print_divs_iter (int n) 
{
    while (n > 1)
    { 
     
        int i = 2;
        while (i <= n && n % i != 0)
        {
            i++;
        }

        std::cout << i << ",";
        n /= i;
    }
}

void print_divs (int n) 
{
    if (n <= 1) 
        return;
    int i = 2;
    while (i <= n && n % i != 0)
    {
        i++;
    }

    print_divs(n/i); 
    std::cout << i << ",";
}

int main()
{
    print_divs(351509);
    std::cout << std::endl;
    print_divs_iter(351509);
}
