#include <iostream>
#include "tokenizer.h"
#include <stack>
#include <cassert>
#include "expressions.h"
#include <string>
#include <vector>
#include <sstream>


int evalrpn (Tokenizer &tokenizer)
{

    std::stack<int> s;

    Tokenizer::Token token = tokenizer.getNextToken();

    while (token.type != Tokenizer::Token::error)
    {

        if (token.type == Tokenizer::Token::number)
        {
            s.push (token.val);
        } else {
            assert (token.type == Tokenizer::Token::oper);
            assert (s.size() >= 2);

            int first = s.top();s.pop();
            int second = s.top();s.pop();

            s.push(apply(token.symbol,first,second));
        }

        token = tokenizer.getNextToken();
    }

    assert (s.size()==1);
    return s.top();

}

std::string converttorpn (Tokenizer &tokenizer)
{
    
    std::stringstream result;
    
    std::stack<char> s;

    Tokenizer::Token token = tokenizer.getNextToken();

    while (token.type != Tokenizer::Token::error)
    {
        if (token.type == Tokenizer::Token::number)
        //NUMBER
        {
            result << token.val << " ";
        } else if (token.type == Tokenizer::Token::oper){
        //OPERATOR
            if (s.empty() || 
                (isOperator(s.top()) &&
                 priority(s.top()) <= priority (token.symbol)))
            {
                s.push (token.symbol);
            } else {
                while (!s.empty() && 
                       isOperator (s.top()) &&
                       priority (s.top()) >= priority(token.symbol))
                {
                    result << s.top() << " ";
                    s.pop();
                }
                s.push (token.symbol);
            }
        } else if (token.type == Tokenizer::Token::open_par)
        //OPEN PARETHESIS
        {
            s.push(token.symbol);
        } else if (token.type == Tokenizer::Token::close_par)
        //CLOSING PARETHESIS
        {
            while (!s.empty() && s.top() != '(')
            {
                result << s.top() << " ";
                s.pop();                
            }
            assert (!s.empty());
            s.pop();
        }

        token = tokenizer.getNextToken();
    }

    while (!s.empty())
    {
        result << s.top() << " ";
        s.pop();
    }

    return result.str();
}

int main ()
{
    Tokenizer stdintokenizer (std::cin);

    std::string rpnstring = converttorpn (stdintokenizer) + " @";

    std::stringstream rpnstream(rpnstring);

    Tokenizer rpntokenizer (rpnstream);

    std::cout << evalrpn (rpntokenizer) << std::endl;

}