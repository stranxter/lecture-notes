#include <iostream>
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





}