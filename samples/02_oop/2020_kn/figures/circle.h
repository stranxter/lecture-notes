#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle (double _x, double _y, double _r);

    double perim();
    double surface();
    void save(std::ostream &out);
    void load(std::istream &in);
    Figure* copy();

    private:
    double x,y;
    double r;
};
