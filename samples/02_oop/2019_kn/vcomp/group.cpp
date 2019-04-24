#include "group.h"

Group::Group(int _x, int _y, const char *s):Shape (_x,_y,s){}

void Group::draw()
{
    for (Shape *shape : children)
    {
        shape->set_x (shape->get_x() + x);
        shape->set_y (shape->get_y() + y);
        shape->draw ();
        shape->set_x(shape->get_x() - x);
        shape->set_y(shape->get_y() - y);
    }
}

void Group::addShape(Shape *shape)
{

    children.push_back (shape->clone());
}

Group::~Group()
{
    for (Shape *shape : children)
    {
        delete shape;
    }
}

Shape *Group::clone()
{
    Group *clonning = new Group (x,y,text);

    for (Shape *shape : children)
    {
        clonning->addShape (shape->clone());
    }

    return clonning;
}

Group& Group::operator=(const Group &g)
{
    if (this != &g)
    {
        Shape::operator= (g);
        for (Shape *s : children)
        {
            delete s;
        }
        children.clear();
        for (Shape *s : g.children)
        {
            children.push_back (s->clone());
        }
    }
    return *this;
}

Group::Group(const Group &g):Shape(g)
{
    for (Shape *s : g.children)
    {
        children.push_back(s->clone());
    }
}

void Group::serialize(std::ostream &out)
{
    out << "Group "
        << children.size()
        << "\n";
    
    for (Shape *s : children)
    {
        s->serialize (out);
    }
}
