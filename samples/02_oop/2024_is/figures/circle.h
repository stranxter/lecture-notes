#pragma once

#include "figure.h"
#include "utils.h"

class Circle : public Figure
{
    public:

    Circle(const Point& center, double radius);

    double area() const;
    double perimeter() const;
    void draw(Point origin) const;
    void save(std::ostream& out) const;
    void load(std::istream& in);
    Figure* copy() const;

    private:
    Point center;
    double radius;
};