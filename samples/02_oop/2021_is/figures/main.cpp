#include <iostream>
#include <vector>
#include <fstream>

#include "figure.h"
#include "rectangle.h"
#include "circle.h"


double sumSurface(Figure* figures[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += figures[i]->surface();
    }
    return sum;
}

void saveToStream(std::ostream& out, std::vector<Figure*> figures)
{
    out << figures.size() << " ";
    
    for (Figure *f : figures)
    {
        f->saveToFile(out);
    }
}


Figure* figureFactory(std::string figureType)
{
    if (figureType == "circle")
    {
        return new Circle();

    } else if (figureType == "rect")
    {
        return new Rectangle();

    } else 
    {
        assert(false);
        return nullptr;
    }
}

std::vector<Figure*> loadFromStream(std::istream& in)
{
    
    int nFigures;
    in >> nFigures;
    
    std::vector<Figure*> result;
    std::string figureType;

    for (int i = 0; i < nFigures; ++i)
    {
        in >> figureType;
        Figure* newFigure = figureFactory(figureType);
        newFigure->loadFromFile(in);      
        result.push_back(newFigure);

    }
    
    return result;
}

int main()
{
    //Figure f("Abstract Figure");
    //f.surface();
    //std::cout << f.surface() << std::endl;

    Rectangle r(2,3);
    std::cout << r.surface() << std::endl;

    Circle c(2);

    std::vector<Figure*> figures = {&r,&c};

    std::ofstream out ("figures.fmi");

    saveToStream(out, figures);
    out.close();

    std::ifstream in ("figures.fmi");
    
    std::vector<Figure*> figures2 = loadFromStream(in);

    saveToStream(std::cout,figures2);


}