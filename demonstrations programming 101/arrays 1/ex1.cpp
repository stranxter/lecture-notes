#include <iostream>


using namespace std;


int main ()
{

	int n,x,count = 0;
	cin >> x;

	n = x;

	while (x > 0)
	{
		x /= 10;
		count ++;

	}




	cout << "ndigits = " << count << endl;

	//n! = n*(n-1)*(n-2)...*1

	int fact = 1;

	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}

	cout << "FACT = " << fact << endl;

	x = n;
	int sum = 0;

	while (x > 0)
	{
		sum +=  x % 10;
		x /= 10;

	}

	cout << "sum digits = " << sum << endl;


	x = n;

	do {
		if (x % 10 == 5)
		{
			cout << "yes";
		}
		x /= 10;

	} while (x > 0 && x % 10 != 5);


	cout << endl;

	int i1;
	int i2;
	int i3;
	int i4;
	int i5;

	cin >> i1;
	cin >> i2;
	cin >> i3;
	cin >> i4;
	cin >> i5;

	cout << i5;
	cout << i4;
	cout << i3;
	cout << i2;
	cout << i1;

	int arr[10];

	int i;
	for (i = 0; i < 10; i++)
		cin >> arr[i];

	for (i = 9; i >=0; i--)
		cout << arr[i];

}