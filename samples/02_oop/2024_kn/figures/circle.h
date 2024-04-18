#pragma once

#include "figure.h"
#include "figures.h"

class Circle : public Figure
{
    public:
    Circle(Point,double);

    double area() const;
    double perimeter() const;

    private:
    Point center;
    double r;

};