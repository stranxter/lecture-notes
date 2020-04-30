#pragma once

#include "figure.h"
#include <string>

class FigureFactory
{
    public:
    static Figure* make(std::string type);

};
