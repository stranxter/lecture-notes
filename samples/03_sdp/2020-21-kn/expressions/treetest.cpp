#include "exprtree.h"

#include <fstream>

int main()
{
    Tokenizer tokenizer (std::cin);

    Expression *tree = parseExpression(tokenizer);

    std::ofstream dot ("tree.dot");

    dot << "digraph G{\n";
    tree->exportDot(dot);
    dot << "}";

    std::cout << "Expression result = " << tree->evaluate() << std::endl;

    delete tree;

}