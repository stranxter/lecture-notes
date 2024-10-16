#include "expression.h"
#include <string>
#include "evalutils.h"

ExprConstant::ExprConstant(int val):_value(val){}

int ExprConstant::value() const
{
    return _value;
}

ExprOperator::ExprOperator(char _op, Expression *_left, Expression *_right)
            :op(_op),left(_left),right(_right){}



int ExprOperator::value() const
{

    return apply(op,left->value(),right->value());

}

ExprIf::ExprIf(Expression *_cond, Expression *_iftrue, Expression *_iffalse)
            :cond(_cond),iftrue(_iftrue),iffalse(_iffalse){}

int ExprIf::value() const
{
    return cond->value() ? iftrue->value() : iffalse->value();
}
