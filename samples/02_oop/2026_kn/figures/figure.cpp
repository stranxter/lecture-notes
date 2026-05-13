#include "figure.hpp"
#include <iostream>

Figure::Figure() : center{0, 0} {
    std::cout << "Figure::Figure()\n";
    label = "No label";
}

Figure::Figure(const Point &_center, const char *_label) : label(_label), center(_center) {
    std::cout << "Figure::Figure(const Point &, const char *)\n";
}

Figure::Figure(const char *_label) : label(_label), center{0, 0} {
    std::cout << "Figure::Figure(const char*)\n";
}
