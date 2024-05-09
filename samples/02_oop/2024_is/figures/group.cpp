
#include "group.h"
#include "utils.h"


Group::Group(const Group &other)
{
    copyContents(other);
}

void Group::copyContents(const Group &other)
{
    for(Figure* f : other.figures)
    {
        figures.push_back(f->copy());
    }
}

Figure* Group::copy() const
{
    return new Group(*this);
}

double Group::area() const
{
    double sum = 0;
    for(Figure* f : figures)
    {
        sum += f->area();
    }
    return sum;
}

double Group::perimeter() const
{
    double sum = 0;
    for(Figure* f : figures)
    {
        sum += f->perimeter();
    }
    return sum;
}

void Group::draw(Point origin) const
{
    for(Figure* f : figures)
    {
        f->draw(origin);
    }
}

void Group::save(std::ostream& out) const
{
    out << "Group " << figures.size() << std::endl;
    for(Figure* f : figures)
    {
        f->save(out);
    }
}
void Group::load(std::istream& in)
{
    int n;
    in >> n;
    for(int i = 0; i < n; i++)
    {
        std::string type;
        in >> type;
        Figure* f = Figure::figureFactory(type);
        f->load(in);
        figures.push_back(f);
    }
}

void Group::add(Figure *f)
{
    figures.push_back(f->copy());
}

void Group::clear()
{
    for(Figure* f : figures)
    {
        delete f;
    }
    figures.clear();
}

Group::~Group()
{
    clear();    
}

Group& Group::operator=(const Group &other)
{
    if(this != &other)
    {
        clear();
        copyContents(other);
    }
    return *this;
}