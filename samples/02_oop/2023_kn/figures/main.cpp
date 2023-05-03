#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "draw/sdlwrapper.h"


#include "figure.h"
#include "circle.h"
#include "rect.h"
#include "group.h"

#include "ffactory.h"


double sumPerim(std::vector<Figure*> figures)
{
    double sum = 0;
    for (Figure* figure : figures)
    {
        sum += figure->perimeter();
    }

    return sum;
}


int main()
{

    Circle *c1 = new Circle({0,0},100);
    Rect *r1 = new Rect({200,200},100,300);
    Circle *c2 = new Circle({300,300},50);
    Rect *r2 = new Rect({400,400},100,50);

    Group g1;

    Group *g2 = new Group;

    g1.addElement(c1);
    c1->translate(100,100);
    g1.addElement(r1);

    g1.translate(0,250);

    g2->addElement(c2);
    g2->addElement(r2);
    g2->addElement(&g1);

    sdlw::setColor(255,0,0);
    sdlw::drawLine(0,0,800,500);

    g2->draw();

    sdlw::updateGraphics();
    std::cin.get();

    delete g2;
    delete c1;
    delete c2;
    delete r1;
    delete r2;

}