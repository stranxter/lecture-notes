#pragma once

#include "figure.h"

Figure* factory(const std::string &type);

std::istream& operator >> (std::istream &in, std::vector<Figure*>& figures);