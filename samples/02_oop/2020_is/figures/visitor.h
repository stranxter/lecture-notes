#pragma once

#include "figure.h"
#include "rect.h"
#include "circle.h"
#include "group.h"

class Visitor
{
    public:
        virtual void processCircle(Circle*)=0;
        virtual void processRectangle(Rectangle*)=0;
        virtual void processGroup(Group*)=0;
};