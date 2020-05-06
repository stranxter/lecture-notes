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

    void accept(Visitor*);

    Figure *copy();

    double get_x();
    double get_y();
    double get_a();
    double get_b();

    private:
    double x,y;
    double a,b;
};

