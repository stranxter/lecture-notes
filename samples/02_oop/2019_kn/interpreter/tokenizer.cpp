#include "tokenizer.h"

KnownToken Tokenizer::knownTokens[] = {"set", Token::kwset,
                                        "+", Token::ao_plus,
                                        "*", Token::ao_mult,
                                        "(", Token::par_open,
                                        ")", Token::par_close};

Tokenizer::Tokenizer(std::istream &_input):input(_input),tokenWasPeeked(false)
{}

Token Tokenizer::peekToken()
{
    if (!tokenWasPeeked)
    {
        peekedToken = readToken();
        tokenWasPeeked = true;
    }

    return peekedToken;
}

Token Tokenizer::readToken()
{
    Token t;

    clearWhiteSpaces();

    while (!isWhiteSpace(input.peek()))
    {
        t.str += input.get();
    }

    size_t i = 0;
    for (i = 0; i < knownTokenN && knownTokens[i].word != t.str; i++)
        ;

    if (i < knownTokenN)
    {
        t.type = knownTokens[i].type;
    }
    else if (isletter(t.str[0]))
    {
        t.type = Token::var_name;
    }
    else
    {
        t.type = Token::unknown;
    }

    return t;
}

Token Tokenizer::nextToken()
{
  if (tokenWasPeeked)
  {
      tokenWasPeeked = false;
      return peekedToken;

  } else {
      return readToken ();
  }
}

bool Tokenizer::isWhiteSpace(char c)
{
    return c <= 32;
           
}

void Tokenizer::clearWhiteSpaces()
{
    while ((bool)input && isWhiteSpace(input.peek()))
    {
        input.get();
    }
}

bool Tokenizer::moreTokens()
{
    if (tokenWasPeeked)
    {
        return true;
    }
    clearWhiteSpaces ();
    
    
    return (bool)input;
}

bool Tokenizer::isletter(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z');
}