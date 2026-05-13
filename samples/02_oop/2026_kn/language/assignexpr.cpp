#include "assignexpr.hpp"

AssignExpr::AssignExpr(char varname, Expression* expr) : varname(varname), expr(expr->copy()) {}

double AssignExpr::value(std::vector<double> &memory) const
{
    double val = expr->value(memory);
    memory[varname - 'a'] = val;
    return val;
}

Expression *AssignExpr::copy() const
{
    return new AssignExpr(varname, expr);
}

AssignExpr::~AssignExpr()
{
    delete expr;
}