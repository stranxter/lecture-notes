#include "painter.h"
#include "draw/sdlwrapper.h"

#include "circle.h"
#include "rect.h"
#include "group.h"

Painter::Painter():offset({0,0})
{

}

void Painter::visitCircle(Circle *c)
{
    sdlw::setColor(c->getColor());
    sdlw::drawFillCircle(c->getCenter().x+offset.x,
                         c->getCenter().y+offset.y,
                         c->getRadius());
}
void Painter::visitRect(Rect *r)
{
    sdlw::setColor(r->getColor());
    sdlw::drawFillRect(r->getVertex().x+offset.x,
                       r->getVertex().y+offset.y,
                       r->getW(),
                       r->getH());
}
void Painter::visitGroup(Group *g)
{
 
    offset.x += g->getPosition().x;
    offset.y += g->getPosition().y;

    for (Figure *f : g->getMembers())
    {
        f->accept(this);
    }

    offset.x -= g->getPosition().x;
    offset.y -= g->getPosition().y;
}
