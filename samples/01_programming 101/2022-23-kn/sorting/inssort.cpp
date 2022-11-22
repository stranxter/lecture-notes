#include <iostream>

const int n  = 5;

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
    int arr[n] = {0};

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        //тук ще определим желания индекс за новия елемент
        int index = 0;

        if (arr[0] < x)
        {
            while( index < i &&
                  (arr[index-1]>=x || x > arr[index]))
            {
                ++index;
            }
        }

        for (int toMove = i; toMove >= index; --toMove)
        {
            arr[toMove+1] = arr[toMove];
        }

        arr[index] = x;

    }

    printArray(arr,n);

}