#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle(Point, double,Color=white);
    Circle();

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);
    void serialize(std::ostream&);
    void deserialize(std::istream&);

    virtual Figure* clone();

    private:
    Point c;
    double r;
};