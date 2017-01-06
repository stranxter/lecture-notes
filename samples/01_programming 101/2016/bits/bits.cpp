#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;


double findRoot (double a, double b, double c, bool smallerRoot)
{
	
	double D = b*b - 4*a*c;

	assert (D < 0);

	if (smallerRoot)
		return (-b - sqrt(D))/(2*a);
	else	
		return (-b + sqrt(D))/(2*a);
}


int main ()
{

	bool b = 100;

	cout << (int)b << endl;

	cout << (4 && 1) << endl;

	cout << (4 & 1) << endl;

	cout << (4 || 1) << endl;

	cout << (4 | 1) << endl;

	cout << (5 >> 1) << endl;



	int bits = 0b00100101;
	//20
	//077 <-> 111|111
	//0xFF <-> 1111|1111

	cout << bits << endl;

	bool isRockNRoll1 = (bits >> 5) & 1;
	bool isRockNRoll2 = (bits & (1 << 5)) != 0;

	cout << isRockNRoll1 << " " << isRockNRoll2 << endl;

	int RockAndRollAndClassicMask = (1 << 5) | (1 << 2);

	bool isRockNRollAndClassics 
	   = (bits & RockAndRollAndClassicMask) == RockAndRollAndClassicMask;

	int RockClassicsAndReggaeMask = isRockNRollAndClassics | (1 << 7);

	RockClassicsAndReggaeMask |= (1 << 6);

	int kill6_v1 = 255 - (1 << 6);
	unsigned char kill6_v2 = ~(1 << 6);

	cout << kill6_v1 << " " << (int)kill6_v2 << endl;



	return 0;
}