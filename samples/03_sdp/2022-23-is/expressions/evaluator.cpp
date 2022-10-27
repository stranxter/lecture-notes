#include "tokenizer.h"

int compute (char op, int left, int right)
{
    switch(op)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    throw("Unknown operator");
    return 0;
}

int evaluate(std::istream &in)
{
    Token next;
    in >> next;

    if (next.type == Token::NUMBER)
    //<expression> ::= <number>
    {
        return next.value;
    }

    if (next.type == Token::OPEN_PAR)
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                   ^
    //                   |
    {
        int left = evaluate(in);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                 ^
    //                                 |
        Token op; in >> op; assert(op.type == Token::OPERATOR);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                           ^
    //                                           |
        int right = evaluate(in);
    //<expression> ::= ( <expression 1><operator><expression 2>)
    //
    //                                                         ^
    //                                                         |
        in >> next; assert(next.type == Token::CLOSE_PAR);
        return compute(op.symbol,left,right);

    }
    throw "Syntax error.";
}
