#include "figure.h"
#include "circle.h"
#include "square.h"
#include "group.h"
#include "ffactory.h"

Figure* FigureFactory::make(std::string type)
{
    Figure *newFigure = nullptr;
    if (type == "circ")
        newFigure = new Circle(0,0,0);
    else if (type == "sq")
        newFigure = new Square (0);
    else if (type == "group")
        newFigure = new Group;
    else
        assert(false);

    return newFigure;
}
