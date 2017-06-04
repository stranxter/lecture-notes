#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>

class Token
{

public:
  static const int TokenUnknown  = -1;
  static const int TokenIf = 1;
  static const int TokenThen = 2;
  static const int TokenElse = 3;
  static const int TokenOpenPar = 4;
  static const int TokenClosePar = 5;
  static const int TokenDoubleConstant = 6;
  static const int TokenArithOperator = 7;

  int type;
  double doubleValue;
  std::string text;

  Token (int, std::string, double=0);
  int getType ();
  std::string getText ();
  operator int ();
};

class Tokenizer
{
private:
  std::istream &input;
  bool havePeeked;
  Token peekedToken;

  static bool IsDoubleConst (const std::string& w, double &parsedVal);

  void removeWhiteSpaces();



public:
  Tokenizer (std::istream&);
  operator bool () const;

  Token getNext();
  Token getExpectedNext (int);
  Token peek ();

};

#endif
