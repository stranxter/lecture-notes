#include "tokenizer.h"

#include <fstream>
#include <iostream>

int main ()
{
    std::ifstream program ("example.knpp");

    Tokenizer t (program);

    while (t.moreTokens ())
    {
        Token token = t.nextToken();
        std::cout << token.type << ":" << token.str << std::endl;
    }
}