#pragma once

#include <iostream>

class Figure
{
    public:

    virtual double perimeter() = 0;
    virtual double surface() = 0;

    virtual void writeToStream(std::ostream&) = 0;
    virtual void loadFromStream(std::istream&) = 0;

    virtual void draw() = 0;

    virtual void translate(double x, double y) = 0;

    virtual Figure* clone() = 0;

    virtual ~Figure() = default;

};

struct Point2D
{
    double x,y;
};

std::ostream& operator << (std::ostream &out, const std::vector<Figure*>& figures);

