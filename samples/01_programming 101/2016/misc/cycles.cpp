#include <iostream>
#include <assert.h>


using namespace std;
/*
Precondition: 
*/
double perimeter (double a, double b, double c)
{

	assert (a > 0 && b > 0 && c > 0);
	assert (a+b > c);
	assert (a+c > b);
	assert (c+b > a);
	
	return a + b + c;
}

int main ()
{

	int x = 100;

	{
		int x = 90;
		cout << x << endl;

	}

	cout << x << endl;

	return 0;

}