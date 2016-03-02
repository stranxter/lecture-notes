#include <iostream>

using namespace std;


int main ()
{

	const int arrSize = 5;

	int a[arrSize] = {0};

	int i;


	for (i = 0; i < arrSize; i++)
	{
		cout << "Please enter a number:";
		cin >> a[i];
	}


	int currentMax = a[0];
	
	for (i = 1; i < arrSize; i++)
	{
		if (a[i] > currentMax)
			currentMax = a[i];
	}

	cout << "Max el = " << currentMax << endl;
}