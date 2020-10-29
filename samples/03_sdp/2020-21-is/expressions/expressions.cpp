#include "expressions.h"
#include <cassert>

int apply (char op, int left, int right)
{
    switch (op)
    {
        case '+': return left + right;
        case '-': return left - right; 
        case '*': return left * right; 
        case '/': return left / right; 
        default: assert (false); return -1;
    }
}
int priority (char c)
{
    switch (c)
    {
        case '+': return 5;
        case '-': return 5;
        case '*': return 15;
        case '/': return 15;
        default: assert (false); return -1;
    }
}

bool isOperator (char c)
{
    return c == '*' ||
           c == '-' ||
           c == '+' ||
           c == '/';
}
