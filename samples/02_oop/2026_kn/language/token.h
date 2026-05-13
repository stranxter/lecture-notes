#pragma once

struct Token
{

    enum TokeType {OPEN_PAREN, CLOSE_PAREN, OPERATOR, NUMBER, VAR_NAME, SET, OPEN_BLOCK, CLOSE_BLOCK};

    TokeType type;
    
    union
    {
        char symbol;
        double number;
    } data;


};