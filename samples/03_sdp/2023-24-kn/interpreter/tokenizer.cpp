#include "tokenizer.h"

std::istream& operator>>(std::istream& in, Tokenizer::Token &t)
{

    char next = in.peek();

    //remove whitespace
    while (next == ' ' || 
           next == '\n' ||
           next == '\t' ||
           next == '\r')
    {
        in.get();
        next = in.peek();
    }

    //try simple cases
    switch(next)
    {
        case '(':
            t.type = Tokenizer::OPEN_PAR;
            t.symbol = next;
            in.get();
            return in;
        case ')':
            t.type = Tokenizer::CLOSE_PAR;
            t.symbol = next;
            in.get();
            return in;
        case '+':
        case '-':
        case '*':
        case '/':
            t.type = Tokenizer::OPERATOR;
            t.symbol = next;
            in.get();
            return in;
        case '$':
            t.type = Tokenizer::EOE;
            t.symbol = next;
            in.get();
            return in;
    }

    //NUMBER
    if(std::isdigit(next))
    {
        t.type = Tokenizer::NUMBER;
        in >> t.value;
        return in;
    }

    //Assuming non-single character keyword
    std::string keyword;
    in >> t.keyword;

    //IF
    if(t.keyword=="if")
    {
        t.type = Tokenizer::IF;
        return in;
    }

    //THEN
    if(t.keyword=="then")
    {
        t.type = Tokenizer::THEN;
        return in;
    }

    //else
    if(t.keyword=="else")
    {
        t.type = Tokenizer::ELSE;
        return in;
    }

    throw "Syntax error. Unknown token";

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
        default:
            out << t.keyword;
    }

    return out;
}


Tokenizer::Tokenizer(std::istream &_in):in(_in), peeked(nullptr)
{

}

typename Tokenizer::Token Tokenizer::getNextToken()
{

    typename Tokenizer::Token result;

    if (peeked != nullptr)
    {
        result = *peeked;
        delete peeked;
        peeked = nullptr;
    } else 
    {
        in >> result;
    }

    return result;
}

typename Tokenizer::Token Tokenizer::peekToken()
{
    if(peeked == nullptr)
    {
        peeked = new Token;
        in >> *peeked;
    }
    return *peeked;
}
