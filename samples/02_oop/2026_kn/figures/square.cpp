#include "square.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

Square::Square(const Point &pos, double size, const char *_label) : Figure(pos, _label), size(size) {
    std::cout << "Square::Square()\n";
}

void Square::serialize(std::ostream &out) const {
    out << "[Sq] "
        << label << "\n"
        << center << " "
        << size << " ";
}

void Square::deserialize(std::istream &in) {
    std::getline(in, label);
    in >> center >> size;
}

double Square::side() const { return size; }

double Square::area() const {
    std::cout << "Square::area()\n";
    return side() * side();
}

Figure *Square::copy() const {
    return new Square(*this);
}

double Square::perimeter() const { return 4 * side(); }

bool Square::containsCentered(const Point &p) const { return std::max(std::abs(p.x), std::abs(p.y)) < size / 2; }
