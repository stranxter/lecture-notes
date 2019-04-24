#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "shape.h"

class Rect : public Shape
{
    public:
    Rect (int _x,int _y,int _w,int _h,const char *_s);
    void draw(SDL_Renderer *);
    Shape* clone ();
    void serialize(std::ostream &);

    void set_w (int _w);
    void set_h (int _h);
    void set_color (int _r, int _g, int _b);

    int get_w ();
    int get_h ();

    private:
    int w;
    int h;
    int r;
    int g;
    int b;
};

#endif