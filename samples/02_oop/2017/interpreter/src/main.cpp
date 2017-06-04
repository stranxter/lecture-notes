#include <string>
#include <fstream>
#include <iostream>

#include "parser/tokenizer.h"
#include "ast/expression.h"
#include "parser/parser.h"

void testTokenizer ()
{

  char s [] = "Hello\n"
              "world";

  std::ifstream input ("test.txt");
  Tokenizer tokenizer (input);

  Token t (Token::TokenUnknown,"");

  do {
    t = tokenizer.getNext();

    std::cerr << "DEBUG: TOKENIZER CYCLE\n";

    if (tokenizer)
    {
      std::cout << t.getType()
                << ":"
                << t.getText()
                << " ";
    }
  } while (tokenizer);
}

void testParser ()
{
  std::ifstream inputProgram ("myProgram.knsi");

  Expression *tree = Parser::parse (inputProgram);

  std::cout << "YOUR PROGRAM = " << tree->value();
}

int main ()
{
  testTokenizer();
  testParser();
}
