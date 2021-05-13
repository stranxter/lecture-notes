#include "group.h"  
#include <cassert>  
#include "ffactory.h"
    

Group::Group():Figure("Group")
{

}


double Group::surface()
{
    double sum = 0;
    for (Figure *f : contents)
    {
        sum += f->surface();
    }

    return sum;
}

void Group::saveToFile(std::ostream &out)
{
    out << "group " << contents.size() << " [ ";
    
    for (Figure *f : contents)
    {
        f->saveToFile(out);
    }

    out << " ] ";

}
void Group::loadFromFile (std::istream &in)
{
    
    char parenth;
    
    int nFigures;
    in >> nFigures;
    
    in >> parenth;
    assert(parenth == '[');

    clearContents();
    std::string figureType;

    for (int i = 0; i < nFigures; ++i)
    {
        in >> figureType;
        Figure* newFigure = figureFactory(figureType);
        newFigure->loadFromFile(in);      
        contents.push_back(newFigure);

    }

    in >> parenth;
    assert(parenth == ']');
    
}

void Group::addFigure(Figure *f)
{
    contents.push_back(f->clone());
}

void Group::draw()
{
    for (Figure *f : contents)
    {
        f->draw();
    }
}

Figure* Group::clone()
{
    Group* newGroup = new Group();
    for (Figure *f : contents)
    {
        newGroup->addFigure(f);
    }

    return newGroup;
}


void Group::clearContents()
{
    for (Figure *f : contents)
    {
        delete f;
    }
    contents.clear();
}

Group::~Group()
{
    clearContents();
}
