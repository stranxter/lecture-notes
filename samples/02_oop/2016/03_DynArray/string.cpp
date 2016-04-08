#include <iostream>
#include <string>

using namespace std;

class String
{
private:
	char *str;
public:
	String ()
	{
		str = new char[1];
		str[0] = 0;
	}

	String (char *s)
	{
		//delete str; НЕЕЕ!!!
		str = new char [strlen (s)+1];
		strcpy (str,s);

	}

	String& operator = (const String& other)
	{	
		//s = s;
		if (this != &other)
		{
			delete str;
			str = new char [strlen (other.str)+1];
			strcpy (str,other.str);			
		}

		return *this;
	}

	String (const String& other)
	{
		//delete str; НЕЕЕ!!!
		str = new char [strlen (other.str)+1];
		strcpy (str,other.str);		
	}

	~String ()
	{
		delete str;
	}

	friend istream& operator >> (istream &in, String& s);
};

istream& operator >> (istream &in, String& s)
{

	delete s.str;

	char s[100];

	return in;
}

int main ()
{
	String a; //дефинираме празния низ ""
	String b = "Hello";
	String c = b;

	cin >> a;
	cout << a;

	cout << a + b;

	if (a > b) //<, >=, <=, ==
	{
		cout << "1\n";
	}

	cout << a[4];
	a[4] = 'a';


}