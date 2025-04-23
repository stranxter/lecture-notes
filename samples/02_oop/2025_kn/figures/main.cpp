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

std::ostream& operator<<(std::ostream& out,const std::vector<Figure*> v)
{
    out << v.size() << std::endl;
    for (Figure* fig : v)
    {
        fig->serialize(out);
        out << std::endl;
    }
    return out;
}

Figure* factory(std::string type)
{
    if (type == "circle")
    {
        return new Circle();
    } else if (type == "rect")
    {
        return new Rect();
    } else if (type == "tri")
    {
        return new Triangle();
    }

    throw "Unknow object type!";
    return nullptr;
}

std::istream& operator>>(std::istream &in, std::vector<Figure*>& v)
{   
    v.clear();
    int n;
    in >> n;
    for(int i = 0; i < n; ++i)
    {

        std::string type;
        in >> type;

        Figure *f = factory(type);

        f->deserialize(in);
        v.push_back(f);
    }
    return in;
}

int main()
{

    std::vector<Figure*> figures={new Circle({100,100},30),
                                  new Circle({20,20},50),
                                  new Rect({100,100},50,50),
                                  new Rect({{150,150},50,100}),
                                  new Triangle({180,30},{100,100},{250,200}),
                                  new Rect({0,0},10,20)};

    /* =========== SVG export ============== */

    std::ofstream svg("figures.svg");
    saveSVG(figures,svg);

    /* =========== drawing ================== */

    std::cout << sumSurface(figures) << std::endl;

    sdlw::setColor(255,255,255);

    drawAll(figures);

    sdlw::updateGraphics();
    std::cin.get();

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