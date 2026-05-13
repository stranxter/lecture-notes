#include "praser.hpp"
#include "expression.hpp"
#include "tokenize.hpp"

#include "constexpr.hpp"
#include "binexpression.hpp"
#include "varexpr.hpp"
#include "assignexpr.hpp"
#include  "block.hpp"

#include <cassert>

Expression *parse(std::istream &in)
{
    Token t;
    in >> t;
    if(t.type == Token::NUMBER)
    {
        return new Constexpr(t.data.number);
    } else 
    if (t.type == Token::OPEN_PAREN)
    {
        Expression *l = parse(in);

        Token opertoken = expect(Token::OPERATOR, in);

        Expression *r = parse(in);

        expect(Token::CLOSE_PAREN, in);

        BinExpr *tree = new BinExpr(l,r,opertoken.data.symbol);
        delete l;
        delete r;

        return tree;
    } else if (t.type == Token::VAR_NAME)
    {
        return new VarExpr(t.data.symbol);
    } else if (t.type == Token::SET)
    {
            Token var = expect(Token::VAR_NAME, in);
            expect(Token::OPERATOR, in); //=
            Expression *expr = parse(in);

            AssignExpr *assign_expr = new AssignExpr(var.data.symbol, expr);
            delete expr;
            return assign_expr;

    } else if (t.type == Token::OPEN_BLOCK)
    {
        Block *block = new Block();
        while (peektokentype(in) != Token::CLOSE_BLOCK)
        {
            Expression *expr = parse(in);    
            block->add(expr);
            delete expr;
        }
        expect(Token::CLOSE_BLOCK, in);
        return block;
    }
    std::cerr << "Unexpected token type: " << t.type << std::endl;
    throw "Syntax error";
}