#pragma once

#include "figure.h"

class Triangle : public Figure
{

    public:
    Triangle(Point,Point,Point);

    double surface();
    double perimeter();
    void draw();
    void toSVG(std::ostream&);


    private:
    Point p1,p2,p3;

};