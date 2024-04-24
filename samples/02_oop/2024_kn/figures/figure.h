#pragma once

#include <iostream>

class Figure
{

    public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    virtual void saveToFile(std::ostream&) const = 0;
    virtual void loadFromFile(std::istream&) {};

    static double scale;
    static Figure* figureFactory(std::string type);
};


std::ostream& operator<< (std::ostream&,const Figure* f);
