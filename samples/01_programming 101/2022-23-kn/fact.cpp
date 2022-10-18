#include <iostream>


int main()
{
    int number;

    std::cout << "Моля, въведете естествено число:";
    std::cin >>  number;

    //number! = 1 * 2 * 3 * 4 * ... * number

    // 1 * 2 * 3 * 4 * 5

    int prod=1;

    while(number > 1)
    {
        prod = prod * number;
        --number;
    }

    std::cout << prod << std::endl;
}