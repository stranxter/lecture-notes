#include "varexpr.hpp"

VarExpr::VarExpr(char name) : varname(name) {}

double VarExpr::value(std::vector<double> &memory) const
{
    return memory[varname - 'a'];
}

Expression* VarExpr::copy() const
{
    return new VarExpr(varname);
}