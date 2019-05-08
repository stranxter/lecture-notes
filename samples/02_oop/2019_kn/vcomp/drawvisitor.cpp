#include "drawvisitor.h"
#include "sdlwrapper.h"

DrawingVisitor::DrawingVisitor():offsetx(0),offsety(0)
{

}

void DrawingVisitor::visitReactangle (Rect *r)
{
    setColor(r->get_r(), r->get_g(), r->get_b());
    drawFillRect(r->get_x()+offsetx, r->get_y()+offsety, r->get_w(), r->get_h());
}
void DrawingVisitor::visitCircle(Circle *c)
{
    drawFile(c->get_x()+offsetx, 
             c->get_y()+offsety, 
             c->get_r() * 2, 
             c->get_r() * 2, 
             "images/circle.png");
}
void DrawingVisitor::visitGroup(Group *g)
{

    offsetx += g->get_x();
    offsety += g->get_y();

    for (size_t i = 0; i < g->get_nChildren(); ++i)
    {
        Shape *shape = g->getChild (i);
        shape->accept (this);
    }

    offsetx -= g->get_x();
    offsety -= g->get_y();
}
