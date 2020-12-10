#include <iostream>
#include <cassert>
#include <fstream>

#include "tokenizer.h"
#include "expressions.h"
#include "exptree.h"
#include "visitorbase.h"

int evaluateExpression (Tokenizer &input)
{
    assert (input.hasMoreTokens());

    Tokenizer::Token token = input.getNextToken();
    
    if (token.type == Tokenizer::Token::number)
    {
        return token.val;
    }
    assert (token.type == Tokenizer::Token::open_par);

    int left = evaluateExpression(input);
    
    Tokenizer::Token op = input.getNextToken();
    assert (op.type == Tokenizer::Token::oper);

    int right = evaluateExpression(input);
    
    //премахваме оставащата затваряща скоба
    token = input.getNextToken();
    assert (token.type == Tokenizer::Token::close_par);

    return apply (op.symbol,left,right);

    
}



int main()
{
    Tokenizer tokenizer(std::cin);

    //std::cout << evaluateExpression (tokenizer) << std::endl;

    Expression *expr = createExpressionTree(tokenizer);

    std::ofstream dot ("expr.dot");
    ExprDotExport exporter (dot);

    dot << "digraph G{\n";
    expr->accept(&exporter);
    dot << "}\n";

    EpxrEvaluator evaluator;
    expr->accept(&evaluator);

    std::cout << "Val=" << evaluator.getResult() << std::endl;
    

}