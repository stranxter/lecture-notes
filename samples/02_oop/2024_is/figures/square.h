#pragma once

#include "figure.h"
#include "utils.h"

class Square : public Figure
{

    public:
    Square(const Point& _p1, const Point& _p2);
    double area() const;
    double perimeter() const;
    
    void load(std::istream& in);
    Figure* copy() const;


    void accept(Visitor* v);
    double side() const;

    Point getp1() const;
    Point getp2() const;

    private:
    Point p1;
    Point p2;
};