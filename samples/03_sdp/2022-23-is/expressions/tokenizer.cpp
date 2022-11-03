#include "tokenizer.h"

bool digit(char c)
{
    return c >= '0' && c <= '9';
}

bool white (char c)
{
    return c == ' ' || 
           c == '\r' ||
           c == '\n' ||
           c == '\t'; 
}

void clearWhiteSpace(std::istream &in)
{
    while (white(in.peek()))
    {
        in.get();
    }
} 

std::istream& operator>>(std::istream &in, Token &t)
{
    clearWhiteSpace(in);
    char next = in.peek();

    if (!in || in.eof())
        return in;

    if (digit(next))
    {
        t.type = Token::NUMBER;
        in >> t.value;
        t.symbol = 0;
    } else 
    {
        switch (next)
        {
            case '+': case '-': case '/': case '*': 
                t.type = Token::OPERATOR;
                break;
            case '(': 
                t.type = Token::OPEN_PAR;
                break;
            case ')': 
                t.type = Token::CLOSE_PAR;
                break;
            case '!':
                t.type = Token::EOE;
                break;
            default: throw "Unrecognized token"; 
        }
        t.symbol=next;
        t.value=0;
        in.get();
    }
    return in;
}

