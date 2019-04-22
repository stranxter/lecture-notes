#include <iostream>
#include "mygraphics.h"
#include <cmath>


using namespace std;


int main ()
{//scklndskl

	setColor (255,0,0);

	drawRect (5,5,20,70);
	
	setColor(0, 0, 255);

	drawRect (50,50,70,20);

	drawFile (100,100,50,50,"images/triangle.png");
	drawFile (100,120,50,50,"images/cicrcle.png");

	//-------------------------------------
	updateGraphics();
	cout << "Press any key to continue...";
	cin.get();
	return 0;
}
