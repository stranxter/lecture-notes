#pragma once

#include <functional>


std::function<double(double,double)> oper(char _oper);
bool isOperator(char c);