#include "exprtree.h"
#include "evalutils.h"
#include <cmath>
#include <iostream>

Expression::~Expression(){}

ExprConst::ExprConst(double _val):val(_val)
{
}
double ExprConst::eval() const
{
    return val;
}

ExprConst* ExprConst::clone()
{
    return new ExprConst(*this);
}

ExprArith::ExprArith(const ExprArith &other)
{
    opfn = other.opfn;
    symbol = other.symbol;
    left = other.left->clone();
    right = other.right->clone();
}

void ExprConst::toDotty(std::ostream& out) const
{
    out << (long)this << "[label=\"" << val << "\"];\n";
}


ExprArith::ExprArith(char _op, Expression *_left, Expression *_right)
{
    opfn = fn(_op);
    symbol = _op;

    left = _left->clone();
    right = _right->clone();
}
double ExprArith::eval() const
{
    return opfn(left->eval(), right->eval());
}
ExprArith* ExprArith::clone()
{
    return new ExprArith(*this);
}

void ExprArith::toDotty(std::ostream& out) const
{
    out << (long)this << "[label=\"" << symbol << "\"];\n";
    out << (long)this << "->" << (long)(this->left) << ";\n";
    out << (long)this << "->" << (long)(this->right) << ";\n";

    left->toDotty(out);
    right->toDotty(out);
}


ExprArith::~ExprArith()
{
    delete left;
    delete right;
}

ExprIf::ExprIf(Expression *_cond, Expression *_iftrue, Expression *_iffalse):cond(_cond), iftrue(_iftrue), iffalse(_iffalse)
{

}
ExprIf::ExprIf(const ExprIf &other)
{
    cond = other.cond->clone();
    iftrue = other.iftrue->clone();
    iffalse = other.iffalse->clone();
}

double ExprIf::eval() const
{
    if(std::abs(cond->eval()) > 0.005)
    {
        return iftrue->eval();
    }

    return iffalse->eval();
}
ExprIf* ExprIf::clone()
{
    return new ExprIf(*this);
}

void ExprIf::toDotty(std::ostream& out) const
{
    out << (long)this << "[label=\"IF\"];\n";
    out << (long)this << "->" << (long)(this->cond) << ";\n";
    out << (long)this << "->" << (long)(this->iftrue) << ";\n";
    out << (long)this << "->" << (long)(this->iffalse) << ";\n";

    cond->toDotty(out);
    iftrue->toDotty(out);
    iffalse->toDotty(out);
}


ExprIf::~ExprIf()
{
    delete cond;
    delete iftrue;
    delete iffalse;
}
