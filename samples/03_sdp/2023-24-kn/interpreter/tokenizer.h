#pragma once

#include <string>
#include <vector>
#include <iostream>

class Tokenizer
{
    public:
    enum Tokens{OPEN_PAR, NUMBER, OPERATOR, CLOSE_PAR, EOE, IF, THEN, ELSE};

    struct Token
    {
        Tokens type;
        char symbol;
        int value;
        std::string keyword;
    };

    Tokenizer(std::istream&);

    Token getNextToken();
    Token peekToken();

    private:
    std::istream &in;
    Token *peeked;

};

std::istream& operator>>(std::istream&, Tokenizer::Token&);
std::ostream& operator<<(std::ostream&, const Tokenizer::Token&);
