#pragma once

#include "figure.h"
#include "utils.h"

class Circle : public Figure
{
    public:

    Circle(const Point& center, double radius);

    double area() const;
    double perimeter() const;

    private:
    Point center;
    double radius;
};