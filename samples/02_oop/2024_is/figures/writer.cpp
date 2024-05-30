#include "writer.h"

Writer::Writer(std::ostream& _out): out(_out) {}

void Writer::visitCircle(Circle* c)
{
     out << "Circle " << c->getCenter().x << " " << c->getCenter().y << " " << c->getRadius() << std::endl;
}

void Writer::visitSquare(Square* s)
{
    out << "Square " << s->getp1().x << " " << s->getp1().y << " " << s->getp2().x << " " << s->getp2().y << std::endl;
}

void Writer::visitTriangle(Triangle* t)
{
    out << "Triangle " << t->getp1().x << " " << t->getp1().y << " " << t->getp2().x << " " << t->getp2().y << " " << t->getp3().x << " " << t->getp3().y << std::endl;  
}   

void Writer::visitGroup(Group* g)
{
    out << "Group " << g->size() << std::endl;
    for(Figure* f : *g)
    {
        f->accept(this);
    }
}