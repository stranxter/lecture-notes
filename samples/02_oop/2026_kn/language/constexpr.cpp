#include "constexpr.hpp"

Constexpr::Constexpr(double value) : _value(value) {}
double Constexpr::value(std::vector<double> &memory) const { return _value; }

Expression *Constexpr::copy() const
{
    return new Constexpr(_value);
}