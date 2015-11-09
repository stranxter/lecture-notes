#include <iostream>

using namespace std;


int main ()
{

	const int arrSize = 5;

	int a[arrSize] = {0};

	int i,j;


	for (i = 0; i < arrSize; i++)
	{
		cout << "Please enter a number:";
		cin >> a[i];
	}

	for (i = 0; i < arrSize; i ++)
	{
		
		//намираме най-малкия елемент
		//измежду елементите с индекси
		//i...arrSize
		int currentMin = i;
		
		for (j = i; j < arrSize; j++)
		{
			if (a[j] < a[currentMin])
				currentMin = j;
		}

		//намерен!

		int save = a[i];
		a[i] = a[currentMin];
		a[currentMin] = save;
	}


	for (i = 0; i < arrSize; i++)
		cout << "a[" << i << "]=" << a[i] << endl;

}