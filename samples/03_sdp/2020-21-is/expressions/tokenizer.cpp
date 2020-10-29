#include "tokenizer.h"

Tokenizer::Tokenizer (std::istream& _in):in(_in){};

typename Tokenizer::Token Tokenizer::getNextToken()
{

    typename Tokenizer::Token result{ Tokenizer::Token::error,' ',-1};
    
    clearWhiteSpace();

    char next = in.peek();
    
    if (std::isdigit(next)) 
    {
        //123+   345)
        in >> result.val;
        result.type = Tokenizer::Token::number;
    } else if (next == '(')
    {
        in.get();
        result.type = Tokenizer::Token::open_par;
        result.symbol = '(';
    } else if (next == ')')
    {
        in.get();
        result.type = Tokenizer::Token::close_par;
        result.symbol = ')';
    } else if (next == '+' || next == '-' || next == '*' || next == '/')
    {
        result.symbol = next;
        in.get();
        result.type = Tokenizer::Token::oper;

    } 


    return result;
}

bool Tokenizer::isWhiteSpace (char c)
{
    return c <= 32;
}

void Tokenizer::clearWhiteSpace()
{
    while (isWhiteSpace(in.peek()))
    {
        in.get();
    }
}

bool Tokenizer::hasMoreTokens()
{
    return (bool)in;
}
