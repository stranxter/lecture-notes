#pragma once
#include "figure.h"
#include <vector>

class Group : public Figure
{

    public:

    Group(const Group&);
    Group() = default;

    double area() const;
    double perimeter() const;
    void load(std::istream& in);

    Group& operator=(const Group&);

    Figure* copy() const;

    void add(Figure*);
    void clear();

    void accept(Visitor* v);

    ~Group();

    std::vector<Figure*>::iterator begin();
    std::vector<Figure*>::iterator end();

    unsigned int size() const;

    private:
    std::vector<Figure*> figures;

    void copyContents(const Group&);


};