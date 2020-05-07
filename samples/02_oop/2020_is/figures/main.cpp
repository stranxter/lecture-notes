#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <iomanip>

#include "figure.h"
#include "circle.h"
#include "rect.h"
#include "group.h"

#include "sdlwrapper.h"
#include "painter.h"

int main()
{

    Group *bottomGroup = new Group(100,80);
    bottomGroup->addFigure(new Circle(0,0,50));

    Group *innerGroup = new Group(100,50);
    innerGroup->addFigure(new Circle(30,30,40));
    innerGroup->addFigure(new Rectangle(10,10,30,80));
    innerGroup->addFigure(bottomGroup);
    innerGroup->addFigure(new Circle(140,120,20));


    Group *mainGroup = new Group(10,0);
    mainGroup->addFigure(new Circle(30,80,20));
    mainGroup->addFigure(new Circle(200,100,25));
    mainGroup->addFigure(new Rectangle(100,100,100,70));
    mainGroup->addFigure(innerGroup);
    mainGroup->addFigure(new Rectangle(200,200,20,50));

    std::cout << mainGroup->surface() << std::endl;

    std::ofstream out ("figures.fig");

    mainGroup->save(out);
    out.close();

    std::ifstream in ("figures.fig");    

    Figure *loadedGroup = Figure::loadFigure(in);

    std::cout << mainGroup->surface()
              << std::endl
              << loadedGroup->surface()
              << std::endl;


    Painter p;
    //mainGroup->accept(&p);
    Group *copiedGroup = new Group(*mainGroup);

    copiedGroup->accept(&p);

    delete mainGroup;

    std::cout << copiedGroup->surface()
              << std::endl;

    

    sdlw::updateGraphics();
    std::cin.get();

}