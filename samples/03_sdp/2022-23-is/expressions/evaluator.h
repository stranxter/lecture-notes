#pragma once

#include <iostream>

int evaluate(std::istream &in);
int evaluateRPN(std::istream &in);

std::string InfixToRPN(std::istream &in);