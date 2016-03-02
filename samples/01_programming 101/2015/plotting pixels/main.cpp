#include "mygraphics.h"
#include <math.h>

void makeLine (double x1, double y1, double x2, double y2)
{
	for (double x = x1; x <= x2; x++)
	{
		drawPixel (x,(x-x1)/(x2-x1)*(y2-y1) + y1);
	}
}


int main ()
{

	for (int count = 0; count <= 9; count++)
	{
		makeLine (count*100,100,(count+1)*100,150);
		//makeLine ()
	}



	for (double x = 0; x <= 1000; x++)
	{
		drawPixel (x/2,150+20.0*sin(x/5.0));
	}


	updateGraphics();

	std::cout << "Press any key to continue...";
	std::cin.get();
	std::cout << std::endl;

	return 0;
}