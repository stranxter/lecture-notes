#ifndef _VISITOR__H
#define _VISITOR__H

#include "rectangle.h"
#include "circle.h"
#include "group.h"

class Visitor
{
public:
    virtual void visitReactangle (Rect*) = 0;
    virtual void visitCircle (Circle*) = 0;
    virtual void visitGroup (Group*) = 0;
};

#endif