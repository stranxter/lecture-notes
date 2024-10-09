#pragma once

#include "expression.h"
#include "tokenizer.h"
#include <iostream>

Expression* parseExpression(std::istream &in);
