#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "group.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>

#include "draw/sdlwrapper.h"


void testManual()
{
    
    Group *picture = new Group();
    picture->addFigure(new Circle({0,0},1));    
    
    Group *g = new Group();
    g->addFigure(new Square({2,2},{3,3}));
    g->addFigure(new Triangle({0,0},{1,0},{1,1}));

    Group *g2 = new Group();
    g2->addFigure(new Circle({1,1},0.2));
    g2->addFigure(g);

    picture->addFigure(g2);

    Figure::scale = 100;
    sdlw::setColor(255,255,255);

    picture->draw();

    sdlw::updateGraphics();
    std::cin.get();

    Group *picture2 = new Group(*picture);

    std::ofstream out("grouptest.txt");
    picture->saveToFile(out);

    delete picture;
    delete picture2;

}


void testWithFile()
{
    std::ifstream in("grouptest.txt");

    std::string type; 
    in >> type; 
    Figure *picture = Figure::figureFactory(type);

    picture->loadFromFile(in);

    Figure::scale = 100;
    sdlw::setColor(255,255,255);

    picture->draw();

    sdlw::updateGraphics();
    std::cin.get();

    delete picture;

}

int main()
{

    testManual();
    //testWithFile();

}