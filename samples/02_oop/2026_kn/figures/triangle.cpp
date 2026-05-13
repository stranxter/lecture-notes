#include "triangle.hpp"
#include <cmath>
#include <iostream>

namespace {
    double square(double x) { return x * x; }
}

Triangle::Triangle(const Point &_A, const Point &_B, const Point &_C)
    : A(_A), B(_B), C(_C), a(_B, _C), b(_C, _A), c(_A, _B) {}

double Triangle::area() const {
    double a = std::sqrt(square(B.x - C.x) + square(B.y - C.y));
    double b = std::sqrt(square(C.x - A.x) + square(C.y - A.y));
    double c = std::sqrt(square(A.x - B.x) + square(A.y - B.y));
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter() const {
    double a = std::sqrt(square(B.x - C.x) + square(B.y - C.y));
    double b = std::sqrt(square(C.x - A.x) + square(C.y - A.y));
    double c = std::sqrt(square(A.x - B.x) + square(A.y - B.y));
    return a + b + c;
}

Figure *Triangle::copy() const {
    return new Triangle(*this);
}

void Triangle::serialize(std::ostream &out) const {
    out << "[Tri] "
        << label << "\n"
        << A << " " << B << " " << C;
}

void Triangle::deserialize(std::istream &in) {
    std::getline(in, label);
    in >> A >> B >> C;
}

bool Triangle::containsCentered(const Point &p) const {
    return a.containsCentered(p) && b.containsCentered(p) && c.containsCentered(p);
}
