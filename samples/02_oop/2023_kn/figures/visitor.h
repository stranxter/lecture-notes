#pragma once

#include "utils.h"

class Circle;
class Rect;
class Group;

class Visitor
{
    public:
    virtual void visitCircle(Circle *) = 0;
    virtual void visitRect(Rect *) = 0;
    virtual void visitGroup(Group *) = 0;
    
};