#include <iostream>

void printArray(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

void merge(int arr1[], int size1,
           int arr2[], int size2,
           int result[])
{
    int ix1 = 0,
        ix2 = 0;
    
    while(ix1 < size1 && ix2 < size2)
    {
        if(arr1[ix1] < arr2[ix2])
        {
            result[ix1+ix2] = arr1[ix1];
            ++ix1;
        } else {
            result[ix1+ix2] = arr2[ix2];
            ++ix2;
        }
    }
    while(ix1 < size1)
    {
        result[ix1+ix2] = arr1[ix1];
        ++ix1;
    }
    while(ix2 < size2)
    {
        result[ix1+ix2] = arr2[ix2];
        ++ix2;
    }
}

int main()
{
    int arr1[] = {1,5,7,9,10,20,100},
        arr2[] = {2,3,11,12,1000},
        result[12] = {0};

    merge(arr1,7,arr2,5,result);

    printArray(result,12);

    
}