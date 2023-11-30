#pragma once
#include <functional>

class Expression
{
    public:
    virtual double eval() const = 0;

    virtual Expression* clone() = 0;

    virtual void toDotty(std::ostream&) const = 0;

    virtual ~Expression();
};

class ExprConst : public Expression
{
    public:
    ExprConst(double _val);
    double eval() const;

    ExprConst* clone();

    void toDotty(std::ostream&) const;

    private:
    double val;
};

class ExprArith : public Expression
{
    public:
    ExprArith(char _op, Expression *_left, Expression *_right);
    ExprArith(const ExprArith&);

    double eval() const;
    ExprArith* clone();

    void toDotty(std::ostream&) const;

    ~ExprArith();
    private:
    std::function<double(double,double)> opfn;
    char symbol;
    Expression *left, *right;

};

class ExprIf : public Expression
{
    public:
    ExprIf(Expression *_cond, Expression *_iftrue, Expression *_iffalse);
    ExprIf(const ExprIf&);

    double eval() const;
    ExprIf* clone();

    void toDotty(std::ostream&) const;


    ~ExprIf();
    private:
    Expression *cond, *iftrue, *iffalse;

};




