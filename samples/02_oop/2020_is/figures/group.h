#pragma once

#include <vector>
#include "figure.h"

class Group : public Figure
{

    public:

    Group(double _x, double _y);
    Group(const Group& other);

    double surface();
    double perim();
    void save(std::ostream&);
    void load(std::istream&);

    void addFigure(Figure *f);

    void accept(Visitor*);

    Figure *copy();

    ~Group();
    size_t nElements();
    Figure* getElement(size_t i);

    double get_x();
    double get_y();

    private:
    double x,y;
    std::vector<Figure*> contents;
};