#include <iostream>
#include "sdlwrapper.h"
using namespace std;

#include "rectangle.h"
#include "circle.h"
#include "group.h"
#include <iostream>
#include <fstream>


int main ()
{//scklndskl

	/*Rect r1 (10,10,30,100,"Test Rectangle");
	Rect r2(50, 50, 30, 50, "Test Rectangle 2");
	Circle c1(20, 20, 30, "Test Circle");

	r1.set_color (255,0,0);
	r2.set_color(0, 255, 0);

	Group g1 (120,130,"A Group");
	Group g2 (120, 130, "A Group");

	g1.addShape (&r1);
	g1.addShape (&c1);

	g2.addShape (&g1);
	g2.addShape (&r2);

	g2.draw();


	std::ofstream file ("drawing.drw");

	g2.serialize (file);
*/
	drawText();


	//-------------------------------------
	updateGraphics();
	cout << "Press any key to continue...";
	cin.get();
	return 0;
}
