#include "block.hpp"

Block::Block() {}

void Block::add(Expression* expr)
{
    expressions.push_back(expr->copy());
}

double Block::value(std::vector<double> &memory) const
{
    double result = 0;
    for(const auto& expr : expressions)
    {
        result = expr->value(memory);
    }
    return result;
}

Expression *Block::copy() const
{
    Block *block = new Block();
    for(const auto& expr : expressions)
    {
        block->add(expr->copy());
    }
    return block;
}

Block::~Block()
{
    for(auto& expr : expressions)
    {
        delete expr;
    }
}