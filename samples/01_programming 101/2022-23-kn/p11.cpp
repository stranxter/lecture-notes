#include <iostream>

void printArray(int array[], size_t n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void printChar(char c)
{
    std::cout << c;
}

void printString(char *s)
{
    //празен низ!
    if(s[0]==0)
    {
        return;
    }

    int count = 0;
    while(s[count] != '\0')
    {
        printChar(s[count]);
        ++count;
    }


}

void arrayToZero(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i]=0;
    }
}

/*
 Функцията проверява дали числото x
 се среща измежду елементите на масива a
 или не.
*/
bool elem(int a[], int n, int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i]==x)
        {
            return true;
        }
    }

    return false;
}

bool elemB(int a[], int n, int x)
{
    int left=0,
        right=n-1;

    int middle=(left+right)/2;

    while(left <= right)
    {
        if(a[middle]==x)
        {
            return true;
        }
        if (x < a[middle])
        {
            right=middle-1;
        } else 
        {
            left=middle+1;
        }
        middle=(left+right)/2;
    }
    return false;
}

int main()
{

    
    int ax[100]; //ax[0]

    arrayToZero(ax,100);
    printArray(ax,100);


    ax[6] = 100;
    *(ax+6) = 100;// ::int*
    //&(ax[6]) <=> ax+6


    int bx[15];
    printArray(bx+2,5);
    

    char c[100] = "Hello world";
    
    printString(c);
    printString(c+2);

    
    //std::cout << c;
    //std::cout << (c+2);

    long a = 10, b = 20; //a::long &a::long* 
    
    //*(&a)::long

    std::cout << *(&a);

    long *pi; // pi::long* &pi::long**
    //*pi::long

    pi = &a;
    *pi = 8;

    pi = (long*)&pi; //pi::long* &pi::long**

    *pi = 5; //pi = <=> *pi =

    std::cout << std::endl << pi << std::endl;


    int arr[]={1,3,5,7,9,11,13};

    std::cout << elemB(arr,7,1) << std::endl;
    std::cout << elemB(arr,7,5) << std::endl;
    std::cout << elemB(arr,7,11) << std::endl;
    std::cout << elemB(arr,7,13) << std::endl;
    std::cout << elemB(arr,7,-10) << std::endl;
    std::cout << elemB(arr,7,19) << std::endl;
    std::cout << elemB(arr,7,10) << std::endl;
    std::cout << elemB(arr,7,2) << std::endl;


}