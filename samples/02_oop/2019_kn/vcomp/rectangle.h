#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "shape.h"

class Rect : public Shape
{
    public:
    Rect (int _x,int _y,int _w,int _h,const char *_s);
    Shape* clone ();
    
    void accept (Visitor*);

    void set_w (int _w);
    void set_h (int _h);
    void set_color (int _r, int _g, int _b);

    int get_w () const;
    int get_h () const;
    int get_r () const;
    int get_g () const;
    int get_b () const;

    private:
    int w;
    int h;
    int r;
    int g;
    int b;
};

#endif