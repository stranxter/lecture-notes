#pragma once

#include <vector>
#include "tokenizer.h"


//std::istream& -> Tokenizer -> RPN -> value

int evalRPN(TokenStream rpn);

std::string toRPN(TokenStream infix);