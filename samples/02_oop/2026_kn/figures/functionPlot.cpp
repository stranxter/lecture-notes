#include "fplot.hpp"
#include <cfloat>
#include <cmath>

FunctionPlot::FunctionPlot(const Point &_center, std::function<double(double)> _f, double width, const char *_label)
    : Figure(_center, _label), f{_f}, width(width) {}

double FunctionPlot::area() const { return 0; }

double FunctionPlot::perimeter() const { return FLT_MAX; }

bool FunctionPlot::containsCentered(const Point &p) const { return std::abs(p.y - f(p.x)) < width; }

void FunctionPlot::serialize(std::ostream &out) const {
    throw "Unable to serialize function.";
}

void FunctionPlot::deserialize(std::istream &in) {
    throw "Unable to deserialize function.";
}

Figure *FunctionPlot::copy() const {
    return new FunctionPlot(*this);
}
