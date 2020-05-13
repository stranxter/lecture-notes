#include "figure.h"
#include <vector>
#include "ffactory.h"

double Figure::sumSurface(std::vector<Figure*> figures)
{
    double sum = 0;
    for (size_t i = 0; i < figures.size(); i++)
    {
        sum += figures[i]->surface();
    }

    return sum;
}

std::ostream& operator << (std::ostream &out, std::vector<Figure*> figures)
{
    out << figures.size() << " ";

    for (Figure *f : figures)
    {
        f->save(out);
    }
    return out;
}


Figure* Figure::readFigure(std::istream &in)
{
    std::string type;
    in >> type; 
    Figure *newFigure;

    try
    {
         newFigure = FigureFactory::make(type);
    }
    catch(UnknownFigureExcpection ex)
    {
        std::cerr << "Error reading figures:" << ex.what() << std::endl;
        return nullptr;
    }
    
    newFigure->load(in);
    return newFigure;

}
std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures)
{
    size_t nFigures;
    in >> nFigures;
    figures.clear();
    for (size_t i = 0; i < nFigures; ++i)
    {
        Figure *newfig = Figure::readFigure(in);
        if (newfig != nullptr)
        {
            figures.push_back(newfig);
        } else {
            return in;
        }   
    }
    return in;
}

Figure::~Figure()
{

}