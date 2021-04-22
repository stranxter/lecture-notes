#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle (double _r);
    Circle();

    double surface();
    void saveToFile(std::ostream&);
    void loadFromFile (std::istream&);

    public:
    double r;

};