#pragma once

#include "figure.h"

class Triangle : public Figure
{

    public:
    Triangle(Point,Point,Point,Color=white);
    Triangle();

    double surface();
    double perimeter();
    void draw();
    void toSVG(std::ostream&);
    void serialize(std::ostream&);
    void deserialize(std::istream&);
    
    virtual Figure* clone();
    
    private:
    Point p1,p2,p3;

};