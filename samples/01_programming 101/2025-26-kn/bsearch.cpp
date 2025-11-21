#include <iostream>
#include <cmath>

bool searchrecunordered(int a[], int size, int x)
{
    return (size > 0) && (a[0]==x || searchrecunordered(a+1,size-1,x));
    /*
    if(size == 0)
    {
        return false;
    }

    if(a[0] == x)
    {
        return true;
    }

    return searchrecunordered(a+1,size-1,x);
    */
}

bool searchrec(int a[], int size, int x)
{
    return (size > 0) && 
           (a[size/2]==x ||
            (x > a[size/2]) && searchrec(a+(int)std::ceil(size/2.0),size/2-(size%2==0),x)||
            (x < a[size/2]) && searchrec(a,size/2,x));
/*    
    if(size == 0)
    {
        return false;
    }

    if(a[size/2] == x)
    {
        return true;
    }

    if(a[size/2] < x)
    {
        return searchrec(a+(int)std::ceil(size/2.0),size/2-(size%2==0),x);
    }
    
    return ;
*/
}


bool search(int a[], int size, int x)
{

    int left = 0, right = size - 1;

    while(left <= right && a[(left+right)/2] == x)
    {
        if(a[(left+right)/2] < x)
        {
            left = (left+right)/2+1;
        } else 
        {
            right = (left+right)/2-1;
        }
    }

    return left<=right;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::cout << searchrec(arr,10,50) << std::endl;

    return 0;
}