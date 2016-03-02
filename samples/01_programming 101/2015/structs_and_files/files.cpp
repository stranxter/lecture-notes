#include <iostream>
#include <fstream>

using namespace std;

void print (ostream& out)
{
	out << "Hello world!\n" 
	    << 5 << " "
	    << 5.15;

}

int main ()
{
	print (cout);

	ofstream hello_file ("hello file on the disk.txt");

	print (hello_file);

	return 0;

}