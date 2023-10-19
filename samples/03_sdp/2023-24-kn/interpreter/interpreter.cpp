#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "tokenizer.h"
#include "receval.h"
#include "rpneval.h"

#include <iostream>
#include <fstream>
#include <sstream>

TEST_CASE("Test Tokenization")
{
    //(1+2)*3
    
    std::vector<std::string> strings = {"(1+2)*3 $",
                                            "(999+0)-74 $",
                                            "   (   \t  \n 1 + \n 7) * \t     19     $"};

    std::vector<Tokenizer::Tokens> expected = {Tokenizer::OPEN_PAR, 
                                                Tokenizer::NUMBER,
                                                Tokenizer::OPERATOR,
                                                Tokenizer::NUMBER,
                                                Tokenizer::CLOSE_PAR,
                                                Tokenizer::OPERATOR,
                                                Tokenizer::NUMBER,
                                                Tokenizer::EOE};


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

TEST_CASE("Test Recursive Evaluation")
{
    std::vector<std::pair<std::string,int>> expressions = {{"((1+2)*3)",9},
                                                           {"99",99},
                                                           {"(3*(1+2))",9},
                                                           {"(((1+1)*(2+3))+8)",18}};    
    for(std::pair<std::string,int> p : expressions)
    {
        std::stringstream e (p.first);
        CHECK(receval(e) == p.second);
    }
}

TEST_CASE("Test RPN Evaluation")
{
    std::vector<std::pair<std::string,int>> expressions = {{"8 1 + $",9},
                                                           {"101 1 - 1 - $",99},
                                                           {"1 2 + 3 4 + * $",21},
                                                           {"1 1 + 2 3 + * 8 + $",18}};    

                                                           
    for(std::pair<std::string,int> p : expressions)
    {
        std::stringstream e (p.first);
        CHECK(RPNeval(e) == p.second);
    }
}
TEST_CASE("Test Infix to RPN")
{
    std::vector<std::pair<std::string,std::string>> expressions = 
                                                          {{"8+1$","8 1 + $"},
                                                           {"101-1-1$","101 1 - 1 - $"},
                                                           {"(1+2)*(3+4)$","1 2 + 3 4 + * $"},
                                                           {"(1+1)*(2+3)+8$","1 1 + 2 3 + * 8 + $"}};    

    for(std::pair<std::string,std::string> p : expressions)
    {
        std::stringstream e (p.first);
        CHECK(infixToRPN(e) == p.second);
    }

}

int main()
{

    std::string e;
    std::cout << ">";
    std::getline(std::cin,e);

    while (e != "exit")
    {
        std::stringstream es (e);
//        std::cout << "value=" << receval(es) << std::endl;
//        std::cout << "value=" << RPNeval(es) << std::endl;
       std::cout << "RPN=" << infixToRPN(es) << std::endl;
        
        std::cout << ">";
        std::getline(std::cin,e);
    }

    std::cout << "Bye!";

    doctest::Context().run();
}