#pragma once

#include <iostream>

struct Token
{
    enum TokenType {OPEN_PAR, 
                    NUMBER, 
                    OPERATOR, 
                    CLOSE_PAR};

    TokenType type;
    char symbol;
    int value;
};

std::istream& operator>>(std::istream &in, Token &t);

