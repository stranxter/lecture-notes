#pragma once

#include <string>
#include <vector>
#include <iostream>

class Tokenizer
{
    public:
    enum Tokens{OPEN_PAR, NUMBER, OPERATOR, CLOSE_PAR};

    Tokenizer(std::istream s);

    struct Token
    {
        Tokens type;
        char symbol;
        int value;
    };

};

std::istream& operator>>(std::istream&, Tokenizer::Token&);
