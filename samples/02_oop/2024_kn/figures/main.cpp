#include "circle.h"
#include "square.h"
#include "triangle.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "draw/sdlwrapper.h"


double sumArea(std::vector<Figure*> figures)
{
    double sum = 0;

    for(Figure *f : figures)
    {
        sum += f->area();
    }
    return sum;
}

void drawAll(std::vector<Figure*> figures)
{
    for(Figure *f : figures)
    {
        f->draw();
    }
}


void saveTofile(std::vector<Figure*> figures, std::ostream& out)
{
    for(Figure *f : figures)
    {
        out << f;   
    }
}


std::vector<Figure*> loadFromFile(std::istream& in)
{

    std::vector<Figure*> result;

    std::string type;
    
    while (in >> type)
    {

        Figure *newFigure = Figure::figureFactory(type);

        newFigure->loadFromFile(in);
        result.push_back(newFigure);
    }

    return result;
    
}

int main()
{

    std::vector<Figure*> figures = {new Circle({0,0},1),
                                    new Square({2,2},{3,3}),
                                    new Triangle({0,0},{1,0},{1,1})};

    //std::vector<Figure*> figures;
    //std::ifstream in("figures.txt");
    //figures = loadFromFile(in);

    std::cout << sumArea(figures) << std::endl;

    sdlw::setColor(255,255,255);

    Figure::scale = 100;
    drawAll(figures);

    sdlw::updateGraphics();
    std::cin.get();

    std::ofstream out("figures.txt");
    saveTofile(figures,out);

}