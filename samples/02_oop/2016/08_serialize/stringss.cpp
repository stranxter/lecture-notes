#include <iostream>
#include <fstream>

using namespace std;

int main ()
{

	char s[200];

	ifstream in ("test.txt");

	in.getline (s,10);

	cout << s << endl << (bool)in;

	return 0;


	//char *sarr[3] = {"Hello world!", "and", "have a nice day"};
	char *sarr[3] = {"Hello", " world! and", "have a nice day"};

	cout << sarr[1] << endl;

	ofstream f ("data.txt");

	f << 3 << endl;

	for (int i = 0; i < 3; i ++)
		f << strlen (sarr[i]) << endl << sarr[i] << endl;


	return 0;
}