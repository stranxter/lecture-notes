#include <iostream>
#include <cmath>
#include <cstring>
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

/*
    Намиране на най-малък елемент в масив.
    Масивът е непразен.
*/

int minrec (int a[], int size)
{
    if (size == 1)
    {
        return a[0];
    }

    return min (minrec (a,size-1), a[size-1]);
    //return min (a[0], minrec (a+1,size-1));

}

/*
    Проверка дали даден масив е подреден в нарастващ ред
*/

bool issorted (int a[], int size)
{
    if (size <= 1)
    {
        return true;
    }

    return a[0] < a[1] && issorted (a+1,size-1);
}

/*
    Дължината на най-дългия общ префикс на двата масива.
    size е дължината на по-късия от двата масив
*/

int commonPrefix (int a[], int b[], int size)
{
    if (size == 0 || a[0] != b[0])
    {
        return 0;
    }

    //size > 0
    //a[0] == b[0]

    return 1 + commonPrefix (a+1,b+1,size-1);
}

/*
    commonPrefix ([1,2,3,9,9,9], [1,2,3,8,9,9],6) =     |3
       1 + commonPrefix ([2,3,9,9,9],[2,3,6,9,9],5) =   |3
           1 + commonPrefix ([3,9,9,9], [3,6,9,9], 4) = |2
               1 + commonPrefix ([9,9,9],[6,9,9], 3)    |1
                   0                                    |0

*/

int commonPrefix (char *s1, char *s2)
{
    if (strlen (s1) == 0 || 
        strlen (s2) == 0 || 
        s1[0] != s2[0])
    {
        return 0;
    }

    return 1 + commonPrefix (s1+1,s2+1);
}

/*
    Низът s1 подниз ли е на низа s2. Например "abc" "zzabczzz",
    но не и "abc" на "zzazbzccc".
*/

bool substring (char *s1, char *s2)
{

    /*
    if (strlen (s2) < strlen (s1))
    {
        return false;
    }
    */

    if (strlen (s1) == 0)
    {
        return true;
    }

    if (strlen (s2) == 0)
    {
        return false;
    }

    if (commonPrefix (s1,s2)==strlen(s1))
    {
        return true;
    }

    return substring (s1, s2+1);
}

/*
    Дадени са два масива с числа. Да се провери дали
    единия може да се получи от другия с добавяне на
    едно и също число k към елементите му.
    Приемаме, че и двата масива са с размер size
*/

bool similar (int a[], int b[], int size)
{
    if (size <= 1)
    {
        return true; 
    }

    return a[0]-b[0] == a[1] - b[1] && similar (a+1,b+1,size-1);
}

/*
    Дадени са два масива с числа. Да се провери дали
    единия може да се получи от другия с добавяне на
    едно и също число k към елементите му.
    Да се намери и върне числото k. 
    Приемаме, че и двата масива са с размер size
*/

bool findsim (int a[], int b[], int size, int &k)
{
    if (size == 0)
    {
        k = 0; //!!! може да е всяка стойност
        return true;
    }

    if (size == 1)
    {
        k = b[0] - a[0];
        return true;
    }

    //може да ползваме similar

    int k; 
    if (findsim (a+1, b+1, size-1,k))
    {
        return k == b[0]-a[0];
    }    
}



int main ()
{
    //cout << seq (4) << endl;

    //printdivs (351509);

    int a[10] = {475,2,35,6,8,9,67,5,43,6};
    sssortrec (a,10);

    printAll (a,10);
}