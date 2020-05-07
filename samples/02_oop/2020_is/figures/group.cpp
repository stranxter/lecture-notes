#include "group.h"
#include "visitor.h"

Group::Group(const Group& other)
{
    //****************************************
    //ТОВА БЕШЕ ПРОБЛЕМА ПО ВРЕМЕ НА ЛЕКЦИИ
    //копираната група оставаше с неинициализирани x и y
    //****************************************
    x = other.x;
    y = other.y;
    //****************************************
    for (Figure *f : other.contents)
    {
        contents.push_back(f->copy());
    }
}

Figure *Group::copy()
{
    return new Group(*this);
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
    out << "group: " << x << " " << y << " ";
    out << contents; 
}
void Group::load(std::istream& in)
{
    in >> x >> y >> contents;  
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

Group::Group(double _x, double _y):x(_x),y(_y)
{

}

size_t Group::nElements()
{
    return contents.size();
}

Figure* Group::getElement(size_t i)
{
    assert(i < contents.size());
    return contents[i];
}
void Group::accept(Visitor *v)
{
    v->processGroup(this);
}

double Group::get_x()
{
    return x;
}
double Group::get_y()
{
    return y;
}
