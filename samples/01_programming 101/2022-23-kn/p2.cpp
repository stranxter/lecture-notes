#include <iostream>

int main()
{
    int a = 7, b = 8, c = 9;

    std::cout << "Моля, въведете a=";
    std::cin >> a;

    std::cout << "Моля, въведете b=";
    std::cin >> b;

    std::cout << "magic=" << (a==b) << std::endl;

    if (a==b)
    {
        std::cout << "Браво, уцели!" << std::endl;
    } else {
        std::cout << "Sorry, не уцели!" << std::endl;
    }

  
}