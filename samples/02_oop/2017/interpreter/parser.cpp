#include <cassert>

#include "parser.h"
#include "tokenizer.h"

#include "expression.h"
#include "constexpr.h"
#include "binexpr.h"
#include "ifexpr.h"


Expression* Parser::parse (std::istream &input)
{
  Tokenizer tokenizer (input);

  return parseExpression (tokenizer);
}

Expression* Parser::parseExpression (Tokenizer &tokenizer)
{
  Token t = tokenizer.peek();

  switch (t.type)
  {
    case Token::TokenOpenPar: return Parser::parseBinExpr(tokenizer);
    case Token::TokenIf: return Parser::parseIfExpr(tokenizer);
    case Token::TokenDoubleConstant: return Parser::parseConst(tokenizer);
  }

  assert (false);
  return nullptr;

}

Expression* Parser::parseBinExpr (Tokenizer &tokenizer)
{
  /*grammar:
  <ArithExpression> ::= (<Expr> <op> <Expr>)
  */

  //прехамваме отваряшата скоба
  tokenizer.getExpectedNext(Token::TokenOpenPar);

  Expression *left = Parser::parseExpression (tokenizer);

  //очакваме оператор
  Token t = tokenizer.getExpectedNext(Token::TokenArithOperator);

  Expression *right = Parser::parseExpression (tokenizer);

  //прехамваме затваряща скоба
  tokenizer.getExpectedNext(Token::TokenClosePar);

  return new BinExpr (left, t.text[0], right);


}

Expression* Parser::parseIfExpr (Tokenizer &tokenizer)
{
  /*
  grammar:
  <IfExpr> ::= if <Expr>
                  then <Expr>
                  else <Expr>

  */

  tokenizer.getExpectedNext (Token::TokenIf);

  Expression *condExpr = Parser::parseExpression (tokenizer);

  tokenizer.getExpectedNext (Token::TokenThen);

  Expression *thenExpr = Parser::parseExpression (tokenizer);

  tokenizer.getExpectedNext (Token::TokenElse);

  Expression *elseExpr = Parser::parseExpression (tokenizer);

  return new IfExpr (condExpr,thenExpr,elseExpr);


}

Expression* Parser::parseConst (Tokenizer &tokenizer)
{
  Token t = tokenizer.getExpectedNext(Token::TokenDoubleConstant);

  return new ConstExpr (t.doubleValue);
}
