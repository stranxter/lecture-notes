#include "expressions.h"
#include <cassert>

int apply (char oper, int left, int right)
{
    switch (oper)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default:
            assert(false);return -1;
    }
    
}

int priority (char oper)
{
    switch (oper)
    {
        case '+': return 5;
        case '-': return 5;
        case '*': return 15;
        case '/': return 15;
        default:
            assert(false);
    }    
    return -1;
}