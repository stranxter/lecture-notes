#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "group.h"

#include <iostream>
#include <vector>
#include <fstream>

#include "draw/sdlwrapper.h"

#include "painter.h"
#include "writer.h"


void testManual()
{

    sdlw::setColor(255,255,255);


    Group *boy = new Group();
    boy->add(new Circle({100,100},30)); //memory leak!
    boy->add(new Square({100,150},{150,100}));

    Group *picto = new Group;
    picto->add(boy);
    picto->add(new Circle({50,100},30));
    picto->add(new Triangle({50,140},{20,200},{80,200}));

    Group *picto2 = new Group(*picto);

    Painter p1({140,40}), p2({240,40});

    picto->accept(&p1);
    picto2->accept(&p2);


    sdlw::updateGraphics();
    std::cin.get();

    std::ofstream out("figures.txt");
    Writer w(out);
    picto->accept(&w);

    delete picto;
    delete picto2;


}

void testWithFile()
{
    std::ifstream in("figures.txt");
    std::string type;
    in >> type;

    Figure *picture = Figure::figureFactory(type);
    picture->load(in);

    Painter p({0,0});


    sdlw::setColor(255,255,255);
    Figure::scale = 2;
    picture->accept(&p);

    sdlw::updateGraphics();
    std::cin.get();

    delete picture;

}

int main()
{

    //testManual();
    testWithFile();
  
}