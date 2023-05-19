#pragma once

#include <vector>
#include "figure.h"

class Group : public Figure
{

    public:
    Group();

    void setPosition(Point2D);
    Point2D getPosition();

    void addElement(Figure *f);

    double perimeter();
    double surface();

    void writeToStream(std::ostream&);
    void loadFromStream(std::istream&);

    void translate(double x, double y);
    void draw();

    Figure* clone();

    ~Group();

    const std::vector<Figure*>& getMembers();

    void accept(Visitor*);

    private:
    std::vector<Figure*> figures;
    Point2D position;

    void clear();


};