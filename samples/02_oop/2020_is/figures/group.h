#pragma once

#include <vector>
#include "figure.h"

class Group : public Figure
{

    public:

    Group();
    Group(const Group& other);

    double surface();
    double perim();
    void save(std::ostream&);
    void load(std::istream&);

    void addFigure(Figure *f);

    Figure *copy();

    ~Group();

    private:
    std::vector<Figure*> contents;
};