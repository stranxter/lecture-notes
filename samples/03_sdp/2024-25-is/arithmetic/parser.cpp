#include "parser.h"
#include <cassert>

Expression* parseExpression(TokenStream &in);

Expression* parseExpression(std::istream &in)
{
    TokenStream stream(in);
    return parseExpression(stream);
}

Expression* parseExpConst(TokenStream &in)
{
        Token t = in.get();
        assert(t.type == Token::number);
        return new ExprConstant(std::stoi(t.val));        
}

Expression* parseExpOpeator(TokenStream &in)
{
    Token t = in.get();
    assert(t.type == Token::open_par);

    //(<expression> <op> <expression>)
    // ^
    // |
    Expression *left = parseExpression(in);

    //(<expression> <op> <expression>)
    //              ^
    //              |
    Token op = in.get();
    assert(op.type == Token::oper);

    //(<expression> <op> <expression>)
    //                   ^
    //                   |
    Expression *right = parseExpression(in);

    //(<expression> <op> <expression>)
    //                               ^
    //                               |
    assert(in.get().type == Token::close_par);

    return new ExprOperator(op.val[0],left,right);    
}


Expression* parseIf(TokenStream &in)
{
    //if <e> then <e> else <e>
    assert(in.get().type == Token::kwif);
    Expression *c = parseExpression(in);

    assert(in.get().type == Token::kwthen);
    Expression *t = parseExpression(in);

    assert(in.get().type == Token::kwelse);
    Expression *e = parseExpression(in);

    return new ExprIf(c,t,e);

}

Expression* parseExpression(TokenStream &in)
{

    switch(in.peek().type)
    {
        case Token::number: return parseExpConst(in);
        case Token::open_par: return parseExpOpeator(in);
        case Token::kwif: return parseIf(in);
        default: throw std::string("Unknown expresson type at:") + in.peek().val;
    }   
}
