#include "serializevisitor.h"
#include <iomanip>

SerializeVisitor::SerializeVisitor(std::ostream &_out):out(_out),depth(0){};

void SerializeVisitor::visitReactangle (Rect *r)
{

    out << std::setw(depth*2+1) << " ";

    out << "Rect "
        << r->get_x()
        << " "
        << r->get_y()
        << " "
        << r->get_w()
        << " "
        << r->get_h()
        << " "
        << strlen(r->get_text())
        << " "
        << r->get_text()
        << "\n";
}

void SerializeVisitor::visitCircle (Circle *c)
{

    out << std::setw(depth * 2+1) << " ";

    out << "Circle "
        << c->get_x()
        << " "
        << c->get_y()
        << " "
        << c->get_r()
        << " "
        << strlen(c->get_text())
        << " "
        << c->get_text()
        << "\n";
}
void SerializeVisitor::visitGroup (Group *g)
{
    out << std::setw(depth * 2+1) << " ";

    out << "Group "
        << g->get_nChildren()
        << "\n";

    depth++;
 
    for (size_t i = 0; i < g->get_nChildren(); ++i)
    {
        g->getChild (i)->accept (this);

    }

    depth--;
}
