#pragma once

class FigureFactory
{
    public:

    static Figure* make(std::string type);
};
