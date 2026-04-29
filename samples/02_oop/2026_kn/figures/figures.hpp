#pragma once

#include <functional>
#include <iostream>

#include "figure.hpp"

double sumArea(Figure *figs[], unsigned size);
void graphToPPM(const std::vector<Figure *> &cofigures, std::ostream &out);
