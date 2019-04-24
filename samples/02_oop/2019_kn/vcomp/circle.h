#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
    public:
    Circle (int _x,int _y,int _r,const char *_s);
    void draw();
    Shape* clone ();
    void serialize(std::ostream &);

    void set_r (int _r);

    int get_r ();

    private:
    int r;
};

#endif