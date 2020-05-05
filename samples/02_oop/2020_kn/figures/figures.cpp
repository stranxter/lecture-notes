#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "figure.h"
#include "circle.h"
#include "rect.h"
#include "group.h"
#include "ffactory.h"

#include "sdlwrapper.h"


int main()
{

    Group * g = new Group;
    g->addFigure (new Circle(1,1,1));
    g->addFigure (new Rect(10,11,12,13));

    Group * g2 = new Group;
    g2->addFigure (new Circle(2,2,2));

    g->addFigure(g2);

    Group *mainGroup = new Group;
    mainGroup->addFigure(new Circle(0,0,1));
    mainGroup->addFigure(new Rect(1,2,3,4));
    mainGroup->addFigure(new Circle(3,0,2));
    mainGroup->addFigure(g);
    mainGroup->addFigure(new Rect(5,6,7,8));

    std::ofstream out ("figures.fig");
    mainGroup->save(out);
    out.close();

    std::cout << mainGroup->surface() << std::endl;

    std::ifstream in ("figures.fig");
    Figure *loadedGroup = new Group;

    loadedGroup = Figure::readFigure(in);
    std::cout << loadedGroup->surface() << std::endl;

    Group *copiedGroup = new Group (*mainGroup);
    std::cout << copiedGroup->surface() << std::endl;

    delete mainGroup;

    sdlw::drawFile(100,100,20,20,"images/circle.png");
    sdlw::setColor(255,255,255);
    sdlw::drawFillRect(200,200, 100,50);    
    sdlw::updateGraphics();
    std::cin.get();




    return 0;

}
