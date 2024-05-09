#pragma once

#include "figure.h"
#include "figures.h"

class Circle : public Figure
{
    public:
    Circle(Point,double);

    Figure* copy() const;

    double area() const;
    double perimeter() const;
    void draw() const;
    void saveToFile(std::ostream&) const;
    void loadFromFile(std::istream&);

    private:
    Point center;
    double r;

};