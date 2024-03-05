#pragma once
#include <functional>

int applyOperator(char op, int left, int right);
std::function<int(int,int)> fn(char c);
int priority(char op);