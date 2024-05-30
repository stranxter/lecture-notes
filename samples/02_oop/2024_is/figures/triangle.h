#pragma once
#include "figure.h"
#include "utils.h"

class Triangle : public Figure
{

    public:

    Triangle(const Point& _p1, const Point& _p2, const Point& _p3);


    double area() const;
    double perimeter() const;
    void load(std::istream& in);
    Figure* copy() const;


    void accept(Visitor* v);

    double sidea() const;
    double sideb() const;
    double sidec() const;

    Point getp1() const;
    Point getp2() const;
    Point getp3() const;

    private:
    Point p1;
    Point p2;
    Point p3;
};