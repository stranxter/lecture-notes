#pragma once

#include <vector>
#include <iostream>

class Visitor;

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perim() = 0;
    virtual void save(std::ostream&) = 0;
    virtual void load(std::istream&) = 0;

    virtual void accept(Visitor*)=0;

    static Figure *loadFigure(std::istream&in);
    static double sumSurfaces(std::vector<Figure*> figures);

    virtual Figure *copy()=0;

    virtual ~Figure();

    protected:
    char label[15];
};

std::istream& operator >> (std::istream& in, std::vector<Figure*>& figures);
std::ostream& operator << (std::ostream& out, std::vector<Figure*> figures);


