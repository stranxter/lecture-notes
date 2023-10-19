#include "rpneval.h"
#include "tokenizer.h"
#include "evalutils.h"
#include <string>
#include <sstream>

#include<cassert>
#include<stack>

int RPNeval(std::istream &in)
{
    Tokenizer::Token t;
    in >> t;

    std::stack<int> s;

    while (t.type != Tokenizer::EOE)
    {
        assert(t.type == Tokenizer::NUMBER || t.type == Tokenizer::OPERATOR);
        if(t.type == Tokenizer::NUMBER)
        {
            s.push(t.value);
        } else { //t.type == Tokenizer::OPERATOR
            assert(s.size() > 1);
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(fn(t.symbol)(left,right));
        }
        in >> t;
    }
    assert(s.size() == 1);
    return s.top();
}

std::string infixToRPN(std::istream &in)
{
    Tokenizer::Token t;
    in >> t;

    std::vector<Tokenizer::Token> output;
    std::stack<Tokenizer::Token> shuntingYard;

    while (t.type != Tokenizer::EOE)
    {
        if(t.type == Tokenizer::NUMBER)
        {
            output.push_back(t);
        } else if (t.type == Tokenizer::OPEN_PAR)
        {
            shuntingYard.push(t);
        } else if (t.type == Tokenizer::CLOSE_PAR)
        {
            assert(shuntingYard.size() > 0);
            while(shuntingYard.top().type != Tokenizer::OPEN_PAR)
            {
                assert(shuntingYard.size() > 0);
                output.push_back(shuntingYard.top()); shuntingYard.pop();
            }
            shuntingYard.pop();//премахване на оставащата отваряща скоба

        } else if (t.type == Tokenizer::OPERATOR)
        {
                while(shuntingYard.size() > 0 &&
                        shuntingYard.top().type != Tokenizer::OPEN_PAR &&
                        priority(shuntingYard.top().symbol) >= priority(t.symbol))
                {
                    Tokenizer::Token waiting;
                    output.push_back(shuntingYard.top());shuntingYard.pop();
                }
                shuntingYard.push(t);
        }

        in >> t;
    }

    while(shuntingYard.size() > 0)
    {
        output.push_back(shuntingYard.top());shuntingYard.pop();        
    }

    std::stringstream rpn;

    for(Tokenizer::Token t : output)
    {
        rpn << t << " ";
    }

    return rpn.str() + "$";
    
}