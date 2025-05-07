#include "group.h"

Group::Group():Figure(white){}

Group::Group(const Group& other)
{
    for(Figure *f : other.parts)
    {
        parts.push_back(f->clone());
    }  
}

Group::Group(const std::vector<Figure*>& _parts,Color c):Figure(c),parts(_parts)
{
    for(Figure *f : parts)
    {
        f->setColor(c);
    }
}


Figure* Group::clone()
{
    return new Group(*this);
}


void Group::setColor(Color c)
{
    for(Figure *f : parts)
    {
        f->setColor(c);
    }
}

double Group::surface()
{
    return 0;
}
double Group::perimeter()
{
    return 0;
}

void Group::draw()
{
    predraw();
    for(Figure *f : parts)
    {
        f->draw();
    }
}
void Group::toSVG(std::ostream&)
{

}

void Group::serialize(std::ostream& out)
{
    out << "group ";

    out << parts;

}
void Group::deserialize(std::istream& in)
{
    in >> parts;
}

Group::~Group()
{
    for(Figure *f : parts)
    {
        delete f;
    }
}