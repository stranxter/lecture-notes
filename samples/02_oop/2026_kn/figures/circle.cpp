#include "circle.hpp"
#include <iostream>

Circle::Circle(const Point &center, double _r, const char *_label) : Figure(center, _label), r(_r) {
    std::cout << "Circle::Circle()\n";
}

double Circle::area() const {
    std::cout << "Circle::area()\n";
    return 3.14 * r * r;
}

double Circle::perimeter() const { return 2 * 3.14 * r; }

void Circle::serialize(std::ostream &out) const {
    out << "[Cir] "
        << label << "\n"
        << center << " "
        << r << " ";
}

void Circle::deserialize(std::istream &in) {
    std::getline(in, label);
    in >> center >> r;
}

bool Circle::containsCentered(const Point &p) const {
    double distSq = p.x * p.x + p.y * p.y;
    return distSq <= r * r;
}

Figure *Circle::copy() const {
    return new Circle(*this);
}
