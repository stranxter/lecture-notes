#include "evalutils.h"
#include <functional>
#include <string>

std::function<int(int,int)> to_function(char op)
{
    switch(op)
    {
        case '+': return [](int x, int y)->int {return x+y;};
        case '-': return [](int x, int y)->int {return x-y;};
        case '*': return [](int x, int y)->int {return x*y;};
        case '/': return [](int x, int y)->int {return x/y;};
        default: throw std::string("Uknown operator:") + op;
    }
}

int priority(char op)
{
    switch(op)
    {
        case '+': return 10;
        case '-': return 10;
        case '*': return 100;
        case '/': return 100;
        case '(': return -1;
        default: throw std::string("Uknown operator:") + op;
    }
}


int apply(char op, int x, int y)
{
    return to_function(op)(x,y);
}