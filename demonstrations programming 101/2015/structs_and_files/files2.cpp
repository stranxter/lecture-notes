#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	
	int i;

	char txt[1000] = "ERROR!";

	ifstream hello_file ("hello file on the disk.txt");

	hello_file >> i;

	hello_file.getline (txt,1000);

	cout << "We are able to read: " << txt << endl;

	return 0;

}