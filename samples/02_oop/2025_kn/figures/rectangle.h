#pragma once

#include "figure.h"

class Rect : public Figure
{
    public:
    Rect(Point, double, double, Color=white);
    Rect();

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);
    void serialize(std::ostream&);
    void deserialize(std::istream&);

    virtual Figure* clone();
    
    private:
    Point c;
    double w,h;
};