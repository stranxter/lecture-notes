#include <iostream>
#include <iomanip>


using namespace std;


int mystrlen (char s[100])
{
	int count = 0;
	while (s[count] != 0) // '\0' == 0
	{
		count++;
	}

	return count;
}

int main () 

{
	char str[100] = "Hello world!"; 
	cout << str << endl;
	str[0] = 'Y';
	cout << str << endl;
	cout << "input:"; 
	cin.getline (str,99);
	for (int counter = 0; counter < 200; counter++) 
	{
		if (str[counter] == 'a') 
		{
		str[counter] = 'b'; 
		}
	}
	cout << str << endl;

	cout << "len = " << mystrlen (str) << endl;

cout << '0' << "/";
cout << (int)'0' << "/";
cout << 0 << endl; //0/48/0

cout << (int)'0' + 3 << "/";
cout << (char)('k' + 3) << "/";

	return 0; 
}