#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle(double, double, double);

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);

    private:
    double x,y,r;
};