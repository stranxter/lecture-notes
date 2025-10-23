#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

const double A = 50;
const double step = 35;
const double ptor = 40;


void drawSin(int y0)
{
    for(double x = 0; x < 400; x += step)
    {
        //sdlw::drawPixel(x,sin(x)*A+y0);
        sdlw::drawLine(x,sin(x/ptor)*A+y0,x+step,sin((x+step)/ptor)*A+y0);
    }
}

void drawTriangle(int zigsize, int startY, int length)
{
    for(int count = 1; count < length / (zigsize * 2); count = count + 2)
    {
        sdlw::drawLine(zigsize*(count-1),0+startY,zigsize*count,zigsize+startY);
        sdlw::drawLine(zigsize*count,zigsize+startY,zigsize*(count+1),0+startY);
    }
}

int main()
{
    sdlw::setColor(255,255,255);

    /*
    drawTriangle(34,0,1000);
    drawTriangle(45,100,1000);
    drawTriangle(20,200,1000);
    */

    drawSin(100);

    sdlw::updateGraphics();
    sdlw::waitKeypress();

    return 0;
}

int SDL_main(int argc, char* argv[]) {
    /* Това е необходимо за SDL под Windows: библиотекат сменя входната точка на програмата*/
    return main(); 
}