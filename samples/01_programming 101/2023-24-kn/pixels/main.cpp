#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

void drawSaw(int startY, int toothSize, int nTeeth)
{
    for(int i = 0; i < nTeeth; ++i)
    {
        sdlw::drawLine(2*i*toothSize,0+startY,(2*i+1)*toothSize,toothSize+startY);    
        sdlw::drawLine((2*i+1)*toothSize,toothSize+startY,2*(i+1)*toothSize,0+startY);        
    }

    sdlw::drawLine(0,0+startY,2*nTeeth*toothSize,0+startY);

}

void drawSinus(int x0, int y0, double freq, double ampl)
{
    double prec = 0.2;
    for(int i = 0; i < 100; ++i)
    {
        sdlw::drawLine(x0+i*3,y0+100+sin(i*prec*freq)*ampl,
                       x0+(i+1)*3,y0+100+sin((i+1)*prec*freq)*ampl);
    }
}

int main()
{
    sdlw::setColor(255,255,255);

    //drawSaw(0,40,5);
    //drawSaw(100,20,10);
    //drawSaw(170,40,5);

    drawSinus(0,100,1,30);
    drawSinus(0,50,3,30);

    sdlw::updateGraphics();
    std::cin.get();

}