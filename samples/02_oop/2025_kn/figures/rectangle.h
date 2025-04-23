#pragma once

#include "figure.h"

class Rect : public Figure
{
    public:
    Rect(Point, double, double);
    Rect();

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);
    void serialize(std::ostream&);
    void deserialize(std::istream&);
    
    private:
    Point c;
    double w,h;
};