#pragma once
#include <iostream>

struct Point
{
    double x;
    double y;
};

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perimeter() = 0;

    virtual void draw() = 0;
    virtual void toSVG(std::ostream&) = 0;

    private:
    char label[15];

};