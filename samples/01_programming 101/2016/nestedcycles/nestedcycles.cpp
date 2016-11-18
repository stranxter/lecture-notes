#include <iostream>

using namespace std;

int main ()
{
	double doubleM[5][5]={-1,-1,-1,-1,-1,
					      -1,-1,-1,-1,-1,
					      -1,-1,-1,-1,-1,
					      -1,-1,-1,-1,-1,
					      -1,-1,-1,-1,-1};


	cin >> doubleM[0][0];
	cin >> doubleM[1][1];
	cin >> doubleM[2][2];
	cin >> doubleM[3][3];
	cin >> doubleM[4][4];

	for (int counter = 0; counter < 5; counter++)
		cin >> doubleM[counter][counter];

	for (int counter = 0; counter < 5; counter++)
		cin >> doubleM[counter][4-counter];


	for (int counter = 0; counter < 5; counter++)
		cin >> doubleM[counter][2];

	char stringMatrix [5][5][11];

	cin >> stringMatrix[4][4];
	//cout << stri



	cout << doubleM[4][4];
}