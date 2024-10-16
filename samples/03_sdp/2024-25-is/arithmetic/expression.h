#pragma once

class Expression
{
    public:
    virtual int value() const = 0;
};

class ExprConstant : public Expression
{
    public:
    ExprConstant(int);
    int value() const;
    private:
    int _value;
};

class ExprOperator : public Expression
{
    public:
    ExprOperator(char, Expression*, Expression*);
    int value() const;

    private:
    char op;
    Expression *left;
    Expression *right;

};

class ExprIf : public Expression
{
    public:
    ExprIf(Expression *_cond, Expression *_iftrue, Expression *_iffalse);
    int value() const;

    private:
    Expression *cond;
    Expression *iftrue;
    Expression *iffalse;
};