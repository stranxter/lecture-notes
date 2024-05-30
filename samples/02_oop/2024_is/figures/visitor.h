#pragma once

#include "circle.h"
#include "triangle.h"
#include "group.h"
#include "square.h"

class Visitor
{
    public:
    virtual void visitCircle(Circle*) = 0;
    virtual void visitTriangle(Triangle*) = 0;
    virtual void visitSquare(Square*) = 0;
    virtual void visitGroup(Group*) = 0;
};