#pragma once
#include <iostream>
#include "utils.h"

class Figure;
class Visitor;

class Figure
{
    public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void load(std::istream& in) = 0;

    virtual Figure* copy() const = 0;

    virtual void accept(Visitor* v) = 0;

    virtual ~Figure() = default;

    static double scale;
    static Figure* figureFactory(const std::string &type);
};
