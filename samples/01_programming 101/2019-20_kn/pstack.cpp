#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

void printSeq (int N)
{
    cout << N << " ";
    if (N > 0)
    {
         printSeq (N-1);
    }
    cout << "(" << N << ")";
}


int mydiv (int x, int y, int *r)
{
  *r = x - (x/y)*y;
  return x/y;
}

void printAll (int a[3], size_t n)
{
    cout << "[";
    for (int i = 0; i < n-1; i++)
        cout << a[i] << ",";
    if (n > 0)
        cout << a[n-1];
    cout << "]" << endl;
}

/*
Да се напише булева фунцкия, която проверява дали
дадено цяло число x е елемент на масива от цели числа
a с дължина n.
*/

bool find (int x, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}

/*
Да се напише булева фунцкия, която проверява дали
дадено цяло число x е елемент на масива от цели числа
a с дължина n. Елементите на масива a са подредение в
нарастващ ред.
*/

bool binsearch (int x, int a[], int n)
{
    assert (n > 0);

    /*
        left: индекс на най-левия елемент в интервала
        right: първи елемент вдясно от интервала
    */
    int left = 0,
        right = n;
    

    while (left < right) /*[?]*/
    /*
        1. a[left] <= x <= a[right]
        2. left <= right
        3. 0 <= left <= n && 0 <= right <= n
    */
    {
        int middle = (left+right)/2;
        if (a[middle] == x)
        {
            return true;
        }
        if (x < a[middle])
        {
            right = middle;
        } else { /* x > a[middle] */
            left = middle+1;
        }
    }

    return false;

}

bool binsearchrec (int x, int a[], int n)
{
    assert (n >= 0);
    if (n == 0)
    {
        return false;
    }
    if (x == a[n/2])
    {
        return true;
    }
    if (x < a[n/2])
    {
        return binsearchrec (x,a,n/2);
    }
    return binsearchrec (x,a+n/2+n%2,n/2-(n+1)%2);
/*
    return (n > 0) &&
           ((x==a[n/2]) ||
            (x < a[n/2] && binsearchrec (x,a,n/2)) ||
            (x > a[n/2] && binsearchrec (x,a+n/2+n%2,n/2-(n+1)%2))
           );
  */         
}



int main ()
{

    //printSeq (4);
    //cout << endl;
/*    int rem = 0, rem2 = 0;
    cout << "[14/4] = "
         << mydiv (14,4,&rem)
         << ",|14/4|="
         << rem
         << endl;

    mydiv (14,4,&rem2);
  */
  /*
  int a[3] = {65537,2,3};

  cout << (long)a << endl;  
  cout << (long)(a+2) << endl;  
  cout << *(a+2) << endl;  
  cout << a[2] << endl;  

  char *cp = (char*)a;

  cout << (int)(cp[0]) << endl;  

  int *ip = a;

  cout << "long = "
       << sizeof (long)
       << endl
       << "int = "
       << sizeof (int)
       << endl
       << "char = "
       << sizeof (char)
       << endl
       << "bool = "
       << sizeof (bool)
       << endl
       << "int a[3] = "
       << sizeof (a)
       << endl
       << "ip = "
       << sizeof (ip)
       << endl;

    printAll (a,3);

    int b[10] = {0,1,2,3,4,5,6,7,8,9};

    printAll (b,10);

    printAll (b+3,5);

    char *s = "Hello World";

    cout << (s+6) << endl;

  */

    int a[5] = {2,4,6,8,10};

    cout << "f=" << binsearch (2,a,5) << endl;
    cout << "f=" << binsearch (4,a,5) << endl;
    cout << "f=" << binsearch (6,a,5) << endl;
    cout << "f=" << binsearch (8,a,5) << endl;
    cout << "f=" << binsearch (10,a,5) << endl;
    cout << "f=" << binsearch (1,a,5) << endl;
    cout << "f=" << binsearch (11,a,5) << endl;
    cout << "f=" << binsearch (3,a,5) << endl;
    cout << "f=" << binsearch (5,a,5) << endl;
    cout << "f=" << binsearch (7,a,5) << endl;
    cout << "f=" << binsearch (9,a,5) << endl;


    cout << "f=" << binsearchrec (2,a,5) << endl;
    cout << "f=" << binsearchrec (4,a,5) << endl;
    cout << "f=" << binsearchrec (6,a,5) << endl;
    cout << "f=" << binsearchrec (8,a,5) << endl;
    cout << "f=" << binsearchrec (10,a,5) << endl;
    cout << "f=" << binsearchrec (1,a,5) << endl;
    cout << "f=" << binsearchrec (11,a,5) << endl;
    cout << "f=" << binsearchrec (3,a,5) << endl;
    cout << "f=" << binsearchrec (5,a,5) << endl;
    cout << "f=" << binsearchrec (7,a,5) << endl;
    cout << "f=" << binsearchrec (9,a,5) << endl;


}