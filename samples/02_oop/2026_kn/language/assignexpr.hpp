#pragma once

#include "expression.hpp"

class AssignExpr : public Expression
{
    public:
    AssignExpr(char varname, Expression* expr);
    double value(std::vector<double> &memory) const override;
    Expression *copy() const override;

    ~AssignExpr();

    private:
    char varname;
    Expression* expr;
};