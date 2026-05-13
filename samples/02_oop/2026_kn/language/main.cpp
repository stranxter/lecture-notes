#include "constexpr.hpp"
#include "binexpression.hpp"

#include <vector>
#include <iostream>

#include <fstream>
#include <vector>

#include "praser.hpp"

BinExpr createExpression()
{
    //5 + 8 * 9
    Constexpr c1(5);
    Constexpr c2(8);
    Constexpr c3(9);
    BinExpr b1(&c2, &c3, '*');
    BinExpr b2(&c1, &b1, '+');
    
    return BinExpr(&c1, &b1, '+');
}

int main()
{

    std::ifstream in("program.kn26");

    Expression *e = parse(in);
    
    std::vector<double> memory;
    memory.assign(26, 0); // 26 variables from a to z

    std::cout << e->value(memory) << std::endl;

    delete e;

    return 0;
}