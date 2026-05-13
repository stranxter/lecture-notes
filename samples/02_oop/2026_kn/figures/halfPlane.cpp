#include "halfplane.hpp"
#include <cfloat>
#include <iostream>

HalfPlane::HalfPlane(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

HalfPlane::HalfPlane(const Point &A, const Point &B)
    : a(A.y - B.y),
      b(B.x - A.x),
      c(A.x * B.y - B.x * A.y) {}

void HalfPlane::serialize(std::ostream &out) const {
    out << "[Hpl] "
        << label << "\n"
        << a << " " << b << " " << c;
}

void HalfPlane::deserialize(std::istream &in) {
    std::getline(in, label);
    in >> a >> b >> c;
}

double HalfPlane::area() const { return FLT_MAX; }

double HalfPlane::perimeter() const { return FLT_MAX; }

bool HalfPlane::containsCentered(const Point &p) const { return p.x * a + p.y * b + c >= 0; }

Figure *HalfPlane::copy() const {
    return new HalfPlane(*this);
}
