#include <iostream>
#include "mygraphics.h"
#include <cmath>

using namespace std;

/*
Функция polygon (n,x,y,radius): Рисуване на многоъгълник
параметър n: брой върхове на многоъгълника
параметри x,y: координати на центъра на многоъгълника
параметър radius: разстояние от центъра до върховете
*/
void polygon (int n, double x, double y, double radius)
{
  for (int side = 0; side < n; side++)
  {
     drawLine (radius*cos(side*2.0*M_PI/n)+x, radius*sin(side*2.0*M_PI/n)+y,
               radius*cos((side+1)*2.0*M_PI/n)+x,radius*sin((side+1)*2.0*M_PI/n)+y);
  }
}

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

/*
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
*/
	setColor (255,255,255);

	const double //scaleX: коефициент на скалиране по X
	             scaleX = 2.0,
	             //y0: ордината на началната точка
	             y0 = 100,
	             //scaleY: коефициент на скалиране по Y
	             scaleY = 50.0,
	             //stepX: стъпка за нарастване на аргумента
	             stepX = 0.05;
	             //nsegments: брой сегменти от кривата
	const int nsegments = 300;

	for (int i = 0; i < nsegments; i++)
	{
	    drawLine (scaleX*i,y0+scaleY*sin(stepX*i),
	              scaleX*(i+1),y0+scaleY*sin(stepX*(i+1)));
	}
/*
	for (int i = 0; i < 20; i++)
	{
		square (200,200,75,(M_PI/20)*i);
	}

	setColor (255,255,255);

	for (int i = 3; i < 20; i++)
	{
			polygon (i,200,200,50+5*i);
	}
*/

	//drawLine (0,0,100,100);

	//-------------------------------------
	updateGraphics();
	cout << "Press any key to continue...";
	cin.get();
	return 0;
}
