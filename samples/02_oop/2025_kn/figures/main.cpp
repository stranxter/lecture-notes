#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "draw/sdlwrapper.h"

#include "circle.h"
#include "rectangle.h"
#include "figure.h"
#include "triangle.h"
#include "group.h"

double sumSurface(std::vector<Figure*> v)
{
    double s = 0;
    for (Figure* fig : v)
    {
        s += fig->surface(); //Figure::surface, Circle::surface, Rect::surface
    }
    return s;
}

void drawAll(std::vector<Figure*> v)
{
    for(Figure *fig : v)
    {
        fig->draw();
    }
}

void saveSVG(std::vector<Figure*>v, std::ostream &f)
{
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";

    for(Figure *fig : v)
    {
        fig->toSVG(f);
    }

    f << "</svg>";

}


void drawSign()
{

    Group *boy = new Group  ({new Circle({100,100},30),
                              new Rect({100,200},35,45)});
    
    Group *girl = new Group ({new Circle({200,100},30),
                              new Triangle({200,140},{140,250},{240,250})});

    Group sign ({girl,boy,new Rect({150,100},300,300)},blue);

    Group sign2(sign);
    sign2.setColor(red);
    
    sign.draw();

    std::ofstream out("sign.kn2025");

    sign.serialize(out);

}


void tests()
{
    std::vector<Figure*> figures={new Circle({100,100},30,red),
                                  new Circle({20,20},50, blue),
                                  new Rect({100,100},50,50,yellow),
                                  new Rect({{150,150},50,100}),
                                  new Triangle({180,30},{100,100},{250,200},blue),
                                  new Rect({0,0},10,20)};


    /* =========== SVG export ============== */

    std::ofstream svg("figures.svg");
    saveSVG(figures,svg);

    /* =========== drawing ================== */

    std::cout << sumSurface(figures) << std::endl;

    sdlw::setColor(255,255,255);

    drawAll(figures);

    /* =========== seriazing / deserializing ==========*/

    std::ofstream out("figures.kn2025");

    std::cout << figures;
    out << figures;

    out.close();

    std::ifstream in("figures.kn2025");
    std::vector<Figure*> arr2;

    in >> arr2;

    std::cout << arr2;

}

void testSignLoading()
{
    std::ifstream in("sign.kn2025");

    Group loadedSign;
    std::string type;
    in >> type;

    loadedSign.deserialize(in);

    loadedSign.draw();


}

int main()
{

    //tests();
    //drawSign();
    testSignLoading();

    sdlw::updateGraphics();
    std::cin.get();

}