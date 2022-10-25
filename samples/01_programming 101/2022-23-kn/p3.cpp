#include <iostream>

int main()
{

    int n;

    int a[100], b[100];    
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Моля, въведете " << i << "-тото число:";
        std::cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }

    std::cout << sum / n << std::endl;



}