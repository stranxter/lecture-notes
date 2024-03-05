#pragma once

#include "figure.h"

class Circle : public Figure
{

    public:
    Circle(Point2D _center, double _r);

    double surface();

    double perimeter();

    void writeToStream(std::ostream& out);

    void loadFromStream(std::istream &in);

    void draw();

    void translate(double x, double y);
    
    Figure* clone();

    Point2D getCenter() const;
    double getRadius() const;

    void accept(Visitor*);

    private:
    Point2D center;
    double r;
};
