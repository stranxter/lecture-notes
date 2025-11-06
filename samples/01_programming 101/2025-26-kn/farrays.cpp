#include <iostream>


int sum(int a[],int n)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
        a[i] = 0;
    }


    return sum;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int arr2[6]={1,2,3,4,5,6};

    std::cout << sum(arr,5) << std::endl;
    std::cout << sum(arr,5) << std::endl;


    int x = 10, y = 20;

    int *pint = &x;

    *pint = 0;

    pint = &y;

    y = *(&x);


}