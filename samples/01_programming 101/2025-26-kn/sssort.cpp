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

    for(int i = 0; i < n; ++i)
    {
        /*Всички елементи вляво от i-тия са подредени и са 
          по-малки или равни от останалите ("готови")
        */

        //1. Намирам най-малкия от оставащите

        int minIndex = i;

        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        //minInded е индексът на най-малкия елемент от "неготовите"
        //2. Разменяме местата на arr[i] и arr[minIndex]
        int save = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = save;

    }


    std::cout << "[";

    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";

}

