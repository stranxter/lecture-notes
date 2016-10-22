#include "mygraphics.h"
#include <math.h>

using namespace std;


double superComplexFunction (double x)
{
	return x*x/200+sin(x)*12-cos(x)*cos(x)*18*x/100;
}


int main ()
{

/*
	for (int x = 0; x < 200; x++)
		drawPixel (20+x,20);
	
	for (int xy = 0; xy < 200; xy++)
		drawPixel (20+xy,20+xy);

	for (int y = 0; y < 200; y++)
		drawPixel (220,20+y);

	for (int x = -200; x < 200; x++)
	{
		int y = x*x;
		drawPixel (x+200,y/100);
	}
*/

	for (int x = 0; x < 200; x++)
	{
		drawPixel (x,superComplexFunction(x));
	}



	//-------------------------------------
	updateGraphics();
	cout << "Press any key to continue...";
	cin.get();
	return 0;
}