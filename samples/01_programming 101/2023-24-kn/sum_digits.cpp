#include <iostream>

int main()
{

    int x, save;
    std::cout << "Моля въведете x=";
    std::cin >> x;

    int sum = 0;
    save = x;
    while (x > 0)
    {
        sum = sum + (x % 10);
        x = x / 10;
    }

    std::cout << "Числото " << save << " има сума на цифрите=" << sum << ".";


    return 0;
}