
#include "exptree.h"
#include <cassert>
#include "visitorbase.h"

Expression::~Expression(){}

ConstExpression::ConstExpression (int _value):value(_value)
{
}

int ConstExpression::getValue()
{
    return value;
}

Expression* ConstExpression::copy()
{
    return new ConstExpression(*this);
}

void ConstExpression::accept(ExprVisitor *visitor)
{
    visitor->processConstExpression(this);
}


char OperatorExpression::getOper()
{
    return oper;
}
Expression* OperatorExpression::getLeftOperand()
{
    return left;
}
Expression* OperatorExpression::getRightOperand()
{
    return right;
}


OperatorExpression::OperatorExpression (Expression *_left, Expression *_right, char _oper)
{
    left = _left->copy();
    right = _right->copy();
    oper = _oper;
}

Expression* OperatorExpression::copy()
{
    return new OperatorExpression(*this);
}


OperatorExpression::~OperatorExpression()
{
    delete left;
    delete right;
}
void OperatorExpression::accept(ExprVisitor *visitor)
{
    visitor->processOperatorExpression(this);
}


Expression* createExpressionTree (Tokenizer &t)
{
    //1

    Tokenizer::Token token = t.getNextToken();

    if (token.type == Tokenizer::Token::number)
    {
        return new ConstExpression (token.val);
    }

    // ( <left operand> <operator> <right operand> )
    //  /|\
    //   |
    //

    assert (token.type == Tokenizer::Token::open_par);

    Expression *left = createExpressionTree (t);

    // ( <left operand> <operator> <right operand> )
    //                /|\
    //                 |
    //

    token = t.getNextToken();
    assert (token.type == Tokenizer::Token::oper);

    char op = token.symbol;

    // ( <left operand> <operator> <right operand> )
    //                           /|\
    //                            |
    //

    Expression *right = createExpressionTree (t);

    // ( <left operand> <operator> <right operand> )
    //                                           /|\
    //                                            |
    //

    assert (t.getNextToken().type == Tokenizer::Token::close_par);

    return new OperatorExpression (left, right, op);


}