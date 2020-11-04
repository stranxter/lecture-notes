#include "tokenizer.h"
#include <stack>
#include <iostream>
#include "expressions.h"
#include <sstream>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


int evalrpn (Tokenizer &tokenizer)
{
    std::stack<int> s;

    Tokenizer::Token token = tokenizer.nextToken();
    
    while (token.type != Tokenizer::Token::error)
    {
        if (token.type == Tokenizer::Token::number)
        {
            s.push (token.numval);
        } else 
        {
            assert (token.type == Tokenizer::Token::oper);
            assert (s.size() >= 2);

            int right = s.top(); s.pop();
            int left = s.top(); s.pop();

            s.push (apply(token.c,left,right));
        }

        token = tokenizer.nextToken();

    }
    assert (s.size() == 1);
    return s.top();
}

std::string converttorpn (Tokenizer &tokenizer)
{
    std::stringstream result;

    Tokenizer::Token token = tokenizer.nextToken();

    std::stack<Tokenizer::Token> s; 

    while (token.type != Tokenizer::Token::error)
    {
        if (token.type == Tokenizer::Token::number)
        {
            result << token.numval << " ";
        } else if (token.type == Tokenizer::Token::open_par)
        {
            s.push (token);
        } else if (token.type == Tokenizer::Token::close_par)
        {
            while (!s.empty() && s.top().type != Tokenizer::Token::open_par)
            {
                result << s.top().c << " ";
                s.pop();
            }
            assert (!s.empty());
            s.pop();
        } else if (token.type == Tokenizer::Token::oper)
        {
            while (!s.empty() &&
                    s.top().type == Tokenizer::Token::oper &&
                    priority(s.top().c) >= priority(token.c))
                    {
                        result << s.top().c << " ";
                        s.pop();
                    }
            s.push(token);
        } else 
        {
            assert (false);
        }
         token = tokenizer.nextToken();
    }

    while (!s.empty())
    {
        result << s.top().c << " ";
        s.pop();
    }

    return result.str();
}




TEST_CASE("Test RPN Calculator")
{
    std::stringstream input ("42 @ "
                             "1 2 + @ "
                             "1 2 + 3 4 + *  @");

    Tokenizer tokenizer (input);

    CHECK (evalrpn(tokenizer) == 42);
    CHECK (evalrpn(tokenizer) == 3);
    CHECK (evalrpn(tokenizer) == 21);

}

TEST_CASE("Test Shunting Yard")
{
    std::stringstream input ("42 @"
                             "1 + 2 @"
                             "(1 + 2 * 3) - (4 + 6) @");

    Tokenizer tokenizer (input);

    std::stringstream rpns1 (converttorpn (tokenizer));
    std::stringstream rpns2 (converttorpn (tokenizer));
    std::stringstream rpns3 (converttorpn (tokenizer));

    Tokenizer t1 (rpns1);
    Tokenizer t2 (rpns2);
    Tokenizer t3 (rpns3);

    CHECK (evalrpn(t1) == 42);
    CHECK (evalrpn(t2) == 3);
    CHECK (evalrpn(t3) == -3);

}



int main()
{
    // пускане на тестовете
    doctest::Context().run();

}