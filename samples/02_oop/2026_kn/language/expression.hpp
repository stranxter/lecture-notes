#pragma once
#include <vector>

class Expression
{
    public:
    virtual double value(std::vector<double> &memory) const = 0;

    virtual Expression *copy() const = 0;

    virtual ~Expression();
};