#include "serializer.h"

#include "circle.h"
#include "rect.h"
#include "group.h"


Serializer::Serializer(std::ostream &_out):out(_out)
{

}

void Serializer::visitCircle(Circle *c)
{
    out << "Circle " 
        << c->getRadius() 
        << " " 
        << c->getCenter().x 
        << " " 
        << c->getCenter().y;
}
void Serializer::visitRect(Rect *r)
{
    out << "Rect " 
        << r->getVertex().x 
        << " " 
        << r->getVertex().y 
        << " "
        << r->getW() 
        << " " 
        << r->getH();

}
void Serializer::visitGroup(Group *g)
{
    for (Figure *f : g->getMembers())
    {
        f->accept(this);
    }
}

