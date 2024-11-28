#include <iostream>


void f(int x)
{
    x += 10;
    std::cout << "x="  << x << std::endl;
}
void g(int *p)
{
    //p=1010101010101;
    p--;
    *p+=90;
    std::cout << "x="  << *p << std::endl;
}

int sum(int pa[], unsigned size)
//int sum(int *pa, unsigned size)
{
    int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += pa[i];
    }

    std::cout << "sizeof(pa[0])=" << sizeof(pa[0]) << std::endl;
    std::cout << "sizeof(pa)=" << sizeof(pa) << std::endl;

    return sum;
}

bool binsearch(int *a, unsigned size, int x)
{
    unsigned left = 0, right = size; //right - left = subarray size

    while (left < right && a[(left+right)/2] != x)
    {
        if(a[(left+right)/2] < x)
        {
            left = (left+right)/2 +1;
        } else 
        {
            right = (left+right)/2;
        }
    }
    return left<right;
}

bool binsearchr(int *a, unsigned size, int x)
{
    if(size == 0)
    {
        return false;
    }
    if(a[(size/2)] == x)
    {
        return true;
    }
    if(x < a[(size/2)])
    {
        return binsearchr(a,size/2,x);
    } else 
    {
        return binsearchr(a+(size/2)+1,(size-1)/2,x);
    }
}

/*
  size = 4
  size/2 = 2
  newsize = (size-1)/2 = 1
  [] [] [X] []

  size = 5
  size/2 = 2
  newsize = (size-1)/2 = 2
  [] [] [X] [] []
*/



int main()
{

    int a = 0, b = 1;
    char c = 65;

    int *p = &a;

    *p = 100;

    std::cout << "a="  << a << std::endl;

    f(a);
    g(p); //g(&a)

    std::cout << "a="  << a << std::endl;
    std::cout << "b="  << b << std::endl;
    std::cout << "c="  << (int)c << std::endl;

    std::cout << "p="  << (long)p << std::endl;
    std::cout << "p="  << (long)(&b) << std::endl;
    std::cout << "p="  << (long)(&c) << std::endl;

    int arr[4]= {1,2,3,4};

    p = &arr[0];
    std::cout << "p="  << (long)p << std::endl;
    p = &arr[1];
    std::cout << "p="  << (long)p << std::endl;
    *p = 100;
    std::cout << "arr[1]="  << arr[1] << std::endl;

    p=arr;
    *arr = 101; // *arr <=> arr[0]
    std::cout << "arr[0]="  << arr[0] << std::endl;

    //p==1000
    std::cout << "p="  << (long)p << std::endl;
    p++;
    std::cout << "p="  << (long)p << std::endl;
    //p==1001

    *(arr+2) = 100;
    arr[2] = 100;

    char *pc = (char*)100;

    std::cout << "pc="  << (long)pc << std::endl;
    pc++;
    std::cout << "pc="  << (long)pc << std::endl;


    long *pl = (long*)arr;

    std::cout << "pl="  << (long)pl << std::endl;
    pl++;
    std::cout << "pl="  << (long)pl << std::endl;
    
    //int arr[4]= {1,2,3,4};
    *pl = 0;
    std::cout << "arr[0]="  << arr[0] << std::endl;
    std::cout << "arr[1]="  << arr[1] << std::endl;
    std::cout << "arr[2]="  << arr[2] << std::endl;
    std::cout << "arr[3]="  << arr[3] << std::endl;

    p = &arr[2];
    p[-2]=9;
    std::cout << "arr[0]="  << arr[0] << std::endl;
    std::cout << "arr[1]="  << arr[1] << std::endl;
    std::cout << "arr[2]="  << arr[2] << std::endl;
    std::cout << "arr[3]="  << arr[3] << std::endl;

    std::cout << "sum(arr)=" << sum(arr,100) << std::endl;

    int arr2[10] = {0,10,20,30,40,50,60,70,80,90};
    std::cout << "sizeof(arr2)=" << sizeof(arr2) << std::endl;

    std::cout << "sum(arr2)=" << sum(arr2+2,5) << std::endl;

    std::cout << "found = " << binsearch(arr2,10,91) << std::endl;
    std::cout << "found = " << binsearchr(arr2,10,91) << std::endl;
    std::cout << "sizeof(unsigned)= " << sizeof(unsigned) << std::endl;

    return 0;
}   