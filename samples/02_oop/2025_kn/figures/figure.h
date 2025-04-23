#pragma once
#include <iostream>

struct Point
{
    double x;
    double y;
};

std::ostream& operator << (std::ostream&,const Point&);
std::istream& operator >> (std::istream&,Point&);

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perimeter() = 0;

    virtual void draw() = 0;
    virtual void toSVG(std::ostream&) = 0;

    virtual void serialize(std::ostream&) = 0;
    virtual void deserialize(std::istream&) = 0;

};