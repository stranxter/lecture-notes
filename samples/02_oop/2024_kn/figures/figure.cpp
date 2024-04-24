#include "figure.h"

#include "circle.h"
#include "square.h"
#include "triangle.h"


double Figure::scale = 0;

std::ostream& operator<< (std::ostream &out, const Figure* f)
{
    f->saveToFile(out);
    return out;
}

Figure* Figure::figureFactory(std::string type)
{
    if(type == "Circle")
    {
        return new Circle({0,0},0);
    } else if(type == "Square")
    {
        return new Square({0,0},{0,0});
    } else if(type == "Triangle")
    {
        return new Triangle({0,0},{0,0},{0,0});
    } else
    {
        throw "Invalid figure type";
    }
}  
