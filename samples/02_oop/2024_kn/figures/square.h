#pragma once

#include "figure.h"
#include "figures.h"

class Square : public Figure
{

    public:
    Square(Point, Point);

    double area() const;
    double perimeter() const;
    void draw() const;

    double side() const;
    void saveToFile(std::ostream&) const;
    void loadFromFile(std::istream&);

    Figure* copy() const;

    private:
    Point p1, p2;


};