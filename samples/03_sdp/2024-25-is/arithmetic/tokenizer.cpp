#include "tokenizer.h"

std::ostream& operator << (std::ostream &out, const Token &t)
{
    out << "Token(" << t.type << "," << t.val << ")";
    return out;
}

bool isOperator(char c)
{
    return c == '+' || 
           c == '-' || 
           c == '*' || 
           c == '/' ||
           c == '$';
}

bool is_whitespace(char c)
{
    return c == ' ' ||
           c == '\n' || 
           c == '\r';
}


TokenStream::TokenStream(std::istream &_in):in(_in){};

Token TokenStream::get()
{ 
    if (isTokenPeeked)
    {
        isTokenPeeked = false;
        return peekedToken;
    }
    while (is_whitespace(in.peek()))
    {
        in.get();
    }
    char c = in.peek();
    if (isdigit(c))
    {
        std::string num;
        while (isdigit(c))
        {
            num += c;
            in.get();
            c = in.peek();
        }
        return Token{Token::number, num};
    } else if (c == '(')
    {
        in.get();
        return Token{Token::open_par, "("};
    } else if (c == ')')
    {
        in.get();
        return Token{Token::close_par, ")"};
    } else if (isOperator(c))
    {
        in.get();
        return Token{Token::oper, std::string("") + c};
    } else if (c == 'i' || c == 't' || c == 'e')
    {
        std::string kw;
        in >> kw;
        if (kw == "if")
        {
            return Token{Token::kwif,"if"};
        } else if (kw == "then")
        {
            return Token{Token::kwthen,"then"};
        } else if (kw == "else")
        {
            return Token{Token::kwelse,"else"};
        } else throw std::string("Unknown keyword:") + kw;

    }
    else
    {
        std::cerr << "char=" << c << "\n" << std::endl;
        throw std::runtime_error("Invalid character");
    }
}

Token TokenStream::peek()
{
    if(isTokenPeeked)
    {
        return peekedToken;
    }
    peekedToken = get();
    isTokenPeeked = true;
    return peekedToken;
}

bool TokenStream::eof()
{
    return in.eof();
}