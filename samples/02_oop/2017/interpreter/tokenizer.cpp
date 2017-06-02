#include <cassert> 
#include <iostream>
#include <sstream>
#include "tokenizer.h"

Token::Token (int _type, std::string _text, double _doubleValue)
    :type(_type),text(_text), doubleValue(_doubleValue)
{
}


int Token::getType ()
{
  return type;
}


std::string Token::getText ()
{
  return text;
}

Token::operator int ()
{
  return getType();
}


Tokenizer::Tokenizer (std::istream &_input):input(_input),havePeeked(false),peekedToken(Token::TokenUnknown,"")
{
}

Tokenizer::operator bool () const
{
  return !input.fail();
}

bool Tokenizer::IsDoubleConst (const std::string &w, double &parsedVal)
{
  std::stringstream wstream (w);

  wstream >> parsedVal;

  return wstream == true;
}

void Tokenizer::removeWhiteSpaces ()
{
  char c = input.peek();

  while (input && (c == ' ' || c == '\n' || c == '\t'))
  {
    input.get();
    c = input.peek();
  }
}

Token Tokenizer::getNext()
//"if", "then", "else"
{
  if (havePeeked)
  {
    havePeeked = false;
    return peekedToken;
  }

  //изтриваме всички нови редове, интервали и табуулации
  removeWhiteSpaces();

  //1. Опит за разпознаване на едносимволни лексеми

  char peeked = input.peek();

  switch (peeked)
  {
    case '(': input.get(); return Token (Token::TokenOpenPar,std::string(1,peeked));
    case ')': input.get(); return Token (Token::TokenClosePar,std::string(1,peeked));
    case '+':
    case '-':
    case '*': input.get(); return Token (Token::TokenArithOperator,std::string(1,peeked));
  }

  //2. Опит за разпознаване на многосимволни думи


  std::string w;
  double doubleConst;
  input >> w;

  std::cerr << "DEBUG: String read:" << w << std::endl;

  if (w == "if")
    return Token (Token::TokenIf,w);
  if (w == "then")
    return Token (Token::TokenThen,w);
  if (w == "else")
    return Token (Token::TokenElse,w);
  if (Tokenizer::IsDoubleConst (w,doubleConst))
    return Token (Token::TokenDoubleConstant,w,doubleConst);

  return Token (Token::TokenUnknown,w);
}

Token Tokenizer::getExpectedNext (int tokenType)
{
  Token t = getNext ();
  assert (t.type == tokenType);
  return t;
}

Token Tokenizer::peek ()
{
  if (!havePeeked)
  {
    peekedToken = getNext();
    havePeeked = true;
  }

  return peekedToken;
}
