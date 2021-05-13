#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "group.h"



Figure* figureFactory(std::string figureType)
{
    if (figureType == "circle")
    {
        return new Circle();

    } else if (figureType == "rect")
    {
        return new Rectangle();

    } else if (figureType == "group")
    {
        return new Group();
    } 
    else 
    {
        assert(false);
        return nullptr;
    }
}