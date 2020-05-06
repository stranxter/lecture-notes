#pragma once

#include "figure.h"
#include <vector>

class Group : public Figure
{
    public:

    Group(double _x, double _y);
    Group(const Group &other);

    double surface();
    double perim();
    void save(std::ostream &out);
    void load(std::istream &in);

    void addFigure(Figure *f);
    Figure* copy ();

    void accept(Visitor*);

    ~Group();

    size_t nElements();
    Figure *getElement(size_t);

    double get_x();
    double get_y();

    private:
    double x,y;
    std::vector<Figure*> contents;

};