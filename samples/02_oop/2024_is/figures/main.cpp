#include "square.h"
#include "circle.h"
#include "triangle.h"

#include <iostream>
#include <vector>
#include <fstream>

#include "draw/sdlwrapper.h"


double area(std::vector<Figure*> figure)
{
    double sum = 0;

    for(Figure* f : figure)
    {
        sum += f->area();
    }

    return sum;
}

void drawAll(std::vector<Figure*> figure)
{
    for(Figure* f : figure)
    {
        f->draw();
    }
}

void saveAll(std::vector<Figure*> figure, std::ostream& out)
{
    for(Figure* f : figure)
    {
        f->save(out);
    }
}

std::vector<Figure*> loadFromFile(std::istream &in)
{

    std::vector<Figure*> result;

    std::string type;
    while (in >> type)
    {
        Figure *newFigure = Figure::figureFactory(type);
        newFigure->load(in);
        result.push_back(newFigure);

    }    

    return result;
}

int main()
{
  
    /*
    std::vector<Figure*> figures = {new Circle({100,100},30),
                                    new Triangle({60,60},{90,90},{70,200}),
                                    new Square({30,30},{10,10})};
    */

   std::ifstream in("figures.txt");
   std::vector<Figure*> figures = loadFromFile(in);

    std::cout << area(figures) << std::endl;

    sdlw::setColor(255,255,255);
    Figure::scale = 2;
    drawAll(figures);

    sdlw::updateGraphics();
    std::cin.get();

    std::ofstream out("`.txt");
    saveAll(figures,out);

}