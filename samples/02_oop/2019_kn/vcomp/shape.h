#ifndef __SHAPE_H
#define __SHAPE_H

class Visitor;

class Shape
{
public:
    
    Shape ();
    Shape (int,int,const char*);
    Shape (const Shape&);

    virtual void accept (Visitor*) = 0;

    virtual Shape* clone () = 0;

    void set_x (int);
    void set_y (int);
    void set_text (const char*);

    void operator = (const Shape& s);
  
    int get_x();
    int get_y();
    char* get_text();

    virtual ~Shape();

  protected:

    int x;
    int y;
    char *text;

};

#endif