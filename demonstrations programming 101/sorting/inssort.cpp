#include <iostream>

using namespace std;


int main ()
{
 
	const int arrSize = 5;

	int a[arrSize] = {0};

	int x,i,k;


	for (i = 0; i < arrSize; i++)
	{
		cout << "Please enter a number:";
		cin >> x;

		int j;
		for (j = 0;a[j]<x && j<i;j++){};
		//j е точно индекса в масива, на
		//който трябва да запишем x

			//a[j] > x сменя реда

	    //ще избутаме всички елементи отдясно
		//на индекса j с един надясно

	     for (k=i;k>j;k--)
			a[k]=a[k-1];
	
		a[j] = x;

	}

	for (i = 0; i < arrSize; i++)
		cout << "a[" << i << "]=" << a[i] << endl;

}