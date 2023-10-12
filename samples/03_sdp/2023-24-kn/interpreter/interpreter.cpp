#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "tokenizer.h"

#include <iostream>
#include <fstream>
#include <sstream>

TEST_CASE("Test Tokenization")
{
    //(1+2)*3
    
    std::vector<std::string> strings = {"(1+2)*3",
                                            "(999+0)-74",
                                            "   (   \t  \n 1 + \n 7) * \t     19     "};

    std::vector<Tokenizer::Tokens> expected = {Tokenizer::OPEN_PAR, 
                                                Tokenizer::NUMBER,
                                                Tokenizer::OPERATOR,
                                                Tokenizer::NUMBER,
                                                Tokenizer::CLOSE_PAR,
                                                Tokenizer::OPERATOR,
                                                Tokenizer::NUMBER};


    Tokenizer::Token token;

    for (std::string s : strings)
    {
        std::stringstream expression(s);
        int count = 0;
        while (count < expected.size())
        {
            expression >> token;
            CHECK(token.type == expected[count]);
            ++count;
        }
    }    

}

int main()
{
    doctest::Context().run();
}