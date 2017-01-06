#include <iostream>

using namespace std;


long test (long *t1, long t2)
{
	(*t1)++;
	t1++; // <=> *t1++;
	t2++;
	return 10;
}

void f (long arr[])
{
	cout << sizeof(arr) << endl;
}

int main ()

{

	long a[3] = {1,2,3};
	long b[4] = {1,2,3,4};

	f (a);
	f (b);



    return 0;
	
}