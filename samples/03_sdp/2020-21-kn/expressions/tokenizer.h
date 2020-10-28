#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>
#include <iostream>


class Tokenizer
{
    public:

    struct Token
    {
        enum TokenType {open_par,number,oper,close_par,error};
        TokenType type;
        int numval;
        char c;
    };

    Tokenizer(std::istream&);

    Token nextToken();
    bool moreTokens();

    private:
    std::istream &in;

    void clearWhiteSpace();

};

Tokenizer& operator>> (Tokenizer&,Tokenizer::Token&);

#endif