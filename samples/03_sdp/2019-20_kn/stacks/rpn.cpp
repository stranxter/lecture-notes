#include <iostream>
#include <stack>
#include <cassert>
#include <vector>
#include <sstream>

bool isdigit (char c)
{
    return c >= '0' && c <= '9';
}

int apply (char op, int x, int y)
{
    switch (op)
    {
        case '+': return x+y;
        case '*': return x*y;
        default: assert (false);
    }
    return 0;
}

void killwhite (std::istream &in)
{
    while (in.peek () == ' ' || in.peek() == '\n')
    {
        in.get();
    }
}

int calcrpp (std::istream &in)
{
    killwhite (in);
    std::stack <int> s;
    while (in.peek() != ';')
    {
        
        if (isdigit (in.peek()))
        {
            int arg;
            in >> arg;
            s.push (arg);
        } else {
            char op = in.get();
            assert (s.size() >= 2);
            int larg = s.top(); s.pop();
            int rarg = s.top(); s.pop();

            s.push (apply(op,larg,rarg));
        }
        killwhite (in);
    }
    assert (s.size() == 1);
    return s.top();
}


struct Token
{
    int type;
    static const int NUM = 0;
    static const int OPER = 1;
    static const int LPAR = 2;
    static const int RPAR = 3;
    int val;
    char op;
};

int priority (char op)
{
    switch (op)
    {
        case '*': return 10;
        case '+': return 5;
        default: assert (false);
    }
    return 0;
}

std::vector<Token> makerpn (std::istream &in)
{
    std::vector<Token> result;
    std::stack<Token> s;
    
    killwhite (in);
    while (in.peek() != ';')
    {
        Token next;
        if (isdigit (in.peek()))
        {
            next.type = Token::NUM;
            in >> next.val;
            result.push_back (next);
        } else if (in.peek() == '(')
        {
            next.type = Token::LPAR;
            s.push (next);
            in.get();
        } else if (in.peek() == ')')
        {
            in.get();
            while (s.size() >= 1 && 
                   s.top().type != Token::LPAR)
            {
                next = s.top(); s.pop();
                result.push_back (next);
                assert (next.type == Token::OPER);
            }
            assert (s.size () >= 1);
            s.pop();
        } else {
            next.type = Token::OPER;
            next.op = in.get();
            while (s.size()>=1 && 
                   s.top().type == Token::OPER &&
                   priority(s.top().op) > priority (next.op))
                   {
                       result.push_back(s.top());
                       s.pop();
                   }
            s.push (next);
        }
        killwhite (in);
    }
    while (s.size () > 0)
    {
        result.push_back (s.top()); s.pop();
    }
    return result;
}

std::stringstream tostream (std::vector<Token> rpn)
{
    std::stringstream res;
    for (Token t : rpn)
    {
        switch (t.type)
        {
            case Token::NUM: res << t.val; break;
            case Token::OPER: res << t.op; break;
            default: assert (false);
        }
        res << " ";
    }
    return res;
}

int calcexprrec (std::istream &in)
{
    killwhite (in);

    if (isdigit (in.peek()))
    {
        int x;
        in >> x;
        return x;
    }
    assert (in.peek() == '(');
    in.get();

    int larg = calcexprrec (in);
    killwhite (in);

    char op = in.get();

    int rarg = calcexprrec (in);

    killwhite (in);
    assert (in.get() == ')');

    return apply (op,larg,rarg);

}

Token readToken (std::istream &in)
{
    killwhite (in);
    Token t;
    if (isdigit (in.peek()))
    {
        t.type = Token::NUM;
        in >> t.val;
        return t;
    } else if (in.peek() == '(')
    {
        t.type = Token::LPAR;
        in.get();
        return t;
    } else if (in.peek() == ')')
    {
        t.type = Token::RPAR;
        in.get();
        return t;
    } else 
    {
        t.type = Token::OPER;
        t.op = in.get();
        return t;
    }
}

int calcexprit (std::istream &in)
{
    std::stack <Token> s;
    Token next = readToken (in);

    s.push (next);

    while (s.size () > 1 || s.top().type != Token::NUM)
    {
        next = readToken (in);
        if (next.type == Token::RPAR)
        {
            assert (s.top().type == Token::NUM);
            int rarg = s.top().val; s.pop();
            assert (s.top().type == Token::OPER);
            char op = s.top().op; s.pop();
            assert (s.top().type == Token::NUM);
            int larg = s.top().val; s.pop();
            assert (s.top().type == Token::LPAR);
            s.pop();
            next.type = Token::NUM;
            next.val = apply (op,larg,rarg);
            s.push (next);
        } else {
            s.push (next);
        }
    }

//    std::cerr << "Top of stack = " << s.top().type << std::endl;
    assert (s.top().type == Token::NUM);
    return s.top().val;

}

int main ()
{
   //std::cout << calcrpp (std::cin);

   //std::vector<Token> rpn = makerpn (std::cin);
   //std::stringstream srpn = tostream (rpn);

   //std::cout << srpn.str();

   //std::cout << calcexprrec (std::cin);

   std::cout << calcexprit (std::cin);

}