#include "tokenize.hpp"
#include "utils.hpp"

#include <cassert>


bool whitespace(char c)
{
    return c <= 32;
}

std::istream& operator>>(std::istream& in, Token& token)
{

    while(whitespace(in.peek()))
    {
        in.get();
    }

    if(in.peek() == '(')
    {
        token.type = Token::OPEN_PAREN;
        token.data.symbol = in.get();
    }
    else if(in.peek() == ')')
    {
        token.type = Token::CLOSE_PAREN;
        token.data.symbol = in.get();
    }
    else if(isOperator(in.peek()))
    {
        token.type = Token::OPERATOR;
        token.data.symbol = in.get();
    }
    else if(std::isdigit(in.peek()))
    {
        token.type = Token::NUMBER;
        in >> token.data.number;
    } else if (in.peek() == 's')
        //'set' or 's'
    {
        in.get();
        if (in.peek() == 'e')
        {
            in.get(); in.get();
            token.type = Token::SET;

        } else {
            assert(!std::isalpha(in.peek()));
            token.type = Token::VAR_NAME;
            token.data.symbol = 's';
        }
    } else if (std::isalpha(in.peek()))
    {
            token.type = Token::VAR_NAME;
            token.data.symbol = in.get();
            assert(!std::isalpha(in.peek()));

    } else if (in.peek() == '{')
    {
        token.type = Token::OPEN_BLOCK;
        token.data.symbol = in.get();
    } else if (in.peek() == '}')
    {
        token.type = Token::CLOSE_BLOCK;
        token.data.symbol = in.get();
    }
    else
    {
        std::cerr << "Invalid token" << std::endl;
        throw "Invalid token";
    }

    return in;
}

Token expect(Token::TokeType type, std::istream &in)
{
    Token result;
    in >> result;
    assert(result.type == type);
    return result;

}

Token::TokeType peektokentype(std::istream& in)
{
    Token t;
    std::streampos pos = in.tellg();
    in >> t;
    in.seekg(pos);
    return t.type;
}