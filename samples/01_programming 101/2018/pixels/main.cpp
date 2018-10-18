#include <iostream>
#include "mygraphics.h"
#include <cmath>

using namespace std;

void square (double x, double y, double diag, double ang)
{
	setColor (255,255,255);
	drawLine (diag*cos(-M_PI/4+ang)+x,diag*sin(-M_PI/4+ang)+y,diag*cos(M_PI/4+ang)+x,diag*sin(M_PI/4+ang)+y);
	drawLine (diag*cos(M_PI/4+ang)+x,diag*sin(M_PI/4+ang)+y,diag*cos(3*M_PI/4+ang)+x,diag*sin(3*M_PI/4+ang)+y);
	drawLine (diag*cos(3*M_PI/4+ang)+x,diag*sin(3*M_PI/4+ang)+y,diag*cos(5*M_PI/4+ang)+x,diag*sin(5*M_PI/4+ang)+y);
	drawLine (diag*cos(5*M_PI/4+ang)+x,diag*sin(5*M_PI/4+ang)+y,diag*cos(-M_PI/4+ang)+x,diag*sin(-M_PI/4+ang)+y);

}

void myDrawLine (double x1,double y1,double x2,double y2)
{
	//sqrt
	double length = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)),
	       dx = (x2-x1)/length,
				 dy = (y2-y1)/length,
				 currentX = x1,
				 currentY = y1;

	for (int i = 0; i < length; i++)
	{
		drawPixel (currentX,currentY);
		currentX += dx;
		currentY += dy;
	}
}

int main ()
{//scklndskl


	setColor (0,255,0);

	myDrawLine (200,200,0,150);

	setColor (255,255,255);

	for (int i = 0; i < 100; i++)
	{
		drawPixel (i,20);
	}

	setColor (255,0,0);

	for (int i = 0; i < 100; i++)
	{
		drawPixel (i,i);
	}

	setColor (255,255,0);

	for (int i = 0; i < 20; i++)
	{

		drawPixel (i*5,i*i);
		myDrawLine (i*5,i*i,(i+1)*5,(i+1)*(i+1));
	}

	setColor (255,0,0);

	for (int i = 0; i < 300; i++)
	{

		drawPixel (i*2,100+50*sin(i/20.0));
    myDrawLine (i*2,100+50*sin(i/20.0),(i+1)*2,100+50*sin((i+1)/20.0));
	}

	for (int i = 0; i < 20; i++)
	{
		square (200,200,75,(M_PI/20)*i);		
	}


	//drawLine (0,0,100,100);

	//-------------------------------------
	updateGraphics();
	cout << "Press any key to continue...";
	cin.get();
	return 0;
}

/*
double superComplexFunction (double x)
{
	return x*x/200+sin(x)*12-cos(x)*cos(x)*18*x/100;
}
*/
