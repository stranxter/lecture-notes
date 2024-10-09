#include "expression.h"
#include <string>
#include <functional>

ExprConstant::ExprConstant(int val):_value(val){}

int ExprConstant::value() const
{
    return _value;
}

ExprOperator::ExprOperator(char _op, Expression *_left, Expression *_right)
            :op(_op),left(_left),right(_right){}


std::function<int(int,int)> to_function(char op)
{
    switch(op)
    {
        case '+': return [](int x, int y)->int {return x+y;};
        case '-': return [](int x, int y)->int {return x-y;};
        case '*': return [](int x, int y)->int {return x*y;};
        case '/': return [](int x, int y)->int {return x/y;};
        default: throw std::string("Uknown operator:") + op;
    }
}

int ExprOperator::apply(char op, Expression *left, Expression *right)
{
    return to_function(op)(left->value(),right->value());
}

int ExprOperator::value() const
{

    return apply(op,left,right);

}

ExprIf::ExprIf(Expression *_cond, Expression *_iftrue, Expression *_iffalse)
            :cond(_cond),iftrue(_iftrue),iffalse(_iffalse){}

int ExprIf::value() const
{
    return cond->value() ? iftrue->value() : iffalse->value();
}
