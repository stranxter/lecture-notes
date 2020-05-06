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
#include "painter.h"


int main()
{

    Group * g = new Group(250,50);
    g->addFigure (new Circle(20,20,50));
    g->addFigure (new Rect(10,10,100,120));

    Group * g2 = new Group(30,300);
    g2->addFigure (new Circle(70,80,70));

    g->addFigure(g2);

    Group *mainGroup = new Group(0,0);
    mainGroup->addFigure(new Circle(300,300,100));
    mainGroup->addFigure(new Rect(200,250,30,40));
    mainGroup->addFigure(new Circle(30,0,40));
    mainGroup->addFigure(g);
    mainGroup->addFigure(new Rect(400,400,70,100));


    Painter p; //... //... //.... //...
    mainGroup->accept(&p);


    /*
    std::ofstream out ("figures.fig");
    mainGroup->save(out);
    out.close();

    std::cout << mainGroup->surface() << std::endl;

    std::ifstream in ("figures.fig");
    Figure *loadedGroup = new Group(0,0);

    loadedGroup = Figure::readFigure(in);
    std::cout << loadedGroup->surface() << std::endl;

    Group *copiedGroup = new Group (*mainGroup);
    delete mainGroup;

    std::cout << copiedGroup->surface() << std::endl;

    copiedGroup->draw();
    */


    sdlw::updateGraphics();
    std::cin.get();


    return 0;

}
