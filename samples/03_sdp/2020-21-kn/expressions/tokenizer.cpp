#include "tokenizer.h"
#include <cassert>

Tokenizer::Tokenizer(std::istream &_in):in(_in){}

Tokenizer::Token Tokenizer::nextToken()
{
    clearWhiteSpace();

    Tokenizer::Token result({Tokenizer::Token::error,-1,'?'});

    char c = in.peek();

    if (std::isdigit(c))
    {  
        result.type = Tokenizer::Token::number;
        in >> result.numval;
    } else if (c == '(')
    {
        result.type = Tokenizer::Token::open_par;
        in >> result.c;
    } else if (c == ')')
    {
        result.type = Tokenizer::Token::close_par;
        in >> result.c;
    } else if (c == '+' || c == '*' || c == '-' || c == '/')
    {
        result.type = Tokenizer::Token::oper;
        in >> result.c;
    } else 
    {
        assert(false);
    }

    return result;

}

bool Tokenizer::moreTokens()
{
    return (bool)in;
}

void Tokenizer::clearWhiteSpace()
{
    while (in && in.peek() <= 32)
    {
       in.get(); 
    }
}

Tokenizer& operator>> (Tokenizer& tokenizer,Tokenizer::Token& result)
{
    result = tokenizer.nextToken();
    return tokenizer;

}
