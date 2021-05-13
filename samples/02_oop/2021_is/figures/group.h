#pragma once

#include <vector>
#include "figure.h"

class Group : public Figure
{

    public:
    
    Group();

    double surface();
    void saveToFile(std::ostream&);
    void loadFromFile (std::istream&);

    void addFigure(Figure *f);

    virtual void draw();
    Figure* clone();

    void clearContents();
    ~Group();

    private:

    std::vector<Figure*> contents;

};