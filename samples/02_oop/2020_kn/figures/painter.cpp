#include "painter.h"
#include "sdlwrapper.h"


Painter::Painter():total_offset_x(0),total_offset_y(0)
{}

void Painter::process_circle(Circle *c)
{  
    sdlw::drawFile(c->get_x()-c->get_r()+total_offset_x,
                   c->get_y()-c->get_r()+total_offset_y,
                   2*c->get_r(),
                   2*c->get_r(),
                   "images/circle.png");    
}
void Painter::process_rect(Rect *r)
{
    sdlw::setColor(255,255,255);
    sdlw::drawFillRect(r->get_x()+total_offset_x,
                       r->get_y()+total_offset_y,
                       r->get_a(),
                       r->get_b());    
}
void Painter::process_group(Group *g)
{
    total_offset_x += g->get_x();
    total_offset_y += g->get_y();
    for (int i = 0; i < g->nElements(); ++i)
    {
        g->getElement(i)->accept(this);
    }
    total_offset_x -= g->get_x();
    total_offset_y -= g->get_y();
}
