#ifndef __EXPRTREE_H
#define __EXPRTREE_H

#include "tokenizer.h"
#include <iostream>

/*
<expression> ::= <constant> | <operator application>
<constant> ::= <number> 
<operator application> ::= (<expression> <operator> <expression>)
*/

class Expression
{
    public:
    virtual void exportDot(std::ostream&) = 0;
    virtual int evaluate() = 0;
    virtual Expression* copy() = 0;
    virtual ~Expression();
};

class ConstExpression : public Expression
{
    public:
    ConstExpression(int);
    void exportDot(std::ostream&);
    int evaluate();
    Expression* copy();

    private:
    int value;
};

class OperatorExpression : public Expression
{
    
    public:
    OperatorExpression(char,Expression*,Expression*);
    OperatorExpression(const OperatorExpression&);
    void exportDot(std::ostream&);
    int evaluate();
    Expression* copy();
    
    ~OperatorExpression();

    private:
    char op;
    Expression *arg1, *arg2;

};

Expression* parseExpression (Tokenizer& tokenizer);

#endif