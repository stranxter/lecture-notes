#include "evalutils.h"
#include <cassert>

int priority(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 10;
        case '*':
        case '/':
            return 20;
        default:
            assert(false);
    }
    return -1;
}

int applyOperator(char op, int left, int right)
{
    switch(op)
    {
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return left / right;

        default: assert(false);
    }

    return -1;
}

std::function<int(int,int)> fn(char c)
{
    switch(c)
    {
        case '+' : return [](int x,int y)->int{return x+y;};
        case '-' : return [](int x,int y)->int{return x-y;};
        case '*' : return [](int x,int y)->int{return x*y;};
        case '/' : return [](int x,int y)->int{return x/y;};

        default: assert(false);
    }

    return [](int,int)->int{assert(false);return -1;};   
}
