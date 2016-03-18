#include <iostream>
#include <string.h>


using namespace std;

class A{

public:

	int x;

	void print ()
	{
		cout << "A!" << x << "\n";
	}

	A (int i)
	{
		x = i+1;
	}

	A ()
	{
		x = 0;
	}

	A (const A& other)//A *other = &c
	{
		cout << "I AM COPYING AN OBJECT WITH X=" << other.x << endl;
		x = other.x+1; //не правете така!
	}

	A (const char *s)
	{
		x = strlen (s);
	}

};

void f (A param) //A param (c);
{
	param.print();
}

int main ()
{
	A a; //!!! контруктор по подразбиране
	     //конструктор без параметри
	a.x = 5;
	A b = a;
	A c = 9;
	b.print();
	c.print();
	
	f(c); 
	
	f(12);
	f ("hello");

	A d = "good bye!";

	d.print ();



}