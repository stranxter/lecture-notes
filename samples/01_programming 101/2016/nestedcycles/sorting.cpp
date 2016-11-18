#include <iostream>
#include <iomanip>

using namespace std;


int main ()
{

	int arr[5] = {0};
	
	int x;
	int i;
	for (i = 0; i < 5; i++)
	{

		cin >> x;
		int positionForX = 0;
		
		while (positionForX < i && 
			   arr[positionForX] <= x)
		{
			positionForX++;
		}
		//намерили сме в PostionForX
		//подходящото "място" на елемента

		//i = броя на записани в масива 
		//    до момента елементи
		//positionForX = позиция за "вмъкване" на x

		for (int elementToMove = i-positionForX;
			 elementToMove > 0 ;
			 elementToMove--)
		{
			arr[positionForX+elementToMove] = 
			    arr[positionForX+elementToMove-1];

		}

		//преместили сме всички елементи "вдясно" от
		//positionForX с един надясно

		arr[positionForX] = x;

	}

	for (i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;


}