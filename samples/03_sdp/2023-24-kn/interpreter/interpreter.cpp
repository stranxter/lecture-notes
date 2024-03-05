#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include "tokenizer.h"
#include "receval.h"
#include "rpneval.h"
#include "exprtree.h"
#include "treebuilder.h"

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

TEST_CASE("Test Tree Evaluation")
{
    std::vector<std::pair<std::string,int>> expressions = {{"((1+2)*3)",9},
                                                           {"99",99},
                                                           {"(3*(1+2))",9},
                                                           {"(((1+1)*(2+3))+8)",18},
                                                           {"(2 + if (1+2) then 3 else 4)",5}};    
    for(std::pair<std::string,int> p : expressions)
    {
        std::stringstream e (p.first);

        Expression* t = parseExpression(e);

        CHECK(t->eval() == p.second);
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

/*    std::string e;
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
*/

    std::stringstream s("(2 + if (1+2) then 3 else 4)");
    Expression *e = parseExpression(s);
    std::ofstream expr ("expr.dot");
    expr << "digraph G{\n";
    e->toDotty(expr);
    expr << "}";

    doctest::Context().run();
}