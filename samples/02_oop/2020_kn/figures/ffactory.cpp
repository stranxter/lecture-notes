#include "figure.h"
#include "circle.h"
#include "rect.h"
#include "group.h"
#include "ffactory.h"

Figure* FigureFactory::make(std::string type)
{
    Figure *newFigure = nullptr;
    if (type == "circ")
        newFigure = new Circle(0,0,0);
    else if (type == "rect")
        newFigure = new Rect(0,0,0,0);
    else if (type == "group")
        newFigure = new Group(0,0);
    else
        throw UnknownFigureExcpection(type);

    return newFigure;
}

UnknownFigureExcpection::UnknownFigureExcpection(const std::string &type):std::exception()
{
    message = "Unknown figure type:";
    message += type;
}

const char* UnknownFigureExcpection::what() const noexcept
{
    return message.c_str();
}
