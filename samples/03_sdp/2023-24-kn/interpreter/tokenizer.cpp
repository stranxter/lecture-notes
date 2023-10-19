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
            t.symbol = next;
            in.get();
        break;
        case ')':
            t.type = Tokenizer::CLOSE_PAR;
            t.symbol = next;
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
        case '$':
            t.type = Tokenizer::EOE;
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

std::ostream& operator<<(std::ostream &out, const Tokenizer::Token &t)
{
    switch(t.type)
    {
        case Tokenizer::NUMBER:
            out << t.value;
            break;
        case Tokenizer::OPERATOR:
        case Tokenizer::OPEN_PAR:
        case Tokenizer::CLOSE_PAR:
        case Tokenizer::EOE:
            out << t.symbol;
            break;
    }

    return out;
}