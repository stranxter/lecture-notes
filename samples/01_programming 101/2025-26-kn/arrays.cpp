#include <iostream>

const int n = 10;

int main()
{

    int arr[n] = {0};

    for(int i = 0; i < n; ++i)
    {
        std::cout << "Моля, въвдете " << i << "-то число:";
        std::cin >> arr[i];

    }

    //търсенена СТОЙНОСТТА на минималния елемент
    //търсенена ПОРЕДНИЯ НОМЕР на минималния елемент (един от тях)

    int minIndex = 0;

    for(int i = 1; i < n; ++i)
    {
        if(arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }

    std::cout << "min=" << arr[minIndex] << "; index=" << minIndex << std::endl;

    //Поредния номер на първата тройка в масива (ако има)

    //[1 4 5 6 3 4 5 6 3 4 5 6]

    int i = 0;

    while(i < n && arr[i] != 3)
    {
        ++i;
    }

    if(i == n)
    {
        std::cout << "Няма тройки в масива.\n";
    } else 
    {
        std::cout << "Three index=" << i << std::endl;
    }
    


}