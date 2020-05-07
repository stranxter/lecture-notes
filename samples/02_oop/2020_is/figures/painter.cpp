#include "painter.h"
#include "sdlwrapper.h"
    
Painter::Painter():offset_x(0),offset_y(0){}

void Painter::processCircle(Circle *c)
{
    sdlw::drawFile(c->get_x()-c->get_r()+offset_x,
                   c->get_y()-c->get_r()+offset_y,
                   2*c->get_r(),
                   2*c->get_r(),"images/circle.png");
}
void Painter::processRectangle(Rectangle *r)
{
    sdlw::setColor(255,255,255);
    sdlw::drawFillRect(r->get_x() + offset_x,
                       r->get_y() + offset_y,
                       r->get_a(),
                       r->get_b());
}
void Painter::processGroup(Group *g)
{
    offset_x += g->get_x();
    offset_y += g->get_y();
    for (size_t i = 0; i < g->nElements();++i)
    {
        g->getElement(i)->accept(this);
    }
    offset_x -= g->get_x();
    offset_y -= g->get_y();
}
