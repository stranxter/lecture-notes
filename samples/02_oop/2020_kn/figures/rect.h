#pragma once

#include "figure.h"

class Rect : public Figure
{
    public:
    Rect (double _x, double _y, double _a,double _b);

    double perim();
    double surface();
    int nsides();
    void save(std::ostream &out);
    void load(std::istream &in);

    private:
    double x,y;
    double a,b;
};

