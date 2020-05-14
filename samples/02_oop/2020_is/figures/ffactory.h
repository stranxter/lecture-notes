#pragma once

#include "figure.h"
#include <string>
#include <stdexcept>

class FigureFactory
{
    public:
    static Figure* make(std::string type);

};

class UnknownFigureException : public std::exception
{
    public:

    UnknownFigureException(const std::string&);

    const char* what() const noexcept;

    private:
        std::string message;

};

