#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>
#include <iostream>

struct Token
{
    enum TokenTypes {kwset, 
                     var_name, 
                     ao_plus, 
                     ao_mult, 
                     par_open, 
                     par_close,
                     unknown};

    std::string str;
    TokenTypes type;
};

struct KnownToken
{
    std::string word;
    Token::TokenTypes type;
};


class Tokenizer
{
    public:
    Tokenizer (std::istream&);

    Token peekToken ();
    Token nextToken ();

    bool moreTokens ();


private:
    std::istream &input;
    Token peekedToken;
    bool tokenWasPeeked; //has a token been peeked at all

    //extracts the next token from the input stream
    Token readToken ();


    void clearWhiteSpaces();
    bool isWhiteSpace (char c);
    bool isletter (char c);
    static const size_t knownTokenN = 5;
    static KnownToken knownTokens[knownTokenN];
};


#endif