#pragma once

#include "expression.hpp"

class BinExpr : public Expression
{
    public:
    BinExpr(Expression* _left, Expression* _right, char _oper);
    BinExpr(const BinExpr& other);

    BinExpr& operator=(const BinExpr& other);

    double value(std::vector<double> &memory) const override;
    Expression *copy() const override;

    ~BinExpr();

    private:
    char opersymbol;
    Expression* left;
    Expression* right;
};