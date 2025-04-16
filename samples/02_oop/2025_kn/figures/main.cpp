#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "draw/sdlwrapper.h"

#include "circle.h"
#include "rectangle.h"
#include "figure.h"
#include "triangle.h"

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

int main()
{

    Circle c1(100,100,30), c2(20,20,50);
    Rect r1(100,100,50,50), r2(150,150,50,100);
    Triangle t({180,30},{100,100},{250,200});

    /*
    std::vector<Circle> circles = {c1,c2};
    std::vector<Rect> rects = {r1,r2};
    */

    Rect r(0,0,10,20);

    //std::cout << "1:" << r.Figure::surface() << std::endl;
    std::cout << "2:" << r.Rect::surface() << std::endl;
    std::cout << "3:" << r.surface() << std::endl;

    Rect *pr = &r;
    std::cout << "4:" << pr->surface() << std::endl;

    Figure *pf = &r;
    std::cout << "5:" << pf->surface() << std::endl;


    std::vector<Figure*> figures={&c1,&c2,&r1,&r2,&t};

    std::cout << sumSurface(figures) << std::endl;

    sdlw::setColor(255,255,255);

    drawAll(figures);

    sdlw::updateGraphics();
    std::cin.get();

    std::ofstream out("figures.svg");

    saveSVG(figures,out);



}