#include <iostream>

unsigned fib_rec(unsigned n)
{
    if(n<=1)
    {
        return 1;
    }

    return fib_rec(n-2) + fib_rec(n-1);
}


unsigned fib_iter(unsigned n)
{
    unsigned a=1,b=1;

    int count = 1;
    while(count < n)
    {
        unsigned ap=b,bp=a+b;
        a=ap;
        b=bp;
        ++count;
    }

    return b;
}

int sum(int a[], unsigned n) //int a[] <=> int*
{   
    if(n==0)
    {
        return 0;
    }
    return a[0] + sum(a+1,n-1);
}

int maxel(int a[], unsigned n)
{
    if(n == 1)
    {
        return a[0];
    }

    return std::max(a[0],maxel(a+1,n-1));
}

bool member(int a[], unsigned n, int x)
{
    if(n==0)
    {
        return false;
    }
    if(a[0]==x)
    {
        return true;
    }
    return member(a+1,n-1,x);

    //return (x==a[0]) || member(a+1,n-1,x);
}

/*
[0,1,2,3,1], 1 -> 2
*/
unsigned count(int a[], unsigned n, int x)
{
    if(n==0)
    {
        return 0;
    }

    //return (a[0]==x ? 1 : 0) + count(a+1,n-1,x);
    return (a[0]==x) + count(a+1,n-1,x);
}

bool equal(int a[], int b[], unsigned n)
{
    /*
    if(n == 0)
    {
        return true;
    }
    if(a[0] != b[0])
    {
        return false;
    }
    return equal(a+1,b+1,n-1);
    */

    return n==0 || a[0] == b[0] && equal(a+1,b+1,n-1);
}

//1,2,3,4,5 -> 5,4,3,2,1


void reverse(int a[], unsigned n)
{
    if(n<2) return;

    
}

bool subset(int a[], unsigned na, int b[], unsigned nb)
{

}

int product(int a[], int b[], unsigned n)
{
    if(n == 0)
    {
        return 0;
    }
    //return a[0]*b[0] + product(a+1,b+1,n-1);
    return a[n-1]*b[n-1] + product(a,b,n-1);
}


int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,0};

    std::cout << "sum=" << sum(a,10);
}