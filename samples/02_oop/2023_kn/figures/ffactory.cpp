#include "ffactory.h"
#include <vector>

#include "circle.h"
#include "rect.h"
#include "group.h"

Figure* factory(const std::string &type)
{
    
    if (type == "Circle")
    {
        return new Circle({0,0},0);
    } else if (type == "Rect")
    {
        return new Rect({0,0},0,0);
    } else if (type == "Group")
    {
        return new Group;
    }

    return nullptr;
}

std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures)
{
    size_t nFugures;
    in >> nFugures;
    for (size_t i = 0; i < nFugures; ++i)
    {
        std::string figureType;
        in >> figureType;

        Figure *f = factory(figureType);

        f->loadFromStream(in);
        figures.push_back(f);

    }
    return in;
}