#include "shape.h"
#include <cstring>

#include <iostream>

void Shape::set_x(int _x)
{
    x=_x;
}
void Shape::set_y(int _y)
{
    y=_y;
}
void Shape::set_text(const char *s)
{
    
    if (text != nullptr)
    {
        delete text;
    }

    text = new char [strlen(s)+1];
    strcpy (text,s);
}

int Shape::get_x()
{
    return x;
}
int Shape::get_y()
{
    return y;
}
char* Shape::get_text()
{
    return text;
}

Shape::Shape():x(0),y(0),text(nullptr)
{

}
Shape::Shape(int _x, int _y,  const char *s)
{
    set_x (_x);
    set_y (_y);
    text = nullptr;
    set_text (s);
}

Shape::~Shape ()
{
    delete text;
}

Shape::Shape (const Shape &s):x(s.x),y(s.y),text(nullptr)
{
    set_text (s.text);
}

void Shape::operator=(const Shape &s)
{
    if (this != &s)
    {
        set_text (s.text);
        std::cerr << " ASSIGNING A SHAPE?\n";
    }
}
