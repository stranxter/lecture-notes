#pragma once

#include "figure.h"
#include <vector>

class Group : public Figure
{
    public:

    Group();
    Group(const Group &other);

    double surface();
    double perim();
    void save(std::ostream &out);
    void load(std::istream &in);

    void addFigure(Figure *f);

    ~Group();

    private:
    std::vector<Figure*> contents;

};