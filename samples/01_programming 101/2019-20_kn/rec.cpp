#include <iostream>
using namespace std;

int seq (int i)
{
    if (i == 0)
    {
        return 0;
    }

    return seq (i-1) + 2*i;
}

int fib_iter (int n)
{
    int a =0, b = 1;

    if (n == 0)
        return a;

    while (n > 1)
    {
        int c = a+b;
        a = b;
        b = c;
        n--;
    }

    return b;
}


void printdivs (int n)
{
    if (n <= 1)
    {
        return;
    }
    int smallestDiv = 2;
    while (smallestDiv <= n && n % smallestDiv != 0)
    {
        smallestDiv++;
    }

    cout << smallestDiv << endl;

    printdivs (n/smallestDiv);
}

int findmiel (int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }

    return min (a[0],findmiel (a+1,n-1));
}


int findminelindex (int a[], int n)
{
    int current = 1, minel = 0;
    while  (current < n)
    {
        if (a[current] < a[minel])
        {
            minel = current;
        }
        current++;
    }
    return minel;
}

void swap (int* a, int* b)
{
    int save = *a;
    *a = *b;
    *b = save;
}

void sssortrec (int a[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int minel = findminelindex (a,n);
    swap (a,a+minel);

    sssortrec (a+1,n-1);

}

void printAll (int a[], size_t n)
{
    cout << "[";
    for (int i = 0; i < n-1; i++)
        cout << a[i] << ",";
    if (n > 0)
        cout << a[n-1];
    cout << "]" << endl;
}


int main ()
{
    //cout << seq (4) << endl;

    //printdivs (351509);

    int a[10] = {475,2,35,6,8,9,67,5,43,6};
    sssortrec (a,10);

    printAll (a,10);
}