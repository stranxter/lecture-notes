#pragma once

#include "figure.h"

class Rect : public Figure
{
    public:
    Rect(double, double, double, double);

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);

    private:
    double x,y,w,h;
};