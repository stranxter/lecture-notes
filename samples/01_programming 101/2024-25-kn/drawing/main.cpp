#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"


void drawSin(int y0, double A, double f, double step)
{
    for (double x = 0; x < 100; x = x + step)
    {
        //sdlw::drawPixel(x,y0+A*sin(x));
        sdlw::drawLine(f*x,y0+A*sin(x),f*(x+step),y0+A*sin(x+step));
    }
}

void drawSaw(int y0, int n, int h)
{
    for(int i = 0; i < n; ++i)
    {
        sdlw::drawLine(h*2*i,y0,h*2*i+h,y0+h);
        sdlw::drawLine(h*2*i+h,y0+h,h*2*(i+1),y0);
    }
}

int main()
{
    sdlw::setColor(255,255,255);


    drawSaw(0,50,20);
    drawSaw(50,50,10);
    drawSaw(150,10,100);

    drawSin(250,50,10,0.2);

    sdlw::updateGraphics();
    std::cin.get();

}