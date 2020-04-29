#pragma once

#include <iostream>

class Figure
{
    public:
    virtual double surface() = 0;
    virtual double perim() = 0;
    virtual void save(std::ostream &out) = 0;
    virtual void load(std::istream &in) = 0;
    //virtual Figure* copy() = 0;

    static double sumSurface(std::vector<Figure*> figures);
    static Figure* readFigure(std::istream&);

    virtual ~Figure();

    protected:
    char label[15];
};


std::ostream& operator << (std::ostream &out, std::vector<Figure*> figures);
std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures);
