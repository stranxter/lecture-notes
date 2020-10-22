#include <iostream>
#include <cassert>

#include "tokenizer.h"


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

    switch (op.symbol)
    {
        case '+': return left + right;
        case '-': return left - right; 
        case '*': return left * right; 
        case '/': return left / right; 
        default: assert (false);
    }

    return -1;
}



int main()
{
    Tokenizer tokenizer(std::cin);

    std::cout << evaluateExpression (tokenizer) << std::endl;
}