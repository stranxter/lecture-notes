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


int main()
{

    Group *innerGroup = new Group;
    innerGroup->addFigure(new Circle(2,2,2));
    innerGroup->addFigure(new Rectangle(3,3));
    innerGroup->addFigure(new Circle(4,4,4));

    Group *mainGroup = new Group;
    mainGroup->addFigure(new Circle(0,0,1));
    mainGroup->addFigure(new Circle(3,0,2));
    mainGroup->addFigure(new Rectangle(1,2));
    mainGroup->addFigure(innerGroup);
    mainGroup->addFigure(new Rectangle(2,4));

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


    Group *copiedGroup = new Group(*mainGroup);

    delete mainGroup;

    std::cout << copiedGroup->surface()
              << std::endl;

}