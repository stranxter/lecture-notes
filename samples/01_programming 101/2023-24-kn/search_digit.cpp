#include <iostream>

int main()
{

    int x, save;
    std::cout << "Моля въведете x=";
    std::cin >> x;

    int sum = 0;

    while(x > 0 && x % 10 != 5)   
    {
        x = x / 10;
    }
    
    if(x > 0)
    {
        std::cout << "Числото има цифрата 5!";        
    } else
    {
        std::cout << "Числото НЯМА цифрата 5!";
    }


/*    int count_5 = 0;
    while (x > 0)
    {
        if(x % 10 == 5)
        {
            ++count_5;
        } 
        x = x / 10;
    }

    if (count_5 > 0)
    {
        std::cout << "Числото има цифрата 5!";
    } else
    {
        std::cout << "Числото НЯМА цифрата 5!";
    }
*/
    return 0;
}