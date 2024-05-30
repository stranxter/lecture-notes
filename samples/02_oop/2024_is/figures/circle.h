#pragma once

#include "figure.h"
#include "utils.h"

class Circle : public Figure
{
    public:

    Circle(const Point& center, double radius);

    double area() const;
    double perimeter() const;
    void load(std::istream& in);
    Figure* copy() const;

    void accept(Visitor* v);

    Point getCenter() const;
    double getRadius() const;

    private:
    Point center;
    double radius;
};