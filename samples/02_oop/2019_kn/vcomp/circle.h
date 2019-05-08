#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
    public:
    Circle (int _x,int _y,int _r,const char *_s);
    Shape* clone ();

    void accept(Visitor *);

    void set_r (int _r);

    int get_r () const;

    private:
    int r;
};

#endif