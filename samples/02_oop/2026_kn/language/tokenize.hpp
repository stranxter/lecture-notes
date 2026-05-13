#pragma once

#include <iostream>
#include "token.h"

std::istream& operator>>(std::istream& in, Token& token);

Token expect(Token::TokeType, std::istream&);

Token::TokeType peektokentype(std::istream& in);