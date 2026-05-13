#include "utils.hpp"

std::function<double(double, double)> oper(char _oper)
{
    switch (_oper) {
        case '+':
            return [](double x, double y) { return x + y; };
        case '-':
            return [](double x, double y) { return x - y; };
        case '*':
            return [](double x, double y) { return x * y; };
        case '/':
            return [](double x, double y) { return x / y; };
        case '>':
            return [](double x, double y) { return x > y; };
        default:
            throw "Invalid operator";
    }
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '=';
}