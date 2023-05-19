#pragma once

#include <iostream>
#include "visitor.h"
#include "utils.h"
#include "draw/sdlwrapper.h"

class Figure
{
    public:

    Figure();

    virtual void accept(Visitor*) = 0;

    virtual double perimeter() = 0;
    virtual double surface() = 0;

    virtual void writeToStream(std::ostream&) = 0;
    virtual void loadFromStream(std::istream&) = 0;

    virtual void draw() = 0;

    virtual void translate(double x, double y) = 0;

    virtual Figure* clone() = 0;

    virtual ~Figure() = default;

    void setColor(sdlw::color);
    sdlw::color getColor();

    private:
    sdlw::color col;

};

std::ostream& operator << (std::ostream &out, const std::vector<Figure*>& figures);
