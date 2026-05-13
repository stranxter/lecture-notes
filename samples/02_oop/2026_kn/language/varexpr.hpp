#pragma once
#include "expression.hpp"

class VarExpr : public Expression
{
    public:
    VarExpr(char name);
    double value(std::vector<double> &memory) const override;

    Expression *copy() const override;

    private:
    char varname;
};