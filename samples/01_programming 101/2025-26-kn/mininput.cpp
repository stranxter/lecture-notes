#include <iostream>


const int n = 5;

int main()
{
    std::cout << "Моля, въведете нулевото поредно число:";
    int min;
    std::cin >> min;

    for(int i = 1; i < n; ++i)
    {
        int x;
        std::cout << "Моля, въведете " << i << "-тото поредно число:";
        std::cin >> x;

        if(x < min)
        {
            min = x;
        }
    }

    std::cout << "Минимален елемент=" << min << std::endl;

}