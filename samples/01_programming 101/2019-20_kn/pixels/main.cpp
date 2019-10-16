#include <iostream>
#include "mygraphics.h"
#include <cmath>

/*
    drawPixel (x,y)
    drawLine (x1,y,x2,y2)
    setColor (r,g,b)
*/

using namespace std;

void trion (int size, int n)
{
    
    for (int counter = 0; counter < 2*n; counter=counter+2)
    {
        drawLine(counter * size, 0, (counter + 1) * size, size);
        drawLine((counter + 1) * size, size, (counter + 2) * size, 0);
    }
        
}

void drawSinus ()
{
    for (double x = 0; x < 200; x++)
    {
        drawLine(2*x, 100 + 30 * sin(x/20.0),
                 2*(x+1), 100 + 30 * sin (x/20.0));
    }
}


int main ()
{
    setColor (255,255,255);

    //trion (50,12);
    drawSinus();

    updateGraphics();
    cout << "Press any key to continue...";
    cin.get();
    return 0;
}