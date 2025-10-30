#include <iostream>

const int n = 5;

int main()
{

    int arr[2][n] = {0,10,15,20,50,
                     2,3,30,60,70};

/*
    for(int currentArray = 0; currentArray < 2; ++currentArray)
    {
        for(int i = 0; i < n; ++i)
        {
            std::cout << "Моля, въвдете " << i << "-то число от " << currentArray <<"-тия масив:";
            std::cin >> arr[currentArray][i];

        }
    }
*/

    int result[2*n] = {0};

    int i1=0,i2=0;

    while(i1 < n || i2 < n)
    {
        if(i1 < n && arr[0][i1] < arr[1][i2])
        {
            result[i1+i2] = arr[0][i1];
            ++i1;
        } else
        {
            result[i1+i2] = arr[1][i2];
            ++i2;
        }
    }

    std::cout << "[";

    for(int i = 0; i < 2*n; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << "]\n";


    return 0;
}