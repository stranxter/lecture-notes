#pragma once
#include "figure.h"

#include <vector>

class Group : public Figure
{
    public:
    Group();
    Group(const std::vector<Figure*>&,Color=white);
    Group(const Group&);

    double surface();
    double perimeter();

    void draw();
    void toSVG(std::ostream&);

    void serialize(std::ostream&);
    void deserialize(std::istream&);

    void setColor(Color);

    virtual Figure* clone();    

    ~Group();

    private:
    std::vector<Figure*> parts;

};