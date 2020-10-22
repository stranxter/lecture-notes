#ifndef __TOKENIZER_H
#define __TOKENIZER_H


#include <iostream>
#include <string>


class Tokenizer
{
    public:

    struct Token
    {
        enum TokenType {open_par, number, oper, close_par, error};
        TokenType type;
        char symbol;
        int val;
    };

    Tokenizer (std::istream&);
    Token getNextToken();
    bool hasMoreTokens();

    static bool isWhiteSpace(char);

    private:
        std::istream& in;
        void clearWhiteSpace();
        
};



#endif