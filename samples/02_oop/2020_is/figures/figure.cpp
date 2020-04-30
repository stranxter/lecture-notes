#include "figure.h"
#include "ffactory.h"


Figure *Figure::loadFigure(std::istream&in)
{
    std::string type;
    in >> type;
    Figure *newFigure = FigureFactory::make(type);
    newFigure->load(in);
    return newFigure;
}


std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures)
{
    size_t nFigures;
    in >> nFigures;

    figures.clear();

    for (size_t i = 0; i < nFigures; ++i)
    {
        figures.push_back(Figure::loadFigure(in));
    }
    return in;
}

std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures)
{
    out << figures.size () << " ";
    for (Figure *f : figures)
    {
        f->save(out);
    }
    return out;
}

double Figure::sumSurfaces(std::vector<Figure*> figures)
{
    double sum = 0;
    for (Figure* f : figures)
    {
        sum += f->surface();
    }
    return sum;
}

Figure::~Figure()
{
    
}
