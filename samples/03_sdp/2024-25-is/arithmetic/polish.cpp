#include "polish.h"
#include <stack>

#include "expression.h"
#include "evalutils.h"
#include <cassert>

int evalRPN(TokenStream rpn)
{
    std::stack<int> s;

    while (!rpn.eof() && 
           (rpn.peek().type != Token::oper || rpn.peek().val != "$"))
    {    
        Token t = rpn.get();

        if (t.type == Token::number)
        {
            s.push(std::stoi(t.val));
        } else if (t.type == Token::oper)
        {
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            int z = apply(t.val[0],x,y);
            s.push(z);
        } else 
        {
            throw std::string("Unsupported token in RPN evaluation:") + t.val;
        }
        
    }  

    assert(s.size() == 1);

    return s.top();
}


std::string toRPN(TokenStream infix)
{

    std::string result = "";
    std::stack<char> s;

    while (!infix.eof() && 
           (infix.peek().type != Token::oper || infix.peek().val != "$"))
    {
        Token t = infix.get();
        if(t.type == Token::number)
        {
            result += t.val;
        } else if (t.type == Token::open_par)
        {
            s.push('(');
        } else if (t.type == Token::close_par)
        {
                while(s.top() != '(')
                {
                    result += s.top();
                    s.pop();
                } 
                s.pop();         
        }
        else if (t.type == Token::oper)
        {
            if(s.size() > 0 && priority(t.val[0]) < priority(s.top()))
            {
                while(s.size() > 0 && s.top() != '(')
                {
                    result += s.top();
                    s.pop();
                }
            }
            s.push(t.val[0]);
        }
    }

    while(s.size() > 0)
    {
        result += s.top();
        s.pop();
    }

    return result;
}