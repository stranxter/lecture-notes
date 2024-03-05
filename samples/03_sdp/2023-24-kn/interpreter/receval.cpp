#include "receval.h"
#include "tokenizer.h"
#include "evalutils.h"
#include <cassert>
#include <functional>


int receval(std::istream &in)
{
    Tokenizer::Token t;
    in >> t;

    if(t.type == Tokenizer::NUMBER)
    {
        return t.value;
    }

    //in ::= <e1><op><e2>)
    assert(t.type == Tokenizer::OPEN_PAR);

    int left = receval(in);

    //in ::= <op><e2>)

    in >> t;
    assert(t.type == Tokenizer::OPERATOR);
    char op = t.symbol;

    //in ::= <e2>)

    int right = receval(in);

    //in ::= )

    in >> t;
    assert(t.type == Tokenizer::CLOSE_PAR);

    //return applyOperator(op,left,right);
    return fn(op)(left,right);

}