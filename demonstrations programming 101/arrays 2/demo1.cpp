#include <iostream>

using namespace std;


int main (){

	int a[5][5] = {0,0,0,0,0,
	               1,1,1,1,1,
	               2,2,2,2,2,
	           	   3,3,3,3,3,
	           	   4,4,4,4,4};

	int b[3][3] = {4,0,0,
	               1,4,1,
	               5,2,2};

	//cout << a[2][0] << a[1][1] << a[0][2];

	int i;

	for (i = 0; i < 3; i++)
		cout << "a[" 
			 << i 
			 << "][" 
			 << i 
			 << "]=" << a[i][i] << endl;

	cout << "======\n";

	for (i = 0; i < 3; i++)
		cout << "a[" 
			 << i 
			 << "][" 
			 << i 
			 << "]=" << a[2-i][i] << endl;
	cout << "======\n";

	// cout << a 

	cout << a << endl;

	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cout << a[i][j] << " ";

		cout << endl;

	}

	cout << "======\n";

	//cout << a+b


	//int c[3][3] = {0};


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//c[i][j] = a[i][j]+b[i][j];	
			cout << a[i][j]+b[i][j] << " ";
		}
		cout << endl;

		

	}


	for (i = 0; i < 5; i++)
	//започваме от втори
	{
		for (j = 0; j < i; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}




}