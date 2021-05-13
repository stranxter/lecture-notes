#pragma once

#include <string>
#include <iostream>

class Figure
{
    public:
    Figure(const std::string& _label);

    protected:
    std::string label;

    public:
    virtual double surface() = 0;
    virtual void saveToFile(std::ostream&) = 0;
    virtual void loadFromFile (std::istream&) = 0;

    virtual void draw() = 0;

    virtual Figure* clone() = 0;
    
    virtual ~Figure();


};