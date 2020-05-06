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
        assert(false);

    return newFigure;
}
