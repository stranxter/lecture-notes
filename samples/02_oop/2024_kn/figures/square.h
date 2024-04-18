#pragma once

#include "figure.h"
#include "figures.h"

class Square : public Figure
{

    public:
    Square(Point, Point, Point);

    double area() const;
    double perimeter() const;

    private:
    Point p1, p2, p3;

};