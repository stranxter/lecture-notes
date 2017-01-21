#include <iostream>
#include <iomanip>
#include <assert.h>


using namespace std;


bool _findNumber (size_t x, int allNumbers[], size_t size)
{
	for (int count = 0; count < size; count++)
	{
		if (allNumbers[count] == x)
		{
			return true;
		}
	}

	return false;
}

void _insertNumber (int x, int *&allNumbers, size_t &size)
{

	//allNumbers = new int [size+1];
	if (_findNumber(x,allNumbers,size))
		return;

	int *newArray = new int [size+1];

	for (int count = 0; count < size; count++)
	{
		newArray[count] = allNumbers[count];
	}

	newArray[size] = x;
	size++;

	if (allNumbers != nullptr)
	{
		delete allNumbers;
	}

	allNumbers = newArray;

}

void _deleteNumber (int x, int *&allNumbers, size_t &size)
{
	
	assert (size > 0);
	assert (allNumbers != nullptr);

	int index=0;
	while (index < size && allNumbers[index] != x)
	{
		index++;
	}
	
	assert (index < size);
	if (index >= size)
		return;

	int *newArray = new int [size-1];

	int count = 0;
	for (count = 0; count < index; count++)
	{
		newArray[count] = allNumbers[count];
	}
	for (count = index+1 ; count < size; count++)
	{
		newArray[count-1] = allNumbers[count];
	}

	delete allNumbers;
	allNumbers = newArray;
	size--;

}

int _getNumber (int index, int allNumbers[], size_t size)
{
	return allNumbers[index];
}

int main ()
{

	int choice = -1;
	int *allNumbers = nullptr;
	size_t size = 0;

	while (choice != 5)
	{

		cout << "Make a choice:\n"
		     << "1.Add number\n"
		     << "2.Delete number\n"
		     << "3.Check number\n"
		     << "4.List all numbers\n"
		     << "5.Exit\n"
		     << "Choose one....";

		cin >> choice;
		int x; 

		switch (choice)
		{
			case 1: 
					cout << "Enter new number:";
					cin >> x;
					_insertNumber (x,allNumbers,size); 
					break;
			case 2: 					
					cout << "Enter number to be deleted:";
					cin >> x;
					if (_findNumber (x,allNumbers,size))
					{
						_deleteNumber (x,allNumbers,size);
					}
					else
					{
						cout << "Sorry, number not found...\n";
					}
					break;

			case 3: 
					cout << "Enter number to be checked:";
					cin >> x;
					if (_findNumber(x,allNumbers,size))
					{
						cout << "Yes, the number was found!\n";
					}
					else 
					{
						cout << "No, the number was not found!\n";
					}

					break;
			case 4: 
					for (int count = 0; count < size; count ++)
						cout << setw(3) 
					         << count 
					         << "." 
					         << _getNumber (count,allNumbers,size)
					         << endl;
					break;
		}



	}


}