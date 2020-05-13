#pragma once
#include <exception>

class UnknownFigureExcpection : public std::exception
{   
    public:
    UnknownFigureExcpection(const std::string&);
    const char* what() const noexcept;
    private:
    std::string message;
};

class FigureFactory
{
    public:

    static Figure* make(std::string type);
    

};
