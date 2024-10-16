#pragma once
#include <iostream>
#include <string>

struct Token
{
    enum TokenType {open_par, number, oper, close_par, kwif, kwthen, kwelse};
    TokenType type;
    std::string val;
};

class TokenStream
{
    public:
    TokenStream(std::istream&);
    Token get();
    Token peek();
    bool eof();

    private:
    std::istream &in;
    Token peekedToken;
    bool isTokenPeeked;
};

std::ostream& operator << (std::ostream &out, const Token &t);

std::vector<Token> tokenize(std::istream &in);
