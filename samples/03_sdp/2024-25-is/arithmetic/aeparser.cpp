#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

#include "expression.h"
#include "parser.h"
#include "polish.h"

TEST_CASE("Test Tree Eval")
{
    //((11+20)∗123)
    Expression *myExpr = new ExprOperator('*',
                                          new ExprOperator('+',
                                                           new ExprConstant(11),
                                                           new ExprConstant(20)
                                                          ),
                                          new ExprConstant(123)                                          
                                         );

    CHECK(myExpr->value() == 3813);
}

TEST_CASE("Test Simple Parse")
{
    std::stringstream in("5");
    Expression *e = parseExpression(in);
    CHECK(e->value() == 5);

}

TEST_CASE("Test Complex Parse")
{
    std::stringstream in("((11+20)*123)");
    Expression *e = parseExpression(in);
    CHECK(e->value() == 3813);
}

TEST_CASE("Test Conditional Expression")
{
    std::stringstream in("(1 + if (8-((2+2)*3)) then 3 else (4-4))");
    
    Expression *e = parseExpression(in);
    CHECK(e->value() == 4);
}

int rpn(std::string s)
{
    std::stringstream in(s);
    TokenStream tokens(in);
    return (evalRPN(tokens));
}

TEST_CASE("Test RPN Evaluation")
{
    std::vector<std::pair<std::string,int>> tests = 
                                 {{"1 2 + $",3},
                                  {"1 2 3 + + $",6},
                                  {"2 3 4 + * $",14},
                                  {"1 2 + 3 4 + + $",10}};
    for(auto test:tests)
    {
        CHECK(rpn(test.first)==test.second);
    }
}

void toRPNhelper(std::string s)
{
    std::stringstream in(s);
    TokenStream tokens(in);
    std::cerr << toRPN (tokens) << std::endl;
}

TEST_CASE("Test Infix to RPN")
{
    std::vector<std::pair<std::string,int>> tests = 
                                 {{"1 + 2 $",3},
                                  {"1 + 2 + 3 $",6},
                                  {"2 + 3 * 4 $",14},
                                  {"1+2*3-4 $",0},
                                  {"(1+2)*3 $",0},
                                  {"3*(1+2) $",0},
                                  {"3+(1*2) $",0},
                                  {"3*(1+2*(1+3)+4) $",0}};
    for(auto test:tests)
    {
        toRPNhelper(test.first);
    }
}


int main()
{

    doctest::Context().run();

    return 0;
}