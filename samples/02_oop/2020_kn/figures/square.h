#pragma once

#include "figure.h"

class Square : public Figure
{
    public:
    Square (double _a);

    double perim();
    double surface();
    int nsides();
    void save(std::ostream &out);
    void load(std::istream &in);

    private:
    double a;
};

