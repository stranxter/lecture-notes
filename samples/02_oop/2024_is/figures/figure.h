#pragma once
#include <iostream>

class Figure;


class Figure
{
    public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    virtual void save(std::ostream& out) const = 0;
    virtual void load(std::istream& in) = 0;

    static double scale;
    static Figure* figureFactory(const std::string &type);
};
