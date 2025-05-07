#pragma once
#include <iostream>

struct Point
{
    double x;
    double y;
};

struct Color
{
    int r;
    int g;
    int b;
};

const Color red = {255,0,0},
            green = {0,255,0},
            blue = {100,100,255},
            white = {255,255,255},
            yellow = {255,255,0};


std::ostream& operator << (std::ostream&,const Point&);
std::istream& operator >> (std::istream&,Point&);

class Figure
{
    public:
    Figure();
    Figure(Color);

    virtual double surface() = 0;
    virtual double perimeter() = 0;

    virtual void draw() = 0;
    virtual void toSVG(std::ostream&) = 0;

    virtual void serialize(std::ostream&) = 0;
    virtual void deserialize(std::istream&) = 0;

    virtual Figure* clone() = 0;

    virtual void setColor(Color);

    virtual ~Figure() = default;

    protected:
    void predraw();
    Color color;

};

std::ostream& operator<<(std::ostream& out,const std::vector<Figure*> v);
std::istream& operator>>(std::istream &in, std::vector<Figure*>& v);

