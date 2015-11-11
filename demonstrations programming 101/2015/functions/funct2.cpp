#include <iostream>

using namespace std;


int enterNumber (int a, int b)
{
	int input;

	cout << "Please enter a number between " 
	     << a 
	     << " and " 
	     << b 
	     << "...";

	do {

		cin >> input;

	} while (input < a || input > b);

	return input;
}

void printNumber (int x)
{
	while (x != 0)
	{
		cout << x % 10;
		x /= 10;
	}
}

void printNumberRec (int x)
{
	if (x < 10)
	{
		cout << x;

	} else {

		cout << x%10;
		printNumberRec (x/10);
		

	}
}

const int N = 10;

bool isSubset (int a[N], int b[N])
{
	for (int i = 0; i < N; i++)
	{
		bool memberFound = false;

		for (int j = 0; j < N; j++)
		{	
			if (a[i] == b[j])
				memberFound = true;

		}

		//(*)
		if (!memberFound)
			return false;
	}

	return true;



}

bool f ()
{
	cout << "I am f\n";
	return false;
}

bool g ()
{
	cout << "I am g\n";
	return true;
}

int mystery (int x)
{
	return x > 0 && mystery (x-1);
	cout << x << " ";
}

int main ()
{
	cout << mystery (5);

/*	if (f() || g ())
		cout << "YEAH!";
*/
	//cout << enterNumber (0,100) / enterNumber (1,100) << endl;

//	printNumberRec (123456789);

//	cout << endl;

}