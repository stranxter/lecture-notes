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

#include "painter.h"


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

    c1->setColor({255,255,255});
    r1->setColor({0,0,255});
    c2->setColor({0,255,255});
    r2->setColor({255,255,0});

    Group g1;

    Group *g2 = new Group;

    g1.addElement(c1);
    c1->translate(100,100);
    g1.addElement(r1);

    g1.translate(0,250);
    g1.setColor({50,50,50});

    g2->addElement(c2);
    g2->addElement(r2);
    g2->addElement(&g1);

    sdlw::setColor({255,0,0});
    sdlw::drawLine(0,0,800,500);

    //g2->draw();
    Painter *p = new Painter();
    g2->accept(p);

    //sdlw::updateGraphics();
    //std::cin.get();

    g2->setPosition({100,25});
    g2->accept(p);

    sdlw::updateGraphics();
    std::cin.get();

    g2->writeToStream(std::cout);
    std::ofstream out ("figs.txt");
    g2->writeToStream(out);
    out.close();
    std::ifstream in("figs.txt");
    std::string label;
    in >> label; //прочитаме водещото "Group"
    g2->loadFromStream(in);
    g2->writeToStream(std::cout);

    delete g2;
    delete c1;
    delete c2;
    delete r1;
    delete r2;

}