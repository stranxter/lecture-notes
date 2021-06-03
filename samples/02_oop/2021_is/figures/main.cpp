#include <iostream>
#include <vector>
#include <fstream>

#include "figure.h"
#include "rectangle.h"
#include "circle.h"
#include "group.h"

#include "draw/sdlwrapper.h"


Figure* createSomeFigure()
{

    Rectangle r(10,10,100,50);
    std::cout << r.surface() << std::endl;

    Circle c(50,50,60),
           c2(250,250,40);

    Group g1;
    g1.addFigure(&r);
    g1.addFigure(&c);
    g1.addFigure(&c2);

    Rectangle r2(230,50,10,70), r3(330,50,10,70);
    Group *g2 = new Group();
    g2->addFigure(&g1);
    g2->addFigure(&r2);
    g2->addFigure(&r3);

    return g2;

}


int main()
{
   

    Figure *f = createSomeFigure();

    std::ofstream out ("figures.fmi");

    f->saveToFile(out);
    out.close();


    sdlw::setColor(255,0,0);
    f->draw();
    sdlw::updateGraphics();
    std::cin.get();

    delete f;


/*
    std::ifstream in ("figures.fmi");
    
    std::vector<Figure*> figures2 = loadFromStream(in);

    saveToStream(std::cout,figures2);
x
    sdlw::setColor(255,0,0);
    sdlw::drawLine(0,0,100,100);
    sdlw::drawFile(20,20,30,30,"draw/images/circle.png");
    sdlw::drawText(40,40,40,"Hello world?!?");
    sdlw::updateGraphics();
    std::cin.get();

*/

}