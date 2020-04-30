#pragma once

#include "figure.h"
#include <iostream>

class Rectangle : public Figure
{
    public:
    Rectangle (double _a, double _b);

    double perim();
    double surface();
    int nsides();
    void save(std::ostream &out);
    void load(std::istream& in);

    Figure *copy();

    private:
    double a,b;
};
