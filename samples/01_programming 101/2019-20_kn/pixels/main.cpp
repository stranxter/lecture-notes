#include <iostream>
#include "mygraphics.h"
#include <cmath>

#define PI 3.14159265
/*
	drawPixel (x,y)
	drawLine (x1,y,x2,y2)
	setColor (r,g,b)
*/

void trion(int size, int n)
{

	for (int counter = 0; counter < 2 * n; counter = counter + 2)
	{
		drawLine(counter * size, 0, (counter + 1) * size, size);
		drawLine((counter + 1) * size, size, (counter + 2) * size, 0);
	}

}

void drawCircle(double x, double y, double r, double startDeg, double endDeg, int thickness)
{
	for (double i = startDeg; i < endDeg; i += 0.3)
	{
		for (double j = 0; j < thickness; j++) 
		{
			drawPixel(x + cos(i * PI / 180)*(r + j), y - sin(i * PI / 180)*(r + j));
		}
	}
}

void thickLine(double sx, double sy, double ex , double ey, double thickness) {

	for (int i = 0; i < thickness; i++)
	{
		drawLine(sx, sy + i, ex, ey + i);
	}
}

//Linear interpolation
double lerp(double a, double b, float t)
{
	double diff = b - a;

	return a + (diff * t);
}

void bezierCurve(double x1, double y1, double x2, double y2, double x3, double y3, int thickness) 
{
	double xa, ya, xb, yb, x, y;
	for (float i = 0; i < 1; i += 0.01)
	{
		//Get point from first line
		xa = lerp(x1, x2, i);
		ya = lerp(y1, y2, i);
		//Get point from second line
		xb = lerp(x2, x3, i);
		yb = lerp(y2, y3, i);

		//Make a new line out of the last 2 and get a point on it
		x = lerp(xa, xb, i);
		y = lerp(ya, yb, i);


		drawPixel(x, y);

		//To make the line thicker I draw a square around the pixel
		for (int j = 1; j <= thickness; j++) {
			drawLine(x - j, y - j, x + j, y);
			drawLine(x - j, y - j, x, y + j);
			drawLine(x + j, y - j, x + j, y + j);
			drawLine(x - j, y + j, x + j, y + j);
		}
	}
}

void drawCatto(double s)
{
	//Back body
	bezierCurve(335, 143 + s, 500, 130+s, 450 + s/4, 280, 2);
	//drawCircle(400, 203, 90, -60, 134, 5);

	drawCircle(420, 153 + s, 1, -200, -20, 15);
	drawCircle(380, 143 + s, 1, -170, 0, 15);

	//Back Legs
	drawCircle(440 + s/4, 280, 6, -180, 0, 5);
	thickLine(435 + s/4, 280, 400 + s/4, 280, 5);
	drawCircle(390 + s/4, 280, 6, -180, 0, 5);

	//Front legs
	thickLine(385 + s / 4, 280, 340 - s / 4, 280, 5);
	drawCircle(330 - s/4, 280, 6, -180, 0, 5);
	thickLine(325 - s / 4, 280, 290 - s / 4, 280, 5);
	drawCircle(280 - s/4, 280, 6, -180, 0, 5);

	//Front body
	bezierCurve(270 - s / 4, 280, 230, 260 + s, 280, 140 + s, 2);

	//Ears
	bezierCurve(280, 140 + s, 290, 110 + s, 300, 140 + s, 2);
	thickLine(298, 140 + s, 315, 140 + s, 5);
	bezierCurve(315, 140 + s, 325, 110 + s, 335, 140 + s, 2);

	//Face
	drawCircle(290, 160 + s, 3, 0, 180, 3);
	drawCircle(325, 160 + s, 3, 0, 180, 3);

	bezierCurve(307, 160 + s, 304, 170 + s, 300, 165 + s, 1);
	bezierCurve(307, 160 + s, 310, 170 + s, 314, 165 + s, 1);

	//Moustache
	bezierCurve(270, 150 + s, 260, 145 + s, 250, 150 + s / 6 + s, 1);
	bezierCurve(270, 160 + s, 260, 155 + s, 250, 165 + s / 6 + s, 1);

	bezierCurve(340, 150 + s, 350, 145 + s, 360, 150 + s / 6 + s, 1);
	bezierCurve(340, 160 + s, 350, 155 + s, 360, 165 + s / 6 + s, 1);

	//Tail
	bezierCurve(460, 200, 480, 190 + s, 500, 191, 3);
}

int main()
{

	std::cout << "Press any key to continue...";
	bool keep_window_open = true;
	double timer = 0;
	while (keep_window_open)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				keep_window_open = false;
				break;
			}
		}

		setColor(0, 0, 0);
		SDL_RenderClear(SDLRen);


		setColor(sin(timer / 10) * 255, sin(timer / 10 + 1) * 255, sin(timer / 10 + 2) * 255);
		drawCatto(sin(timer) * 20);
		updateGraphics();
		SDL_UpdateWindowSurface(SDLWin);

		timer+=0.6;

		SDL_Delay(16);
	}
	return 0;
}