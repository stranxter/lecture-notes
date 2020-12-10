#ifndef __EXPRTREE_
#define __EXPRTREE_

#include "tokenizer.h"
#include <iostream>


class ExprVisitor;

class Expression
{
    public:
    virtual Expression* copy() = 0;
    virtual void accept(ExprVisitor*) = 0;

    virtual ~Expression();
};

class ConstExpression : public Expression
{
    public:
    ConstExpression(int);
    Expression* copy();

    void accept(ExprVisitor*);

    int getValue();
    
    private:
    int value;
};

class OperatorExpression : public Expression
{
    public:
    OperatorExpression(Expression *_left, Expression *_right, char _oper);
    Expression* copy();

    void accept(ExprVisitor*);

    char getOper();
    Expression *getLeftOperand();
    Expression *getRightOperand();

    ~OperatorExpression();
    private:
    char oper;
    Expression *left, *right;

};

Expression* createExpressionTree (Tokenizer&);

#endif