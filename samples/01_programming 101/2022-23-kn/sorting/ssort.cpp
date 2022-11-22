#include <iostream>

const int n = 5;

void printArray(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}


int main()
{
    int arr[n] = {7,2,1,10,3};

    for (int sortedN = 0; sortedN < n; ++sortedN)
    {
        int indexMinUnsorted = sortedN; //това е индексът на 
                                        //първият от несортираните елементи
        for(int i = sortedN+1; i < n; ++i)
        {
            if(arr[i]<arr[indexMinUnsorted])
            {
                indexMinUnsorted=i;
            }
        }
        //indexMinUnsorted е индексът на най-малкия елемент
        //измежду[sortedN..n]

        int save = arr[sortedN];
        arr[sortedN]=arr[indexMinUnsorted];
        arr[indexMinUnsorted]=save;
    }

    printArray(arr,n);
}