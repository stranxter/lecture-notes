#pragma once

#include "figure.h"
#include "figures.h"


class Triangle : public Figure
{
    public:
    Triangle(Point, Point, Point);

    double area() const;
    double perimeter() const;
    void draw() const;
    void saveToFile(std::ostream&) const;
    void loadFromFile(std::istream&);

    Figure* copy() const;

    private:
    Point p1, p2, p3;
    double side_a() const;
    double side_b() const;
    double side_c() const;
};