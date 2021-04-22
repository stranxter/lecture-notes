#pragma once

#include "figure.h"

class Rectangle : public Figure
{
    public:

    Rectangle();
    Rectangle(double _a, double _b);

    double a,b;
    double surface();
    void saveToFile(std::ostream&);
    void loadFromFile (std::istream&);
};