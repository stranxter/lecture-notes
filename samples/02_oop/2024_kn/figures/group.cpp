#include "group.h"

double Group::area() const
{
    double sum = 0;
    for (Figure *f : figures)
    {
        sum += f->area();
    }
    return sum;
}
double Group::perimeter() const
{
    double sum = 0;
    for (Figure *f : figures)
    {
        sum += f->perimeter();
    }
    return sum;

}
void Group::draw() const
{
    for (Figure *f : figures)
    {
        f->draw();
    }
}

void Group::addFigure(Figure *f)
{
    figures.push_back(f);
}

void Group::saveToFile(std::ostream &out) const
{
    out << "Group " << figures.size() << std::endl;
    for (Figure *f : figures)
    {
        f->saveToFile(out);
    }
}

void Group::loadFromFile(std::istream &in)
{
    int nchildren;
    in >> nchildren;
    for (int i = 0; i < nchildren; i++)
    {
        std::string type;
        in >> type;
        Figure *newFigure = Figure::figureFactory(type);
        newFigure->loadFromFile(in);

        figures.push_back(newFigure);

    }
}

Group::~Group()
{
    std::cerr << "~Group()\n";
    for (Figure *f : figures)
    {
        delete f;
    }
}

void Group::clear()
{
    for (Figure *f : figures)
    {
        delete f;
    }
    figures.clear();
}

void Group::copyContents(const Group &other)
{
    for (Figure *f : other.figures)
    {
        figures.push_back(f->copy());
    }
}

Group::Group(const Group &other)
{
    copyContents(other);
}

Figure *Group::copy() const
{
    return new Group(*this);
}

Group& Group::operator=(const Group &other)
{
    if (this != &other)
    {
        clear();
        copyContents(other);
    }

    return *this;
}