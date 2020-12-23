#include "exprtree.h"
#include "expressions.h"


Expression::~Expression()
{}

int ConstExpression::evaluate()
{
    return value;
}

ConstExpression::ConstExpression(int _val):value(_val)
{
}

Expression* ConstExpression::copy()
{
    return new ConstExpression(*this);
}

void ConstExpression::exportDot(std::ostream &out)
{
    /*
    <id>[label="xxx"];
    */

   out << (long)this << "[label=\"" << value << "\"];\n";

}

OperatorExpression::~OperatorExpression()
{
    delete arg1;
    delete arg2;
}

OperatorExpression::OperatorExpression(char _op, Expression *_arg1, Expression *_arg2)
{
    op = _op;
    arg1 = _arg1->copy();
    arg2 = _arg2->copy();
}

int OperatorExpression::evaluate()
{
    return apply(op,
                 arg1->evaluate(),
                 arg2->evaluate());
}

Expression* OperatorExpression::copy()
{
    return new OperatorExpression(*this);
}

OperatorExpression::OperatorExpression(const OperatorExpression &other)
{
    op=other.op;
    arg1 = other.arg1->copy();
    arg2 = other.arg2->copy();
}


void OperatorExpression::exportDot(std::ostream &out)
{
    out << (long)this << "[label=\"" << op << "\"];\n";

    //<id parent>-><id child>

    out << (long)this << "->" << (long)(arg1) << ";\n";
    out << (long)this << "->" << (long)(arg2) << ";\n";

    arg1->exportDot(out);
    arg2->exportDot(out);
    
}


Expression* parseExpression (Tokenizer& tokenizer)
{
    Tokenizer::Token token = tokenizer.nextToken();

    if (token.type == Tokenizer::Token::number)
    {
        return new ConstExpression(token.numval);
    }   
    //((1+2)*3)

    assert(token.type == Tokenizer::Token::open_par);

    Expression *left = parseExpression(tokenizer);
    
    token = tokenizer.nextToken();
    char oper = token.c;
    assert(token.type == Tokenizer::Token::oper);
    
    Expression *right = parseExpression(tokenizer);
    
    token = tokenizer.nextToken();

    assert(token.type == Tokenizer::Token::close_par);

    Expression *result = new OperatorExpression(oper,left,right);
    delete left;
    delete right;
    return result;
    
}
