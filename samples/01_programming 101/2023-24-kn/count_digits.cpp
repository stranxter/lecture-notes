#include <iostream>

int main()
{

    int x, save;
    std::cout << "Моля въведете x=";
    std::cin >> x;

    if (x < 10)
    {
        std::cout << "Числото " << x << " има 1 цифра.";
    } else 
    {
        int count = 0;
        save = x;
        while (x > 0)
        {
            x = x / 10;
            ++count;
        }

        std::cout << "Числото " << save << " има " << count << " цифри.";

    }

    return 0;
}