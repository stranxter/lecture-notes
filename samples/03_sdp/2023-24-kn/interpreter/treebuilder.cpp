#include "treebuilder.h"
#include "tokenizer.h"

Expression* parseExpression(Tokenizer &tokens);

Expression *parseConst(Tokenizer &tokens)
{
    assert(tokens.peekToken().type == Tokenizer::NUMBER);
    return new ExprConst(tokens.getNextToken().value);    
}

Expression *parseParExpression(Tokenizer &tokens)
{
    //(<left subexpr> <ope> <right subex>)

    assert(tokens.getNextToken().type == Tokenizer::OPEN_PAR);

    //<left subexpr> <ope> <right subex>)
    Expression *left = parseExpression(tokens);

    //<ope> <right subex>)
    assert(tokens.peekToken().type == Tokenizer::OPERATOR);
    char op = tokens.getNextToken().symbol;

    //<right subex>)
    Expression *right = parseExpression(tokens);

    //)
    assert(tokens.getNextToken().type == Tokenizer::CLOSE_PAR);

    return new ExprArith(op,left,right);

}

Expression *parseIfExpression(Tokenizer &tokens)
{
    // if <expression> then <expression> else <expression>

    assert(tokens.getNextToken().type == Tokenizer::IF);

    Expression* cond = parseExpression(tokens);

    assert(tokens.getNextToken().type == Tokenizer::THEN);

    Expression* iftrue = parseExpression(tokens);

    assert(tokens.getNextToken().type == Tokenizer::ELSE);

    Expression* iffalse = parseExpression(tokens);

    return new ExprIf(cond,iftrue,iffalse);
}


Expression* parseExpression(Tokenizer &tokens)
{

    /*
    
    <expression> ::= <number> | 
                     (<expression> <operator> <exprerssion>) |
                     if <expression> then <expression> else <expression>
                     
    <number> ::= {0,..,9}+
    <operator> ::= + | - | * | /    
    
    */

    if(tokens.peekToken().type == Tokenizer::NUMBER)
    {
        return parseConst(tokens);
    }
    if(tokens.peekToken().type == Tokenizer::OPEN_PAR)
    {
        return parseParExpression(tokens);
    }
    if(tokens.peekToken().type == Tokenizer::IF)
    {
        return parseIfExpression(tokens);
    }

    throw "Syntax error. Unknown expression type";
    return nullptr;
}

Expression* parseExpression(std::istream &in)
{
    Tokenizer tokens(in);
    return parseExpression(tokens);
}
