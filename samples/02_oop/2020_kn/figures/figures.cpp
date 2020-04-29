#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

#include "figure.h"
#include "circle.h"
#include "square.h"
#include "group.h"
#include "ffactory.h"


int main()
{

    Group * g = new Group;
    g->addFigure (new Circle(1,1,1));
    g->addFigure (new Square(5));

    Group * g2 = new Group;
    g2->addFigure (new Circle(2,2,2));

    g->addFigure(g2);

    Group *mainGroup = new Group;
    mainGroup->addFigure(new Circle(0,0,1));
    mainGroup->addFigure(new Square(1));
    mainGroup->addFigure(new Circle(3,0,2));
    mainGroup->addFigure(g);
    mainGroup->addFigure(new Square(2));

    std::ofstream out ("figures.fig");
    mainGroup->save(out);
    out.close();

    std::cout << mainGroup->surface() << std::endl;

    std::ifstream in ("figures.fig");
    Figure *loadedGroup = new Group;

    loadedGroup = Figure::readFigure(in);
    std::cout << loadedGroup->surface() << std::endl;

    Group *copiedGroup = new Group (*mainGroup);

    delete mainGroup;

    return 0;

}
