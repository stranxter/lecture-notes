#pragma once

#include "figure.h"

class Circle : public Figure
{
    public:
    Circle(Point, double);
    Circle();

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);
    void serialize(std::ostream&);
    void deserialize(std::istream&);

    private:
    Point c;
    double r;
};