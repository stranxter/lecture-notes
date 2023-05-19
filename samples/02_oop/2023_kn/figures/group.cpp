#include "group.h"
#include "ffactory.h"


void Group::addElement(Figure *f)
{
    
    figures.push_back(f->clone());

}

void Group::translate(double x, double y)
{
    for (Figure *f : figures)
    {
        f->translate(x,y);
    }
}

void Group::draw()
{
    for (Figure *f : figures)
    {
        f->draw();
    }
}

double Group::perimeter()
{
    double p = 0;
    for (Figure *f : figures)
    {
        p += f->perimeter();
    }   
    return p;
}
double Group::surface()
{
    double s = 0;
    for (Figure *f : figures)
    {
        s += f->surface();
    }   
    return s;
}

void Group::writeToStream(std::ostream &os)
{
    os << "Group\n";
    os << figures;
}
void Group::loadFromStream(std::istream &is)
{
    clear();
    is >> figures;
}

void Group::clear()
{
   for (Figure *f : figures)
   {
        delete f;
   }
   figures.clear();
}

Group::~Group()
{
    clear();
}

Figure* Group::clone()
{
    Group *newGroup = new Group;
    for (Figure *f : figures)
    {
        newGroup->addElement(f->clone());
    }
    return newGroup;
}

const std::vector<Figure*>& Group::getMembers()
{
    return figures;
}

void Group::accept(Visitor *v)
{
    v->visitGroup(this);
}
Group::Group():position({0,0})
{

}

void Group::setPosition(Point2D p)
{
    position = p;
}

Point2D Group::getPosition()
{
    return position;
}
