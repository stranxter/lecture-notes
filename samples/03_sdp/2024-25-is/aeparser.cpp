#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

struct Token
{
    enum TokenType {open_par, number, oper, close_par};
    TokenType type;
    std::string val;
};

std::ostream& operator << (std::ostream &out, const Token &t)
{
    out << "Token(" << t.type << "," << t.val << ")";
    return out;
}

bool isOperator(char c)
{
    return c == '+' || 
           c == '-' || 
           c == '*' || 
           c == '/';
}

Token nextToken(std::istream &in)
{
    char c = in.peek();
    if (isdigit(c))
    {
        std::string num;
        while (isdigit(c))
        {
            num += c;
            in.get();
            c = in.peek();
        }
        return Token{Token::number, num};
    } else if (c == '(')
    {
        in.get();
        return Token{Token::open_par, "("};
    } else if (c == ')')
    {
        in.get();
        return Token{Token::close_par, ")"};
    } else if (isOperator(c))
    {
        in.get();
        return Token{Token::oper, std::string("") + c};
    } else
    {
        std::cerr << "char=" << c << "\n" << std::endl;
        throw std::runtime_error("Invalid character");
    }

}

std::vector<Token> tokenize(std::istream &in)
{
    std::vector<Token> tokens;
    while (in && in.peek() != '\n')
    {
        Token t = nextToken(in);
        if(in)
        {
            tokens.push_back(t);
        }
    }
    return tokens;
}


int main()
{
    std::ifstream in("expression.exis");
    
    std::vector<Token> tokens = tokenize(in);
    // do something with parsed

    for (Token t : tokens)
    {
        std::cout << t;
    }

    std::cout << std::endl;

    return 0;
}