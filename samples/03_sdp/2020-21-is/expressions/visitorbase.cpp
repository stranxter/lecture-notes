#include "visitorbase.h"
#include "expressions.h"

ExprDotExport::ExprDotExport (std::ostream &_out):out(_out){}

void ExprDotExport::processConstExpression(ConstExpression *expr)
{
    out << (long)expr << "[label=\"" << expr->getValue() << "\"];\n"; 

}

void ExprDotExport::processOperatorExpression(OperatorExpression *expr)
{
    out << (long)expr << "[label=\"" << expr->getOper() << "\"];\n"; 

    out << (long)expr << "->" << (long)expr->getLeftOperand() << ";\n";
    out << (long)expr << "->" << (long)expr->getRightOperand() << ";\n";

    expr->getLeftOperand()->accept(this);
    expr->getRightOperand()->accept(this);

}

int EpxrEvaluator::getResult()
{
    return result;
}

void EpxrEvaluator::processConstExpression(ConstExpression *expr)
{
    result = expr->getValue();
}

void EpxrEvaluator::processOperatorExpression(OperatorExpression *expr)
{
    //return apply(oper,left->evaluate(),right->evaluate());

    expr->getLeftOperand()->accept(this);
    int saveLeftValue = result;

    expr->getRightOperand()->accept(this);

    result = apply(expr->getOper(),saveLeftValue,result);

}
