#include "tokenizer.h"

std::istream& operator>>(std::istream& in, Tokenizer::Token &t)
{

    char next = in.peek();

    while (next == ' ' || 
           next == '\n' ||
           next == '\t' ||
           next == '\r')
    {
        in.get();
        next = in.peek();
    }

    switch(next)
    {
        case '(':
            t.type = Tokenizer::OPEN_PAR;
            in.get();
        break;
        case ')':
            t.type = Tokenizer::CLOSE_PAR;
            in.get();
        break;
        case '+':
        case '-':
        case '*':
        case '/':
            t.type = Tokenizer::OPERATOR;
            t.symbol = next;
            in.get();
        break;
        default:
            if(!std::isdigit(next))
            {
                throw "Unexpected character type!";
            }
            t.type = Tokenizer::NUMBER;
            in >> t.value;
    }

    return in;
}