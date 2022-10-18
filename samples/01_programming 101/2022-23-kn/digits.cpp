#include <iostream>


int main()
{

    int number;

    std::cout << "Моля, въведете естествено число:";
    std::cin >>  number;

    int counter = 0;
    int sum = 0;
    int count5s = 0;

    //[1 2 3 4 5] [6] 
    
    
    do {
        if (number%10 == 5)
        {
            ++count5s;
        }
        sum = sum + number % 10;
        number = number / 10;
        ++counter;
    } while (number > 0);

    /*sum = sum + number;
    if (number%10 == 5)
    {
        ++count5s;
    }*/

    std::cout << counter << std::endl;
    std::cout << sum << std::endl;
    if (count5s > 0)
    {
        std::cout << "Има ";
    } else {
        std::cout << "Няма ";
    }
    std::cout << "петици" << std::endl;

    return 0;
}