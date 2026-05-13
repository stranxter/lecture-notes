#include "figures.hpp"
#include "group.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "halfplane.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &out, const Point &p) {
    return out << p.x << " " << p.y;
}

std::istream &operator>>(std::istream &in, Point &p) {
    return in >> p.x >> p.y;
}

double sumArea(Figure *figs[], unsigned size) {
    double result = 0;
    for (unsigned int i = 0; i < size; ++i) {
        result += figs[i]->area();
    }
    return result;
}

Figure *figureFactory(const std::string &figure) {
    if (figure == "[Cir]") {
        return new Circle({0, 0}, 0, "dummy");
    } else if (figure == "[Sq]") {
        return new Square({0, 0}, 0, "dummy");
    } else if (figure == "[Tri]") {
        return new Triangle({0, 0}, {0, 0}, {0, 0});
    } else if (figure == "[HPl]") {
        return new HalfPlane(0, 0, 0);
    } else if (figure == "[Grp]") {
        return new Group;
    } else {
        std::cerr << "Unrecognized figure type: " << figure << std::endl;
        throw "Unrecognized figure type.";
    }
    return nullptr;
}
