#include "binexpression.hpp"

#include "utils.hpp"

BinExpr::BinExpr(Expression *_left, Expression *_right, char _oper)
{
    left = _left->copy();
    right = _right->copy();
    opersymbol = _oper;
}
BinExpr::BinExpr(const BinExpr& other)
{
    left = other.left->copy();
    right = other.right->copy();
    opersymbol = other.opersymbol;
}

double BinExpr::value(std::vector<double> &memory) const 
{ 
    return oper(opersymbol)( left->value(memory),  right->value(memory) );
}

Expression *BinExpr::copy() const
{
    return new BinExpr(left, right, opersymbol);
}

BinExpr::~BinExpr()
{
    delete left;
    delete right;
}

BinExpr& BinExpr::operator=(const BinExpr& other)
{
    if (this != &other)
    {
        delete left;
        delete right;

        left = other.left->copy();
        right = other.right->copy();
        opersymbol = other.opersymbol;
    }
    return *this;
}