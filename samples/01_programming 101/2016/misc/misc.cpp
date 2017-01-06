#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstring>

using namespace std;



int myStringLength (char str[100])
{
	int currentSymbolToCheck = 0;

	while (str[currentSymbolToCheck] != 0)
	{
		cout << str[currentSymbolToCheck];
		if (str[currentSymbolToCheck+1] != 0 && 
			str[currentSymbolToCheck] != ' ')
			 cout << ",";
		currentSymbolToCheck++;
	}

	cout << endl;
	return currentSymbolToCheck;
}

bool smallerThan (char str1[100], char str2[100])
{
	int indexOfFirstDifferentLetter = 0;

	while (str1[indexOfFirstDifferentLetter] ==
		   str2[indexOfFirstDifferentLetter] &&
		   str1[indexOfFirstDifferentLetter] != 0 &&
		   str2[indexOfFirstDifferentLetter] != 0)
	{
		indexOfFirstDifferentLetter++;
	}


	if (str1[indexOfFirstDifferentLetter] == 0)
	{
		return str2[indexOfFirstDifferentLetter] != 0;
	}

	if (str2[indexOfFirstDifferentLetter] == 0)
	{
		return false;
	}

	return str1[indexOfFirstDifferentLetter] < 
	       str2[indexOfFirstDifferentLetter];

}

void myStringCopy (char str1[], char str2[])
{
	for (int currentSymbolToCopy = 0; 
		 currentSymbolToCopy <= myStringLength (str2); 
		 currentSymbolToCopy++)
	{
		str1[currentSymbolToCopy] = str2[currentSymbolToCopy];
	}
}

int main ()
{

	cout << strlen ("abc") << endl;


	char str1[100] = "Hello world!",
	     str2[100] = "Yellow";


	cout << myStringLength (str1) 
	     << endl
	     << myStringLength (str2) 
	     << endl 
	     << smallerThan (str1, str2)
	     << endl
	     << smallerThan (str2, str1)
	     << endl;

	myStringCopy (str1,str2); //str1=str2

	cout << str1 << endl;

	return 0;
/*

	str[14] = '#';
	str[13] = '&';
	str[12] = '~';
	str[3] = 0;
	cout << str << endl;

	int q[3];

	cin >> q[0] >> q[1] >> q[2];

	cout << q[1];

	return 0;

	cout << "Моля, въведете нещо:";
	cin >> str;
	cout << "Вие въведохте:" << str << endl;


	return 0;

	int a = 9;
	int m[20]={0,1,2,3};
	int c = 11;

	cout << m[3] << endl;
	m[2] = 99;
	cout << sizeof(m) << endl;
*/

	return 0;
}