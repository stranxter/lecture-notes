#include <iostream>

void i (int w)
{
    std::cout << "w" << std::endl;
}

void h (int z)
{
    std::cout << z << std::endl;
    z += 30;
}

void g (int y)
{
    h (y);
    i (y+1);
    std::cout << y << std::endl;
    y += 20;
}

void f (int x)
{
    g (x);
    std::cout << x << std::endl;
    x += 10;
}

int main ()
{
    f (5);
    return 0;
}