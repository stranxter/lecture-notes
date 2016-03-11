#include <iostream>
#include <string.h>

using namespace std;

void _strcat_1 (char *s1, char *s2)
{
	int l1 = strlen (s1),
	    l2 = strlen (s2);

	for (int i = 0; i < l2; i++)
		s1[l1+i] = s2[i];

	s1[l1+l2] = 0;
}

char* _strcat_dynamic (char *s1, char *s2)
//s3 = _strcat_dynamic (s1,s2);
{

	int l1 = strlen (s1),
	    l2 = strlen (s2);

	char *result = new char[l1+l2+1];

	int i;

	for (i = 0; i < l1; i++)
		result[i] = s1[i];

	for (i = 0; i < l2; i++)
		result[l1+i] = s2[i];

		
	result[l1+l2] = 0;

	return result;


}

int main ()
{
	char s1[100] = "Hello World", s2[] = "!!!!!!";

	char *s3 = new char[2000];
	delete s3;

	s3 = _strcat_dynamic (s1,s2);

	cout << s1 << endl << s2 << endl;

	cout << "s3=" << s3 << endl;
}