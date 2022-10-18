#include <iostream>
#include <cmath>
#include "./draw/sdlwrapper.h"

void saw(int k,int toothSize)
{

    for (int n = 0; n < k; ++n)
    {
        sdlw::drawLine(toothSize*2*n,0,toothSize*2*n+toothSize,toothSize);
        sdlw::drawLine(toothSize*2*n+toothSize,toothSize,toothSize*2*(n+1),0);
    }

}

void sinGraph()
{
    
}

void circle2()
{
    double step = 0.2;
    for (double angle=0; angle < 2*3.14; angle += step)
    {
        sdlw::drawLine(300+cos(angle)*50,300+sin(angle)*50,
                       300+cos(angle+step)*50,300+sin(angle+step)*50);
    }

}




int main()
{

    sdlw::setColor(255,255,255);

    //saw(10,30);
    //sinGraph();
    circle2();
    

    sdlw::updateGraphics();
    std::cin.get();

}