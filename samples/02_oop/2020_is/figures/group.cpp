#include "group.h"


Group::Group(const Group& other)
{
    for (Figure *f : other.contents)
    {
        contents.push_back(f->copy());
    }
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
double Group::perim()
{
    double sum = 0;
    for (Figure *f : contents)
    {
        sum += f->perim();
    }
    return sum;
}
void Group::save(std::ostream& out)
{
    out << "group: ";
    out << contents; 
}
void Group::load(std::istream& in)
{
    in >> contents;  
}

void Group::addFigure(Figure *f)
{
    contents.push_back(f);
}

Group::~Group()
{
    for (Figure *f : contents)
    {
        delete f; //f->~, delete buffer
    }
}

Figure *Group::copy()
{
    return new Group(*this);
}


Group::Group(){}
