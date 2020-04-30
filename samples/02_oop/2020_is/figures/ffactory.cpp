#include "ffactory.h"

#include "circle.h"
#include "rect.h"
#include "group.h"

Figure* FigureFactory::make(std::string type)
{
    Figure *newFigure = nullptr;
    if (type == "circle:")
        newFigure = new Circle(0,0,0);
    else if (type == "rect:")
        newFigure = new Rectangle(0,0);
    else if (type == "group:")
        newFigure = new Group;
    else
        assert(false);

    return newFigure;
}

