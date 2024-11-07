#include <iostream>


void f(int x)
{
    x = x + 1;
}

void g(int x[1])
{
    x[0] = x[0] + 1;
}

void ps(int N)
{
    std::cout << N << " ";
    if(N > 0)
    {
        ps(N-1);
    }
    std::cout << N << " ";
}
//     x:123         |    x:12      |     x:1         |       x:0
//print10rec(123) -> print10rec(12) -> print10rec (1) - > print10rec(0)

void print10rec(int x)
{
    if(x > 0)
    {
        std::cout << x % 10 << "->";
        print10rec(x / 10);
        std::cout << x % 10 << "<-";
    }
}

void print10(int x)
{
    while(x > 0)
    {
        std::cout << x % 10 << " "; 
        x /= 10;
    }
}

int main()
{
    /*
    int x = 0;
    f(x);

    int arr[1] = {0};
    g(arr);

    std::cout << x << std::endl;
    std::cout << arr[0] << std::endl;

    */

   ps(120);
   std::cout << std::endl;
   print10(1234);
   std::cout << std::endl;
   print10rec(1234);
}