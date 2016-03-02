#include <iostream>

using namespace std;

int main ()
{
	long arrLong [3] = {1,2,3};

	long *imeto;
	imeto = &arrLong[1];
	imeto = arrLong + 1;
	imeto = (arrLong+1);

//	long* arrLongPtr[3] = {arrLong,arrLong+1,arrLong+2};
	long* arrLongPtr1[3] = {&arrLong[2],&arrLong[1],&arrLong[0]};
	long* arrLongPtr2[3] = {&arrLong[0],&arrLong[1],&arrLong[2]};

	//arrLongPtr[0] = arrLong + 2; 

//	*arrLongPtr[1] = 0;

	for (int i = 0 ; i < 3; i++)
		cout << arrLong[i] << endl;

	for (int i = 0 ; i < 3; i++)
		cout << *arrLongPtr1[i] << endl;

	for (int i = 0 ; i < 3; i++)
		cout << *arrLongPtr2[i] << endl;

}