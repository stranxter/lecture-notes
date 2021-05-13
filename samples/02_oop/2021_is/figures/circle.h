#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle (double _x, double _y, double _r);
    Circle();

    double surface();
    void saveToFile(std::ostream&);
    void loadFromFile (std::istream&);

    void draw();
    Figure* clone();

    private:
    double r;
    double x,y;

};