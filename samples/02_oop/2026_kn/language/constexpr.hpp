#pragma once

#include "expression.hpp"

class Constexpr : public Expression
{
    public:
    Constexpr(double value);
    double value(std::vector<double> &memory) const override;

    Expression *copy() const override;

    private:
    double _value;
};