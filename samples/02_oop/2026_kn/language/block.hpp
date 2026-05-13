#pragma once

#include "expression.hpp"

class Block : public Expression
{
    public:
    Block();
    void add(Expression* expr);
    double value(std::vector<double> &memory) const override;
    Expression *copy() const override;

    ~Block();

    private:
    std::vector<Expression*> expressions;
};