#include "tokenizer.h"
#include <stack>
#include <iostream>
#include <string>
#include <sstream>

int apply(char op, int left, int right)
{
    switch(op)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    throw("Unknown operator");
    return 0;
}

bool highPriority(char op)
{
    return op == '*' || op == '/';
}

bool parenthesis(char c)
{
    return c == '(' || c == ')';
}

int evaluate(std::istream &in)
{
    Token next;
    in >> next;

    if (next.type == Token::NUMBER)
    //<expression> ::= <number>
    {
        return next.value;
    }

    if (next.type == Token::OPEN_PAR)
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                   ^
    //                   |
    {
        int left = evaluate(in);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                 ^
    //                                 |
        Token op; in >> op; assert(op.type == Token::OPERATOR);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                           ^
    //                                           |
        int right = evaluate(in);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                                         ^
    //                                                         |
        in >> next; assert(next.type == Token::CLOSE_PAR);
        return apply(op.symbol,left,right);

    }
    throw "Syntax error.";
}

int evaluateRPN(std::istream &in)
{
    std::stack<int> s;

    Token t;
    in >> t;

    while (in)
    {
        if (t.type == Token::NUMBER)
        {
            s.push(t.value);
        } else 
        {
            assert(t.type == Token::OPERATOR);
            assert(s.size() >= 2);
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            s.push(apply(t.symbol,left,right));
        }
        in >> t;
    }
    assert(s.size()==1);
    return s.top();
}

std::string InfixToRPN(std::istream &in)
{
    std::stringstream output;
    std::stack<char> operatorStack;

    Token t;
    in >> t;
    while (in)
    {
        switch(t.type)
        {
            case Token::NUMBER:
                output << t.value << " ";
                break;
            case Token::OPERATOR:
                if (!highPriority(t.symbol))
                {
                    while (operatorStack.size() > 0 &&
                           !parenthesis(operatorStack.top())     
                    )/* &&
                        проверка за приоритет, ако се налага*/
                    {
                        output << operatorStack.top() << " ";
                        operatorStack.pop();
                    }                    
                    operatorStack.push(t.symbol);
                } 
                else 
                {
                    operatorStack.push(t.symbol);
                }
                break;
            case Token::OPEN_PAR:
                operatorStack.push(t.symbol);
                break;
            case Token::CLOSE_PAR:
                while (operatorStack.size() > 0 &&
                       !parenthesis(operatorStack.top()))
                {
                        output << operatorStack.top() << " ";
                        operatorStack.pop();
                }
                assert(operatorStack.size() > 0);
                operatorStack.pop();//вадим отварящата скоба
                break;
            default: assert(false);
                
        }
        in >> t;
    }

    while (operatorStack.size()>0)
    {
        output << operatorStack.top() << " ";
        operatorStack.pop();
    }


    return output.str();
}