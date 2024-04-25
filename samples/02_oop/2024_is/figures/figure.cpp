#include "figure.h"

#include "circle.h"
#include "triangle.h"
#include "square.h"

double Figure::scale = 1;

Figure* Figure::figureFactory(const std::string &type)
{
    if(type == "Circle")
    {
        return new Circle({0,0},0);
    }
    else if(type == "Triangle")
    {
        return new Triangle({0,0},{0,0},{0,0});
    }
    else if(type == "Square")
    {
        return new Square({0,0},{0,0});
    }
    else
    {
        throw "Unknown figure type";
        return nullptr;
    }
}


