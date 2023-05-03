#pragma once

#include <vector>
#include "figure.h"

class Group : public Figure
{

    public:
    void addElement(Figure *f);

    double perimeter();
    double surface();

    void writeToStream(std::ostream&);
    void loadFromStream(std::istream&);

    void translate(double x, double y);
    void draw();

    Figure* clone();

    ~Group();

    private:
    std::vector<Figure*> figures;
};