#pragma once

#include "figure.h"

class Rectangle : public Figure
{
    public:

    Rectangle();
    Rectangle(double _x, double _y, double _a, double _b);

    double surface();
    void saveToFile(std::ostream&);
    void loadFromFile (std::istream&);

    void draw();
    Figure* clone();

    private:
    double x,y,a,b;

};