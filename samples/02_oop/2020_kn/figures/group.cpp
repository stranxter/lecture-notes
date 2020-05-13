#include "group.h"
#include "visitor.h"


Group::Group (const Group &other)
{
    x = other.x;
    y = other.y;
    for (Figure *f:other.contents)
    {
        contents.push_back(f->copy());
    }
}

Figure* Group::copy ()
{
    return new Group(*this);
}

void Group::addFigure(Figure *f)
{
    contents.push_back(f);
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
void Group::save(std::ostream &out)
{
    out << "group " << contents;
}
void Group::load(std::istream &in)
{
    in >> contents;
}

Group::~Group()
{
    for (Figure *f : contents)
    {
        delete f; 
    }
}

Group::Group(double _x, double _y):x(_x),y(_y){}

void Group::accept(Visitor *v)
{
    v->process_group(this);
}

size_t Group::nElements()
{
    return contents.size();
}

Figure* Group::getElement(size_t i)
{
    assert (i < contents.size());
    return contents[i];
}

double Group::get_x()
{
    return x;
}
double Group::get_y()
{
    return y;
}

