#include "painter.h"

#include "draw/sdlwrapper.h"


Painter::Painter(const Point& _origin):origin(_origin)
{
}

void Painter::visitCircle(Circle* c)
{
    sdlw::drawFillCircle(c->getCenter().x*Figure::scale+origin.x*Figure::scale, 
                         c->getCenter().y*Figure::scale+origin.y*Figure::scale, 
                         c->getRadius()*Figure::scale);
}

void Painter::visitTriangle(Triangle* t)
{
    sdlw::drawLine(t->getp1().x*Figure::scale+origin.x*Figure::scale, t->getp1().y*Figure::scale+origin.y*Figure::scale, 
                   t->getp2().x*Figure::scale+origin.x*Figure::scale, t->getp2().y*Figure::scale+origin.y*Figure::scale);
    sdlw::drawLine(t->getp2().x*Figure::scale+origin.x*Figure::scale, t->getp2().y*Figure::scale+origin.y*Figure::scale, 
                   t->getp3().x*Figure::scale+origin.x*Figure::scale, t->getp3().y*Figure::scale+origin.y*Figure::scale);
    sdlw::drawLine(t->getp3().x*Figure::scale+origin.x*Figure::scale, t->getp3().y*Figure::scale+origin.y*Figure::scale, 
                   t->getp1().x*Figure::scale+origin.x*Figure::scale, t->getp1().y*Figure::scale+origin.y*Figure::scale);

}

void Painter::visitSquare(Square* s)
{
    sdlw::drawLine(s->getp1().x*Figure::scale+origin.x*Figure::scale, s->getp1().y*Figure::scale+origin.y*Figure::scale, 
                   s->getp2().x*Figure::scale+origin.x*Figure::scale, s->getp1().y*Figure::scale+origin.y*Figure::scale);
    sdlw::drawLine(s->getp2().x*Figure::scale+origin.x*Figure::scale, s->getp1().y*Figure::scale+origin.y*Figure::scale, 
                   s->getp2().x*Figure::scale+origin.x*Figure::scale, s->getp2().y*Figure::scale+origin.y*Figure::scale);
    sdlw::drawLine(s->getp2().x*Figure::scale+origin.x*Figure::scale, s->getp2().y*Figure::scale+origin.y*Figure::scale, 
                   s->getp1().x*Figure::scale+origin.x*Figure::scale, s->getp2().y*Figure::scale+origin.y*Figure::scale);
    sdlw::drawLine(s->getp1().x*Figure::scale+origin.x*Figure::scale, s->getp2().y*Figure::scale+origin.y*Figure::scale, 
                   s->getp1().x*Figure::scale+origin.x*Figure::scale, s->getp1().y*Figure::scale+origin.y*Figure::scale);
}

void Painter::visitGroup(Group* g)
{
  for(Figure *f : *g)
  {
    f->accept(this);
  }
}